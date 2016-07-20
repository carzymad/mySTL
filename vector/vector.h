#ifndef _VECTOR_H_
#define _VECTOR_H_

class vector
{
private:
    int *arry;
    int maxSize;            // 表明当前数组最大长度
    int realSize;           // 表名当前数组已容纳的数据量
    
    void copyNewArry();

public:
    vector(int length = 100);
    vector(int data, int size);
    vector(vector &tmp);    // 拷贝构造函数
    ~vector();
    void push_back(int data);
    void pop_back();
    int size();
    int operator [] (int index)
    {
        return arry[index];
    }
};

#endif
