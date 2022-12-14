#include <iostream>
#include <vector>
#include <array>
#include "sort_lib.cpp"

void print_vector(const auto& arr)
{
    for (const auto& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}


void input_vector(std::vector<int>& arr)
{
    int val {};
    for ( ;std::cin >> val; )
    {
        arr.push_back(val);
    }
}


int main()
{
    std::vector<int> arr {};
    input_vector(arr);
    insert_sort_cannon(arr);
    print_vector(arr);

    merge_sort(arr, 0, arr.size());
    print_vector(arr);

}
