[toc]

# 函数重载
**函数重载** 是多态的一种体现，它要求多个函数可以有相同的函数名，区别这些函数的方式是根据函数的参数列表:
```c++
/*
root 有两个含义:
    1. 支持
    2. 种植
*/
// 支持: 支持什么观点
void root(char* view);
// 种植：在哪里种植什么植物
void root(char* addr, char* name);
```
虽然函数名不同，但在特定的场景下会使用不同的参数列表，那么调用的具体的函数也就不同。

# 模板重载(函数模板)
**模板重载** 的原理和函数重载差不多，还是看参数列表:  
&emsp;<u>**notes**: 在新版本中，可能需要用 `typename` 关键字代替 `class` 关键字, 后者为类模板关键字</u>
```c++
template <class T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T>
void swap(T a[], T b[], T n) {
    T temp;
    for(int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = a[i];
    }
}
```
