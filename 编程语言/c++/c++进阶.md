[toc]

# 异常处理
## 1. 简介  
c++异常是指在程序运行过程中产生的特殊情况，通常这些特殊情况需要得到特殊处理。

## 2. C++异常处理涉及到三个关键字：try、catch、throw:
    * **throw**: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
    * **catch**: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
    * **try**: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。

## 3. 结构
```c++
try
{
    // 保护代码
}catch( ExceptionName e1 )
{
    // catch 块
}catch( ExceptionName e2 )
{
    // catch 块
}catch( ExceptionName eN )
{
    // catch 块
}
```
## 4. 示例
```c++
#include <iostream>
using namespace std;

double division(int a, int b)
{
    if( b == 0 )
    {
        throw "Division by zero condition!";
    }
    return ((double)a / b);
}

int main ()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    }catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}
```

* c++标准的异常<exception>
这些标准异常通过父子类层次结构组织起来，如下图所示：
![异常处理](./pictures/c++进阶-异常处理-标准异常组织结构图.png)

|异常                   |表述                                                                       |
|:----------------------|:--------------------------------------------------------------------------|
|std\:\:exception       |该异常是所有标准 C++ 异常的父类。                                          |
|std::bad_alloc         |该异常可以通过 new 抛出。                                                  |
|std::bad_cast|该异常可以通过 dynamic_cast 抛出。                                                   |
|std::bad_typeid    |该异常可以通过 typeid 抛出。                                                   |
|std::bad_exception|这在处理 C++ 程序中无法预期的异常时非常有用。                                   |
|std::logic_error       |理论上可以通过读取代码来检测到的异常。                                     |
|std::domain_error|当使用了一个无效的数学域时，会抛出该异常。                                       |
|std::invalid_argument  |当使用了无效的参数时，会抛出该异常。                                       |
|std::length_error      |当创建了太长的 std::string 时，会抛出该异常。                              |
|std::out_of_range      |该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator\[]()。 |
|std::runtime_error     |理论上不可以通过读取代码来检测到的异常。                                   |
|std::overflow_error    |当发生数学上溢时，会抛出该异常。                                           |
|std::range_error       |当尝试存储超出范围的值时，会抛出该异常。                                   |
|std::underflow_error   |当发生数学下溢时，会抛出该异常。                                           |

---
# 模板  

模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。模板可以用来定义函数和类：
## 1. 函数模板
定义形式：  
```C++
template <typename type> ret-type func-name(parameter list)
{
   // 函数的主体
}
```
示例  
```C++
#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
	return a < b ? b:a; 
} 
int main ()
{

	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl; 

	double f1 = 13.5; 
	double f2 = 20.7; 
	cout << "Max(f1, f2): " << Max(f1, f2) << endl; 

	string s1 = "Hello"; 
	string s2 = "World"; 
	cout << "Max(s1, s2): " << Max(s1, s2) << endl; 

	return 0;
}
```

## 2. 类模板
定义形式：
```C++
template <class type> class class-name {

}
```
示例：
```C++
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack { 
	private: 
		vector<T> elems;     // 元素 

	public: 
		void push(T const&);  // 入栈
		void pop();               // 出栈
		T top() const;            // 返回栈顶元素
		bool empty() const{       // 如果为空则返回真。
			return elems.empty(); 
		} 
}; 

	template <class T>
void Stack<T>::push (T const& elem) 
{ 
	// 追加传入元素的副本
	elems.push_back(elem);    
} 

	template <class T>
void Stack<T>::pop () 
{ 
	if (elems.empty()) { 
		throw out_of_range("Stack<>::pop(): empty stack"); 
	}
	// 删除最后一个元素
	elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const 
{ 
	if (elems.empty()) { 
		throw out_of_range("Stack<>::top(): empty stack"); 
	}
	// 返回最后一个元素的副本 
	return elems.back();      
} 

int main() 
{
	try { 
		Stack<int>         intStack;  // int 类型的栈 
		Stack<string> stringStack;    // string 类型的栈 

		// 操作 int 类型的栈 
		intStack.push(7); 
		cout << intStack.top() <<endl; 

		// 操作 string 类型的栈 
		stringStack.push("hello"); 
		cout << stringStack.top() << std::endl; 
		stringStack.pop(); 
		stringStack.pop(); 
	} 
	catch (exception const& ex) { 
		cerr << "Exception: " << ex.what() <<endl; 
		return -1;
	} 
}
```
# 自定义namespace
在单独的文件中自定义的'namespace'是无法在全局命名空间中使用的因为它不在全局命名空间中.若想在 main.c 中使用该'namespace'中定义的内容,就需要一个'myNmaespace.h'的头文件中进行声明,然后在mian.c中引用。
