#include <iostream>
#include <string>
#include <bitset>

int main()
{
	int* a = new int(2.9);
	std::cout << "a = " << a[0] << " a = " << *a << " a = a " << (a[0]==*a) << std::endl;
	return 0;
}
