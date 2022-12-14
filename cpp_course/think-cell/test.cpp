#include <iostream>
#include <map>
#include <memory>


int main()
{
	std::map<int, int> m {};
	m[1] = 2;
	m[3] = 4;
	for (const auto& el : m)
	{
		std::cout << el.first << " = " << el.second << std::endl;
	}
	m.erase(m.begin(), m.begin());
	for (const auto& el : m)
	{
		std::cout << el.first << " = " << el.second << std::endl;
	}
	for (auto it {--(m.end())}; it != m.begin(); it--)	{
		std::cout << it->first << " = " << it->second << std::endl;
	}
	return 0;

}
