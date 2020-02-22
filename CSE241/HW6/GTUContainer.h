#ifndef _GTU_Container_h_
#define _GTU_Container_h_

#include <memory>
#include "GTUIterator.h"
#include "GTUIterator.cpp"
#include "GTUIteratorConst.h"
#include "GTUIteratorConst.cpp"

namespace bugraStl
{

template <typename T>
class GTUContainer
{
public:
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual int max_size() const = 0;

    virtual void erase(GTUIterator<T> position) = 0;
    virtual void insert(const T &element) = 0;

    virtual void clear() = 0;

    virtual GTUIterator<T> begin() const = 0;
    virtual GTUIterator<T> end() const = 0;

    virtual GTUIteratorConst<T> cbegin() const = 0;
    virtual GTUIteratorConst<T> cend() const = 0;
};

}; // namespace bugraStl

#endif