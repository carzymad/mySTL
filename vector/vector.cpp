#include "vector.h"

vector::vector(int length):
    realSize(0), maxSize(length)
{
    arry = new int[length];
}

vector::vector(int data, int size):
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

vector::vector(vector &tmp):
    maxSize(tmp.maxSize), realSize(tmp.realSize)
{
    arry = new int[maxSize];
    for (int i = 0; i < realSize; i++)
    {
        arry[i] = tmp.arry[i];
    }
}

vector::~vector()
{
    delete [] arry;
}

void vector::push_back(int data)
{
    arry[realSize++] = data;
    if (realSize == maxSize)
        copyNewArry();
}

void vector::pop_back()
{
    if (realSize == 0)
        return;
    realSize--;
}

void vector::copyNewArry()
{
    maxSize *= 2;
    int *tmp = new int[maxSize];
    for (int i = 0; i < realSize; i++)
    {
        tmp[i] = arry[i];
    }
    delete [] arry;
    arry = tmp;
}

int vector::size()
{
    return realSize;
}
