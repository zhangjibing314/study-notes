[toc]
---
# 指定tty作为被调试程序的stdin,stdo
```shell
# tty_path:被指定的tty的全路径
# debug-app:被调试的程序
# 用法
gdb --tty=<tty_path> <debug-app>
```
# 调试进程
## 开始调试进程

* 方案一：在启动gdb时就指定进程：
```shell
sudo gdb -p <pid>
```

* 方案二：启动gdb后再指定进程：
```shell
(gdb) attach <pid>
```
## 调试结束
```shell
# 和被调试的进程分离，使其继续运行
(gdb) detach
```

# 修改变量

```shell
set var_name=value
```
修改变量时有时会提示:  
`Ambiguous set command "...": .`,  
则需加上`var`，即`set var var_name=value`

# 显示变量
## 常规变量显示
* 临时显示:
```shell
p var_name
```
* 每次暂停都显示:
```shell
#确定要显示的变量
display var_name
#取消显示的变量
undisplay var_name
```
* 按照指定格式显示变量
```shell
p/<format> <var_name>
```
format| 说明|
|-    |-    |
|x    |十六进制|
|d    |十进制|
|u    |十进制，无符号|
|o    |八进制|
|t    |二进制|
|a    |打印为地址|
|c    |将值转换为整数|
|f    |浮点数
|s    |字符串|
|z    |该值被视为整数并以十六进制打印|

## 显示数组  
```shell
p *<arr_name>@<len>
```
## 指针变量显示
* 显示指针变量地址:`p &var_ptr_name`
* 显示指针变量内容:
    * 默认格式: `p <var_ptr>`
    * 指定格式:`x/<format> <var_ptr> `
        ><format> 指定查看数据的方式，比如：
        >>x 十六进制  
        >>d 十进制  
        >>u 无符号十进制  
        >>o 八进制  
        >>t 二进制  
        >>a 地址（十六进制）  
        >>c 字符  
        >>f 浮点数  
        >>s 字符串  
        >示例：`x/x var_1`
# 显示调用栈
```shell
backtrace # or 'bt'
```
# 分割窗口
    * layout：用于分割窗口，可以一边查看代码，一边测试：
    * layout src：显示源代码窗口
    * layout asm：显示反汇编窗口
    * layout regs：显示源代码/反汇编和CPU寄存器窗口
    * layout split：显示源代码和反汇编窗口
    * focus [src|asm|regs]:聚焦到指定窗口
    * Ctrl + L：刷新窗口
    * Ctrl + x，再按1：单窗口模式，显示一个窗口
    * Ctrl + x，再按2：双窗口模式，显示两个窗口
    * Ctrl + x，再按a：即退出layout，回到执行layout之前的调试窗口。
