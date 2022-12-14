#include <iostream>
#include <map>


int main() {
	std::map<int, int> m {};
	std::cout << "m.begin() == m.end() = " << (m.begin() == m.end()) << std::endl;
	return 0;
}
