#include <iostream>


int main()
{
    int r_val {300};
    auto foo = [&r_val]() -> int {return r_val;};
    auto l_val = foo();
    std::cout << "l_val = " << l_val << std::endl;
    return 0;
}