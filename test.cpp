#include "list.cpp"
#include <iostream>
using namespace std;

int main()
{
        Node a(nullptr, nullptr, 0);
        cout << 'a\n';
        Node b(&a, nullptr, 1);
        cout << 'b\n';
        Node c(&b, nullptr, 2);
        cout << 'c\n';        
        b.safe_delete();
        cout << 'b safe_deleted\n';
        
        cout << a.get_prev() << ' ' << a.get_next() << endl;
        cout << c.get_prev() << ' ' << b.get_next() << endl;
        
        return 0;
        
}
