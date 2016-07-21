#include "vector.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    cjl::vector a;
    cjl::vector b;
    int data;

    printf("请输入a的数据：");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data);
        a.push_back(data);
    }
    printf("请输入b的数据：");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data);
        b.push_back(data);
    }
    cout << "a的数据：";
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d ", a[i]);
    }
    cout << endl;
    cout << "b的数据：";
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << ' ';
    }
    a.swap(b);
    cout << endl << "a、b交换后：" << endl << "a的数据：";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl << "b的数据：";
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << ' ';
    cout << endl;
    
    int index;
    cout << "请输入两个数字，第一个是你要插入的位置，第二个是你要插入的数据:";
    cin >> index >> data;
    a.insert(a.begin()+index, data);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;

    return 0;
}
