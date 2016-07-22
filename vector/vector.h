#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

namespace cjl {

template<typename T>
class vector
{
private:
    T *arry;
    T maxSize;            // 表明当前数组最大长度
    T realSize;           // 表名当前数组已容纳的数据量
    
    void copyNewArry()
    {
        maxSize *= 2;
        T *tmp = new T[maxSize];
        for (T i = 0; i < realSize; i++)
        {
            tmp[i] = arry[i];
        }
        delete [] arry;
        arry = tmp;
    }


public:
    typedef T* iterator;              // vector是顺序结构
    typedef const T* const_iterator;  // 同上

    vector(int length = 100):
        realSize(0), maxSize(length)
    {
        arry = new T[length];
    }

    vector(T data, int size):
        maxSize(100), realSize(size)
    {
        if (size > maxSize / 2)
            maxSize = size * 2;
        arry = new int[maxSize];
        for (int i = 0; i < size; i++)
        {
            arry[i] = data;
        }
    }

    vector(const vector &tmp):      // 拷贝构造函数
        maxSize(tmp.maxSize), realSize(tmp.realSize)
    {
        arry = new int[maxSize];
        for (int i = 0; i < realSize; i++)
        {
            arry[i] = tmp.arry[i];
        }
    }
   
    ~vector()
    {
        delete [] arry;
    }

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
    void push_back(int data)   
    {
        arry[realSize++] = data;
        if (realSize == maxSize)
            copyNewArry();
    }

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
    void pop_back()
    {
        if (realSize == 0)
            return;
        realSize--;
    }
    int size()
    {
        return realSize;
    }
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
