---
title: git
toc: true
---
[toc]

# git 基础
## 简介
## git 的三种状态
* 工作区

已经修改了仓库中的文件但尚未提交到数据库,即没有使用 `git add ` 命令

* 暂存区

将当前修改标记为进入下一个提交的快照 ,即使用了 `git add ` 命令

* 本地仓库

将修改的数据存储在了本地数据库中

## 处理工作区中的内容
* 清理未跟踪的文件 && 目录: `git clean -f -d`
* 清理工作区的修改: `git checkout .`
## 处理暂存区中的内容
* 1. 将暂存区的内容回退到工作区
```shell
git reset .
```
## 处理本地仓库中的内容

## 子模块——submodule
* 在主仓库库中添加子模块
```shell
git submodule add <子仓库的url> <在主仓库中的位置>
```

* 在主仓库库中移除子模块
```shell
# 取消注册
git submodule deinit <在主仓库中的位置>
# 移除
git rm <在主仓库中的位置>
```

* 在主仓库库中更新子模块
    * 方法1
    ```shell
    # 更新所有子模块
    cd <submodule-name>
    git pull
    cd -
    git submodule --merge
    # 将对子模块的更新(patch跟踪)在主仓库中提交
    git add .
    git commit -m "commit info"
    ```
    * 方法2
    ```shell
    # 更新所有子模块
    git submodule update --remote
    # 将对子模块的更新(patch跟踪)在主仓库中提交
    git add .
    git commit -m "commit info"
    ```
