#include <iostream>
#include <cstring>
#include <vector>


int main () {
    std::cout << "Enter your name: ";
    std::vector<char> a {};
    for (char ch = std::cin.get() ; ch != '1'; ch = std::cin.get())
    {
        a.push_back(ch);
    }
    std::cout << "Enter the number of repeatitions: ";
    int rep {0};
    std::cin >> rep;
    for (int i = 0; i < rep; i++)
    {
        for (char ch : a){
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    std::cout << a.data();
    char b[3] = {'a', 'b', 'c'};
    std::cout << "b = " << b;
    return 0;
}