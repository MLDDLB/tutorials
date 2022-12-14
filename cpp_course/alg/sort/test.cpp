#include <iostream>


class Lock_A
{
	public:
		Lock_A() : a(nullptr){}

		Lock_A(const int& val) : a(new int(val)) {
			std::cout << "Called contstructor " << val << std::endl;
		}
		
		~Lock_A()
		{
			std::cerr << "Called destructor" << std::endl;
			delete a;
		}

		void foo()
		{
			throw std::bad_alloc();
			return;
		}

	private:
		int *a;
};


int main()
{
	Lock_A val1 {3};
	val1.foo();
	return 0;
}

