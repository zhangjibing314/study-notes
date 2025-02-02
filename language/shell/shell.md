---
title: shell
toc: true
---
# 目录
[TOC]
---
# 变量类型(变量赋值时`=`两边不能有空格)

* 字符串
```sh
var_name='string'
var_name="string"
```
* 整型 
```sh
declare -i var_name = value
```
* 数组
```sh
arr_name=(val1 val2 val3)
```
* 关联数组
```sh
declare arr_name
arr_name["arr_nam"]="zhangsir"
arr_name["age"]=18
```
* 环境变量
```sh
PATH
```
* 获取变量数值
```sh
$var_name
```
---
# 字符串处理
## 字符串拼接
```sh
str1="hello"
str2="world"
# 1. 使用双引号拼接
str3="$str1$str2"
# 2. 使用单引号拼接
str='$str1$str2'
```
## 获取字符串长度
```sh
str='abcde'
echo ${#str}
```
## 提取子串
```sh
str='this is a string'
echo ${str:0:6} #表示从第0个字符开始，取长度为6的子串
```
---
# 数组处理
## 读取数组元素
```sh
arr=(1 2 3 4 5)
echo ${arr[0]} # 读取数组第1个元素
echo ${arr[@]} # 读取数组所有元素
```
## 获取数组长度
```sh
arr=(1 2 3 4 5)
echo ${#arr[@]}
```
---
* 传参
```sh
$0 #执行的文件名
$# #参数的个数
$1 #第一个参数
$2 #第二个参数
$$ #当前脚本运行的PID
$? #显示命令的退出状态
```
---
# 算术运行
* 运算符
|运算符     |说明   |举例                           |
|-          |-      |-                              |
|'+'	    |加法	|`expr $a + $b` 结果为 30。     |
|'-'	    |减法	|`expr $a - $b` 结果为 -10。    |
|'*'	    |乘法	|`expr $a \* $b` 结果为  200。  |
|'/'        |除法	|`expr $b / $a` 结果为 2。      |
|'%'	    |取余	|`expr $b % $a` 结果为 0。      |
|'='	    |赋值	|a=$b 把变量 b 的值赋给 a。     |
|'=='	    |相等	|[ $a == $b ] 返回 false。      |
|'!='	    |不相等 |[ $a != $b ] 返回 true。       |
* 运算
```sh
var1=1
var2=2

var3=`expr $var1 / $var2`
#也可以：
var3=$((var1 + var2))

if [ $a == $b ]
then
   echo "a 等于 b"
fi
if [ $a != $b ]
then
   echo "a 不等于 b"
fi
```
---
# 关系运行
* 运算符
-eq	检测两个数是否相等	        [ $a -eq $b ] 返回 false。
-ne	检测两个数是否不等	        [ $a -ne $b ] 返回 true。
-gt	检测左边是否大于右边	    [ $a -gt $b ] 返回 false。
-lt	检测左边是否小于右边	    [ $a -lt $b ] 返回 true。
-ge	检测左边是否大于等于右边	[ $a -ge $b ] 返回 false。
-le	检测左边是否小于等于右边	[ $a -le $b ] 返回 true。
* 运算
```sh
a=1
b=2

if [ $a -eq $b ]
then
	echo "a=b"
elif [ $a -ne $b ]
then
	echo "a!=b"
fi
```
---
# 布尔运算
* 运算符
!	非运算	[ ! false ] 返回 true。
-o	或运算	[ $a -lt 20 -o $b -gt 100 ] 返回 true。
-a	与运算	[ $a -lt 20 -a $b -gt 100 ] 返回 false。
* 运算
```sh
a=1
b=2
if [ $a -ne $b -a $a -lt 1 ]
then
    echo "something"
fi
```
---
# 逻辑运算
* 运算符
&&	逻辑的 AND	[[ $a -lt 100 && $b -gt 100 ]] 返回 false
||	逻辑的 OR	[[ $a -lt 100 || $b -gt 100 ]] 返回 true
* 运算
```sh
a=10
b=20

if [[ $a -lt 100 && $b -gt 100 ]]
then
   echo "返回 true"
else
   echo "返回 false"
fi
```
---
# 字符串运算
* 运算法
=	检测两个字符串是否相等，相等返回 true。	[ $a = $b ] 返回 false。
!=	检测两个字符串是否不相等，不相等返回 true。	[ $a != $b ] 返回 true。
-z	检测字符串长度是否为0，为0返回 true。	[ -z $a ] 返回 false。
-n	检测字符串长度是否不为 0，不为 0 返回 true。	[ -n "$a" ] 返回 true。
$	检测字符串是否不为空，不为空返回 true。	[ $a ] 返回 true。
* 运算
```sh
a="abc"
b="efg"

if [ $a = $b ]
then
   echo "$a = $b : a 等于 b"
else
   echo "$a = $b: a 不等于 b"
fi
```
---
# 函数
```sh
myfun ()
{
	echo '输入 1 到 4 之间的数字:'
	echo '你输入的数字为:'
	read aNum
	case $aNum in
		1)  echo '你选择了 1'
			;;
		2)  echo '你选择了 2'
			;;
		3)  echo '你选择了 3'
			;;
		4)  echo '你选择了 4'
			;;
		*)  echo '你没有输入 1 到 4 之间的数字'
			;;
	esac
}

myfun
```
---
# 流程控制
* if lese
```sh
a=10
b=20

if (( $a == $b )); then
	echo "a=b"
elif (( $a > $b )); then
	echo "a>b"
else
	echo "a<b"
fi

```
* for 循环
```sh
arr=(1 2 3 4 5)
for var in ${arr[*]}
do
	echo $var
done
#-----------------------------------
for (( var=1 ; var < 10 ; var+=1))
do
	echo "var=$var"
	sleep 1
done

```
* while 循环
```sh
while :
do
	echo "hello world"
	sleep 1
done
```
* case ... esac
```sh
echo '输入 1 到 4 之间的数字:'
echo '你输入的数字为:'
read aNum
case $aNum in
	1)  echo '你选择了 1'
		;;
	2)  echo '你选择了 2'
		;;
	3)  echo '你选择了 3'
		;;
	4)  echo '你选择了 4'
		;;
	*)  echo '你没有输入 1 到 4 之间的数字'
		;;
esac
```
* 跳出循环
```sh
# 1.
break
#2 
continue
```
---
# 文件包含  
**注**:被包含文件不具备执行权限**
```sh
# 1. 
. file_path
# 2.
source file_path
```
