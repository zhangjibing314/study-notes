---
title: grep
toc: true
---
[toc]

# 简介  
    1. grep命令是一种强大的文本搜索工具，它能使用正则表达式搜索文本，并把匹配的行打印出来（匹配到的标红);
    2. grep全称是Global Regular Expression Print，表示全局正则表达式版本，它的使用权限是所有用户;
　　3. 工作方式:它在一个或多个文件中搜索字符串模板。若模板包括空格，则必须被引用，模板后的所有字符串被看作文件名。搜索的结果被送到标准输出，不影响原文件内容。
　　4. grep可用于shell脚本，因为grep通过返回一个状态值来说明搜索的状态，若模板搜索成功，则返回0，如果搜索不成功，则返回1，如果搜索的文件不存在，则返回2。我们利用这些返回值就可进行一些自动化的文本处理工作。

　　egrep = grep -E：扩展的正则表达式 （除了\< , \> , \b 使用其他正则都可以去掉\）

---
# 一般格式：
```shell
grep [选项...] [模式] [文件...]
```
---
# 常见选项：
|选项 |说明                          |
|----|------------------------------|
|-i  |匹配是忽略大小写|
|-v  |反向查找，即只打印不匹配的行|
|-n  |显示匹配行的行号|
|-r  |递归查找子目录的文件|
|-l  |只打印匹配的文件名|
|-c  |只打印匹配的行数|

---
# 更多参数：
>-a 或 --text : 不要忽略二进制的数据。
>-A<显示行数>或--after-context=<显示行数> : 除了显示符合范本样式的那一列之外，并显示该行之后的内容。
>-b 或 --byte-offset : 在显示符合样式的那一行之前，标示出该行第一个字符的编号。
>-B<显示行数> 或 --before-context=<显示行数> : 除了显示符合样式的那一行之外，并显示该行之前的内容。
>-C<显示行数> 或 --context=<显示行数>或-<显示行数> : 除了显示符合样式的那一行之外，并显示该行之前后的内容。
>-d <动作> 或 --directories=<动作> : 当指定要查找的是目录而非文件时，必须使用这项参数，否则grep指令将回报信息并停止动作。
>-e<范本样式> 或 --regexp=<范本样式> : 实现多个选项之间的逻辑或关系。
>-E 或 --extended-regexp : 将样式为延伸的正则表达式来使用。
>-f<规则文件> 或 --file=<规则文件> : 指定规则文件，其内容含有一个或多个规则样式，让grep查找符合规则条件的文件内容，格式为每行一个规则样式。
>-F 或 --fixed-regexp : 将样式视为固定字符串的列表。
>-G 或 --basic-regexp : 将样式视为普通的表示法来使用。
>-h 或 --no-filename : 在显示符合样式的那一行之前，不标示该行所属的文件名称。
>-H 或 --with-filename : 在显示符合样式的那一行之前，表示该行所属的文件名称。
>-i 或 --ignore-case : 忽略字符大小写的差别。
>-l 或 --file-with-matches : 列出文件内容符合指定的样式的文件名称。
>-L 或 --files-without-match : 列出文件内容不符合指定的样式的文件名称。
>-n 或 --line-number : 在显示符合样式的那一行之前，标示出该行的列数编号。
>-o 或 --only-matching : 只显示匹配PATTERN 部分。
>-q 或 --quiet或--silent : 不显示任何信息。
>-r 或 --recursive : 此参数的效果和指定"-d recurse"参数相同。
>-s 或 --no-messages : 不显示错误信息。
>-v 或 --invert-match : 显示不包含匹配文本的所有行。
>-V 或 --version : 显示版本信息。
>-w 或 --word-regexp : 只显示全字符合的列。
>-x --line-regexp : 只显示全列符合的列。
>-y : 此参数的效果和指定"-i"参数相同。

---
# grep中的逻辑关系(and, or, not)
* 逻辑与  
1. 使用 `\|`
```shell
grep 'pattern1\|pattern2' filename
```
2. 使用 `-E`
```shell
grep -E 'pattern1|pattern2' filename
```
3. 使用 `-e`
```shell
grep -e 'pattern1' -e 'pattern2' filename
```
* 逻辑或  
1. 使用管道
```shell
grep -E 'pattern1' filename | grep -E 'pattern2'
```
2. 使用 `.*`和`|`
```shell
grep -E 'pattern1.*pattern2|pattern2.*pattern1' filename
```
* 逻辑非
1. 使用 `-V`
```shell
grep -V 'pattern' filename
```
