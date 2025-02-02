---
title: 系统仿真
toc: true
---
[toc]

# qemu 命令行的一般形式
```shell
qemu-system-x86_64 [machine opts]   \
                [cpu opts]          \
                [accelerator opts]  \
                [device opts]       \
                [backend opts]      \
                [interface opts]    \
                [boot opts]
```
大多数选项都有帮助信息，例如：
```shell
qemu-system-x86_64 -M help
```
# 选项概览
![选项介绍](./pictures/options-overview.png)
