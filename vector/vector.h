#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

namespace cjl {

class vector
{
private:
    int *arry;
    int maxSize;            // 表明当前数组最大长度
    int realSize;           // 表名当前数组已容纳的数据量
    
    void copyNewArry();

public:
    typedef int* iterator;              // vector是顺序结构，所以将迭代器定义为int*就行了
    typedef const int* const_iterator;  // 同上

    vector(int length = 100);
    vector(int data, int size);
    vector(const vector &tmp);    // 拷贝构造函数
    ~vector();
    iterator begin() const
    {
        return arry;
    }
    iterator end() const
    {
        return arry+realSize;
    }
    void swap(vector &dir)        // 交换两个vector
    {
        int tmpRealSize, tmpMaxSzie;
        int *tmpArry;
        tmpMaxSzie = maxSize;       // 暂存
        tmpRealSize = realSize;     // 暂存
        tmpArry = arry;             // 暂存
        
        maxSize = dir.maxSize;
        realSize = dir.realSize;
        arry = dir.arry;
        
        dir.maxSize = tmpMaxSzie;
        dir.realSize = tmpRealSize;
        dir.arry = tmpArry;
    }
    void clear()        // 清空数组
    {
        realSize = 0;
    }
    bool empty()        // 判断数组是否为空
    {
        return realSize ? false : true;
    }
    void push_back(int data);   
    void insert(iterator index, int data)       // 从数组中间插入
    {
        if (index == end()) {
            *index = data;
            realSize++;
            return;
        }
        if (index == begin())
            index += 1;
        if (realSize+1 == maxSize) {
            copyNewArry();
        }
        for (iterator i = end(); i > index-1; i--) {
            *i = *(i-1);
        }
        *(index-1) = data;
        realSize++;
    }
    void pop_back();
    int size();
    int capacity()      // 当前状态下不申请新空间下，能储存的最大数量
    {
        return maxSize;
    }
    int front()         // 返回第一个元素的值
    {
        return arry[0];
    }
    int operator [] (int index)
    {
        return arry[index];
    }
};


}       // 命名空间结束的地方

#endif
