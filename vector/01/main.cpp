#include "vector.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    vector a;
    int data;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data);
        a.push_back(data);
    }
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d ", a[i]);
    }
    cout << endl;

    return 0;
}
