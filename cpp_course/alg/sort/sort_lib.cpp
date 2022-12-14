#include <cstdlib>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <algorithm>


void insert_sort(auto& arr)
{
    for (auto i {arr.begin()}; i != arr.end()-1; i++)
    {
        auto j {i+1};
        while (j != arr.begin() && *j < *(j-1))
        {
            auto buf {*(j-1)};
            *(j-1) = *j;
            *j = buf;
            j--;
        }
    }
    return;

}


void insert_sort_cannon(auto& arr)
{
    for (auto j {arr.begin()+1}; j != arr.end(); j++)
    {
        auto i = j - 1;
        auto key = *j;
        while (i >= arr.begin() && *i > key)
        {
            *(i+1) = *i;
            i--;
        }
        *(i+1) = key;
    }
    return;
}


void merge_sort(auto& arr, const std::size_t left, const std::size_t right)
{
    std::cout << "merge left: " << left << " right: " << right << std::endl;
    if (left < right)
    {
        auto mid = (left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        std::size_t n1 {mid - left + 1}, n2 {right - mid};
        decltype(arr) left_arr (n1);
        decltype(arr) right_arr (n2);
        std::copy(arr.begin()+left, arr.begin()+n1, std::back_inserter(left_arr));
        std::copy(arr.begin()+left+n1, arr.begin()+right, std::back_inserter(right_arr));
        std::cout << "left: " << std::endl;
        for (const auto& val : left_arr)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        std::cout << "right: " << std::endl;
        for (const auto& val : right_arr)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        std::size_t i {0}, j {0}, k {left};
        while (k < right)
        {
            while (i < n1 && left_arr[i] <= right_arr[j])
            {
                arr[k] = left_arr[i];
                i++;
                k++;
            }
            while (j < n2 && left_arr[i] >= right_arr[j])
            {
                arr[k] = right_arr[j];
                j++;
                k++;
            }
        }
        return;
    }
}
