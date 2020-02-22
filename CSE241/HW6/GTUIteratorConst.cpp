#include "GTUIteratorConst.h"

namespace bugraStl
{

template <typename T>
GTUIteratorConst<T>::GTUIteratorConst(T *ptr) : _ptr(ptr) {}

template <typename T>
T GTUIteratorConst<T>::operator*() const
{
    return *_ptr;
}

template <typename T>
T *GTUIteratorConst<T>::operator->() const
{
    return _ptr;
}

template <typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator+(int add)
{
    _ptr += add;
    return *this;
}

template <typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator-(int sub)
{
    _ptr -= sub;
    return *this;
}

template <typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator++()
{
    _ptr++;
    return *this;
}

template <typename T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator++(int)
{
    GTUIteratorConst tmp = *this;
    _ptr++;
    return tmp;
}

template <typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator--()
{
    _ptr--;
    return *this;
}

template <typename T>
GTUIteratorConst<T> GTUIteratorConst<T>::operator--(int)
{
    GTUIteratorConst tmp = *this;
    _ptr--;
    return tmp;
}

template <typename T>
GTUIteratorConst<T> &GTUIteratorConst<T>::operator=(const GTUIteratorConst &operand)
{
    _ptr = operand._ptr;
    return *this;
}

template <typename T>
bool GTUIteratorConst<T>::operator==(const GTUIteratorConst &operand) const
{
    return (_ptr == operand._ptr);
}

template <typename T>
bool GTUIteratorConst<T>::operator!=(const GTUIteratorConst &operand) const
{
    return !(_ptr == operand._ptr);
}

} // namespace bugraStl