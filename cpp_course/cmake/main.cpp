#include <iostream>
#include "lib.hpp"

int main(int argc, char **argv)
{
    int val = 8;
    const int sqr_val = sqr(8);
    std::cout << "val = " << val << " sqr = " << sqr_val << std::endl;
    return 0;
}