#include <iostream>

void foo(int* a)
{
	std::cout << "a = " << a << std::endl;
}

int main()
{
	int* a = new int(5);
	foo(a);
	return 0;
}
