#include <memory>
#include <iostream>

// You can use smart pointers to incapsulate pointers to large objects
class LargeObject
{
    public:
        void do_something() const
        {
            std::cout << "Do something" << std::endl;
        }
};


void process_large_object(const LargeObject& obj)
{
    obj.do_something();
    return;
}


void smart_pointer_demo()
{
    // Create an object in the heap and pass it to the smart pointer
    std::unique_ptr<LargeObject> obj {new LargeObject()};
    // You can access object's methods
    obj->do_something();
    // Pass object as a reference to the other method
    process_large_object(*obj);
} // Object is deleted when the smart pointer goes out of scope


void smart_pointer_demo_2()
{
    std::unique_ptr<int> obj {new int(3)};
    std::cout << "Smart pointer points to the: " << obj << " with value: " << *obj << std::endl;
    // You can use p.reset() to free the pointer before the end of block
    obj.reset();
    std::cout << "After reset: " << obj << std::endl;
}


void legacy_api(const int* raw_pointer){}


void smart_pointer_demo_3()
{
    std::unique_ptr<int> obj {new int(3)};
    // You can access the raw pointer underneath using get() method
    legacy_api(obj.get());
}


void use_raw_pointer()
{
    // Using a raw pointer -- not recommended
    int* raw_p = new int(3);
    std::cout << "raw_p points to: " << raw_p << " with value: " << *raw_p << std::endl;
    // If we forget to delete it, we'll cause memory leak
    delete raw_p;
}


void use_smart_pointer()
{
    // Declare smart pointer on the stack and pass it the raw pointer
    std::unique_ptr<int> sm_p {new int(3)};
    // Initializing smart pointers with the '(expression)' is prohibited ( {} or = )
    std::cout << "sm_p points to: " << sm_p << " with value: " << *sm_p << std::endl;
} // Smart pointer will be deleted here automatically


int main()
{
    use_raw_pointer();
    use_smart_pointer();
    smart_pointer_demo();
    smart_pointer_demo_2();
    return 0;
}