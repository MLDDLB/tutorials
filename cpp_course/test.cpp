#include <iostream>

int main() {
	std::size_t size {10};	
	
	int p1[size] {};
	std::cout << "p1 = " << p1 << " *p1 = " << *p1 << std::endl;
	for (auto val : p1) {
		std::cout << "val = " << val << " ";
	}
	std::cout << std::endl;
	int a {0}, b{1};
	std::cout << "res = " << (a or b) <<std::endl;
	a xor_eq b;
	std::cout << "a = " << a << std::endl;
	return 0;
}
