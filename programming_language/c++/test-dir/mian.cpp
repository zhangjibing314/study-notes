#include <iostream>

class MyClass {
	public:
		static int class_var;  // 类作用域变量

		void set(int i) {
			class_var = i;
		}		       
		int get(void) {
			return class_var;
		}
};

int MyClass::class_var = 30;

int main() {
	std::cout << "类变量: " << MyClass::class_var << std::endl;

	MyClass c;
	c.set(100);
	std::cout << "类变量: " << MyClass::class_var << std::endl;
	std::cout << "类变量: " << c.get() << std::endl;
	return 0;
}
