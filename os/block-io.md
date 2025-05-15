---
title: 块设备 IO 层
toc: true
date: 2025/2/16
---
[toc]

# 块设备 IO 层

块设备是指可以随机访问的设备。

块设备 IO 层的作用是管理块设备和块设备请求。

## 缓冲区
磁盘中的一个块被调用到内存中时，就需要有一块内存区域与之对应，这个内存区域就是缓冲区(buffer)。

## ~~缓冲区头部~~
只在内存中存储磁盘中的数据是不够的，还需要一些控制信息，所有就需要为每个缓冲区添加一个描述符，即缓冲区头部(buffer_head), 它用来描述磁盘块和内存缓冲区的映射关系。
```c
// linux kernel version: 6.0
// path: include/linux/buffer_head.h

struct buffer_head {
	unsigned long b_state;		/* buffer state bitmap (see above) */
	struct buffer_head *b_this_page;/* circular list of page's buffers */
	struct page *b_page;		/* the page this bh is mapped to */

	sector_t b_blocknr;		/* start block number */
	size_t b_size;			/* size of mapping */
	char *b_data;			/* pointer to data within the page */

	struct block_device *b_bdev;
	bh_end_io_t *b_end_io;		/* I/O completion */
 	void *b_private;		/* reserved for b_end_io */
	struct list_head b_assoc_buffers; /* associated with another mapping */
	struct address_space *b_assoc_map;	/* mapping this buffer is
						   associated with */
	atomic_t b_count;		/* users using this buffer_head */
	spinlock_t b_uptodate_lock;	/* Used by the first bh in a page, to
					 * serialise IO completion of other
					 * buffers in the page */
};
```
与缓冲区对应的内存物理页由 `b_page` 表示，`b_data` 指向在该页中相应的块

## bio
由于 bbuffer_head 的弊端，所以引入了 bio
```c
// linux kernel version: 6.0
// path: include/linux/blk_types.h

struct bio {
    ...
	struct bio_vec		*bi_io_vec;	/* the actual vec list */
    ...
};

```

## 请求队列
