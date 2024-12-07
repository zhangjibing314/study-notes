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
* 方案一：临时显示:
```shell
p var_name
```
* 方案二：每次暂停都显示:
```shell
#确定要显示的变量
display var_name
#取消显示的变量
undisplay var_name
```
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
