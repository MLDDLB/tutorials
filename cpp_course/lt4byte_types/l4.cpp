#include <iostream>

enum A
{
    T1, T2, T3
};

int main()
{
    short int a {43}, b {43};
    std::cout << "You can't make arythmetic operations with types whose size is less than 4 bytes" << std::endl;
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "sizeof(a) = " << sizeof(a) << " sizeof(b) = " << sizeof(b) <<std::endl;
    std::cout << "a + b = " << (a+b) << std::endl;
    std::cout << "sizeof(a+b) = " << sizeof(a+b) << std::endl;
    std::cout << "The result converts from short int to int" << std::endl;

    char ch1 {'a'}, ch2 {'b'};
    std::cout << "Same with char type (1 byte long)" << std::endl;
    std::cout << "ch1 = " << ch1 << " ch2 = " << ch2 << std::endl;
    std::cout << "ch1 + ch2 = " << (ch1+ch2) << std::endl;
    std::cout << "The resutl was implicitly converted to int, so if we want to get the symbol, "
              << "we need to explicitely convert it back to char" << std::endl;
    std::cout << "ch1 + ch2 = " << static_cast<char>(ch1+ch2) << std::endl;
    return 0;
}
