#include <iostream>
#include <limits>

/*
    std::numeric_limits<T>::max()
    std::numeric_limits<T>::min()
    std::numeric_limits<T>::lowest()
*/
int main()
{
    std::cout << "=====Short int====" << std::endl;
    std::cout << "Min(lowest number): " << std::numeric_limits<short int>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<short int>::max() << std::endl;
    std::cout << "Lowest(same as min() for int): " << std::numeric_limits<short int>::lowest() <<std::endl;

    std::cout << "=====Int32=====" << std::endl;
    std::cout << "Min: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Lowest: " << std::numeric_limits<int>::lowest() << std::endl;

    std::cout << "=====Long int=====" << std::endl;
    std::cout << "Min: " << std::numeric_limits<long int>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<long int>::max() << std::endl;
    std::cout << "Lowest: " << std::numeric_limits<long int>::lowest() << std::endl;

    std::cout << "=====Long long int=====" << std::endl;
    std::cout << "Min: " << std::numeric_limits<long long int>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<long long int>::max() << std::endl;
    std::cout << "Lowest: " << std::numeric_limits<long long int>::lowest() << std::endl;

    std::cout << "=====Unsigned int====" << std::endl;
    std::cout << "Min: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Lowest: " << std::numeric_limits<unsigned int>::lowest() << std::endl; 

    std::cout << "=====Float=====" << std::endl;
    std::cout << "Min(closest to zero): " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Lowest(lowest negative number): " << std::numeric_limits<float>::lowest() << std::endl;

    std::cout << "=====Double=====" << std::endl;
    std::cout << "Min(closest to zero): " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "Lowest(lowest negative number): " << std::numeric_limits<double>::lowest() << std::endl;

    std::cout << "=====Long double=====" << std::endl;
    std::cout << "Min(closest to zero): " << std::numeric_limits<long double>::min() << std::endl;
    std::cout << "Max: " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Lowest(lowest negative number): " << std::numeric_limits<long double>::lowest() << std::endl;

    std::cout << "=====Other facilities=====" << std::endl;
    std::cout << "Int is signed: " << std::numeric_limits<int>::is_signed << std::endl;
    std::cout << "Int digits: " << std::numeric_limits<int>::digits << std::endl;
    std::cout << "Int digits(base 10): " << std::numeric_limits<int>::digits10 << std::endl;
    return 0;
}