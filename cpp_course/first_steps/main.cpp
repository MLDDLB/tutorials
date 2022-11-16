#include <iostream>

consteval int get_value(){
    return 3;
}

int main(){
    constexpr int value = get_value();
    std::cout << "value : " << value << std::endl;
    try{
        int a = 2;
        int b = 0;
        if (b == 0){ throw std::exception();}
        std::cout << "a = " << a << std::endl;
    }
    catch (...)
    {
        std::cerr << "cought" << std::endl;
        return -1;
    }
    return 0;
}