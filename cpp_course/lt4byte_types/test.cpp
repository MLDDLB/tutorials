#include <iostream>
#include <limits>

int main()
{
	int a[10] {1, 2, 3, 4, 5, 6};

	for (size_t i {}; i < 10; i++)
	{
		std::cout << sizeof(i) <<std::endl;
		break;
	}
	return 0;
}
