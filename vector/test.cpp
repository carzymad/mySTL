#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    int data;
    cjl::vector a;
    cjl::vector b;
    for (int i = 0; i < 3; i++)
    {
        cin >> data;
        a.push_back(data);
    }
    for (int i = 0; i < 5; i++)
    {
        cin >> data;
        b.push_back(data);
    }
    cout << "a.size = " << a.size() << endl;
    cout << "b.size = " << b.size() << endl;
    
    a.swap(b);

    cout << "a.size = " << a.size() << endl;
    cout << "b.size = " << b.size() << endl;
    
    cout << "a:";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl << "b:";
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << ' ';
    cout << endl;
    
    int index = 3;
    a.insert(a.begin()+index, 1);

    cout << endl << "a:";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;

    cjl::vector::iterator it;
    for (it = a.begin(); it != a.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}

/*
int main()
{
    cjl::vector a;
    int data;
    for (int i = 0; i < 5; i++)
    {
        cin >> data;
        a.push_back(data);
    }
    for (int i = 0; i < 5; i++)
        cout << a[i] << ' ';
    cout << endl;
    int index;
    cin >> index >> data;
    a.insert(a.begin()+index, data);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;

    return 0;
}*/
