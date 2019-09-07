#include "list.cpp"
#include <iostream>

int main()
{
    List a;
    for (int i=0; i<20; i++)
    {
        a.push(20-i);
        std::cout<<"Pushed " << 20 - i << std::endl;
        std::cout<<"Got " << a.get(i, 9999) << std::endl;
    }
    return 0;
}
