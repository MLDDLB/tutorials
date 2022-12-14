#include <iostream>
#include <vector>


void foo(int arr[])
{
	for (int i {0}; i < 5; i++)
	{
		arr[i] = 0;
	}
	return;
}


void foo2(std::vector<int> arr)
{
	for (int i {0}; i < 5; i++)
	{
		arr[i] = 0;
	}
	return;
}


int main(){
	int a[5] {1, 2, 3, 4, 5};
	foo(a);
	for (const int& val : a)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
	std::vector<int> b {1, 2, 3, 4, 5};
	foo2(b);
	for (const auto& val : b)
	{
		std::cout << val << " ";
	}
	std::cout << std::endl;
	return 0;

}
