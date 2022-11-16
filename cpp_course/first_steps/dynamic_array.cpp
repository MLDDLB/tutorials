#include <iostream>

class IntArray
{
    private:

        int size;
        int fill;
        int* arr;

    public:
        IntArray();
        IntArray(int ar_size);

        void push(int val);
        int pop();
        int get_size();

        int operator[](const int& val)
        {
            if (val < size)
                return arr[val];
            throw -1;
        }
};

IntArray::IntArray()
    : size{0}, fill{0}, arr{new int[size]}
{}

IntArray::IntArray(int ar_size)
    : size{ar_size}, fill{0}, arr{new int[size]}
{}

void IntArray::push(int val)
{
    if (size == 0)
    {
        size = 1;
        arr = new int(1);
    }
    else if (fill == size)
    {
        size *= 2;
        int* new_arr = new int[size];
        for (int i = 0; i < fill; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    arr[fill] = val;
    fill++;
    return;
}

int IntArray::pop()
{
    if (size == 0)
    {
        arr = new int[0];
    }
    if (fill <= (size/4))
    {
        size /= 2;
        int* new_arr = new int[size];
        for (int i = 0; i < fill; i++)
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    fill--;
    return arr[fill];
}

inline int IntArray::get_size()
{
    return size;
}


int main()
{
    IntArray a {};
    for (int val = (int)std::cin.get()-48; val != 0; val = (int)std::cin.get() - 48)
    {
        a.push(val);
        std::cout << "size = " << a.get_size() << std::endl;
        for (int i = 0; i < a.get_size(); i++)
        {
            std::cout << "a[" << i << "] = " << a[i] << " ";
            if (i == a.get_size()-1)
                std::cout << std::endl; 
        }
    }
    while (a.get_size() > 1)
    {
        a.pop();
        std::cout << "size = " << a.get_size() << std::endl;
        for (int i = 0; i < a.get_size(); i++)
        {
            std::cout << "a[" << i << "] = " << a[i] << " ";
            if (i == a.get_size()-1)
                std::cout << std::endl; 
        }
    }
    return 0;
}