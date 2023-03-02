#include <iostream>

int main()
{
    try
    {
        while (true)
        {
            new int [1000000000UL];
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    while (true)
    {
        int *p = new(std::nothrow) int [1000000000UL];
        if(p == nullptr)
        {
            std::cout << "Memory allocation failed" << std::endl;
            break;
        }
    }
    
    
    return 0;
}