---
title: git tips
toc: true
---
# 补丁——patch
* 生成补丁的方式
    * 基于 **当前提交** 的数据库中的 patch 生成补丁:
    ```shell
    git format-patch HEAD^
    ```
    * 基于数据库中指定 patch **哈希或标签** 生成补丁:
    ```shell
    git format-patch <哈希或标签>
    ```
    * 基于 **工作区的修改** 生成补丁
    ```shell
    git diff > <patch_name.patch>
    ```
* 应用补丁
    * 将补丁打在 **工作区**:
    ```shell
    git apply  <补丁>
    ```
    * 将补丁打在 **本地仓库** 上：
    ```shell
    git am <补丁>
    ```
* 取消补丁——反向应用补丁
```shell
git apply -R <补丁>
```
