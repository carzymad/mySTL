#ifndef _ALGORITHM_H
#define _ALGORITHM_H

template<typename iterator, typename T>
iterator find(iterator begin, iterator end, T value)
{
    while (begin != end && *begin != value)
    {
        begin++;
    }

    return begin;
}

#endif
