#ifndef _Global_Functions_h_
#define _Global_Functions_h_

#include <iostream>

using namespace bugraStl;

// find value and return iterator to it
template <typename T>
GTUIterator<T> find(GTUIterator<T> first, GTUIterator<T> last, const T &val)
{
    while (first != last)
    {
        if (*first == val)
            return first;

        first++;
    }
}

// find value that satisfies given function and return iterator to it
template <typename T, typename Function>
GTUIterator<T> find_if(GTUIterator<T> first, GTUIterator<T> last, Function pred)
{
    while (first != last)
    {
        if (pred(*first))
            return first;

        first++;
    }
}

// do the given function for every value in between given iterators
template <typename T, typename Function>
Function for_each(GTUIterator<T> first, GTUIterator<T> last, Function func)
{
    while (first != last)
    {
        func(*first);

        first++;
    }

    return func;
}

// print values in between given iterators
template <typename T>
void printContainer(GTUIteratorConst<T> first, GTUIteratorConst<T> last)
{
    for (auto itr = first; itr != last; itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << "\n";
}

#endif