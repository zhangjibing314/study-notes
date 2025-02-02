---
title: mysql 管理
toc: true
---
[toc]

# 启动 or 关闭 MySQL服务器
1. 启动
```shell
sudo systemctl start mysql
```
2. 关闭
```shell
sudo systemctl stop mysql
```
3. 重启
```shell
sudo systemctl restart mysql
```
4. 查看状态
```shell
sudo systemctl status mysql
```

---
# 用户设置
## 显示所有用户(使用root权限登陆mysql):
```sql
select User from mysql.user;
```
## 查看当前用户
```sql
select current_user();
#或
select user();
```
## 创建or 删除用户
* 创建
    ```sql
    create user 'username'@'host' identified by 'password';
    ```
username：用户名。  
host：指定用户可以从哪些主机连接。例如，localhost 仅允许本地连接，% 允许从任何主机连接。  
password：用户的密码。  
    
* 删除
    ```sql
    DROP USER 'username'@'host';
    ```
* 修改用户名
```sql
rename user 'user_name'@'localhost' to 'user_name_1'@'localhost'
```
## 授权 or 撤销权限
```sql
GRANT privileges ON database_name.* TO 'username'@'host';
#刷新
FLUSH PRIVILEGES;
```
    privileges：所需的权限，如 ALL PRIVILEGES、SELECT、INSERT、UPDATE、DELETE 等。
    database_name.*：表示对某个数据库或表授予权限。database_name.* 表示对整个数据库的所有表授予权限，database_name.table_name 表示对指定的表授予权限。
    TO 'username'@'host'：指定授予权限的用户和主机。

* 撤销
```sql
REVOKE privileges ON database_name.* FROM 'username'@'host';
```

## 查看用户权限
```sql
SHOW GRANTS FOR 'username'@'host';
```
---
## MySQL配置文件
* /etc/my.cnf 文件是 MySQL 配置文件，用于配置 MySQL 服务器的各种参数和选项。
* 一般情况下，你不需要修改该配置文件.

