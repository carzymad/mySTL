#include <iostream>
#include "vector.h"
#include <algorithm>

using namespace std;

int main()
{
    cjl::vector<char> a;
    a.push_back('A');

    cout << *find(a.begin(), a.end(), 'A') << endl;

    return 0;
}
