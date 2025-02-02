---
title: docker
toc: true
---
[toc]

# 常用命令
```shell
# 拉去镜像
docker image pull <image_name:version_no>
```
# 查看镜像
```shell
docker images
```
# 使用镜像创建容器
```shell
docker create -it -v <host-dir-path>:</container_dir_path> --name my-container   <image_name>
# -it   :交互模式
# -v    :共享目录
```


# 启用容器
```shell
docker start <container_id> bash
```

# 进入容器
```shell
docker attach <container_id>
```

# 在x86-64中实现arm平台
1. docker配置
```shell
# 开启experimental 功能配置
# 查看
docker info | grep -i 'experimental'
# 配置
在`/etc/docker/`
在`/etc/docker/daemon.json`中添加 experimental = true"
```
2. 配置 qemu-user-static
```shell
注册可支持的架构解析器
docker run --rm --privileged multiarch/qemu-user-static:register --reset
```

