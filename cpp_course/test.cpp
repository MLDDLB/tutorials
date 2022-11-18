#include <iostream>

void foo(int val)
{
	std::cout << "foo = " << val << std::endl;
}

int main()
{
	int a {4};
	std::cout << a << std::endl;
	a = a << 2 << 2;
	std::cout << a << std::endl;
	return 0;
}
