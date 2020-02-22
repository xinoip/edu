#include "GTUIterator.h"

namespace bugraStl
{

template <typename T>
GTUIterator<T>::GTUIterator(T *ptr) : _ptr(ptr) {}

template <typename T>
T &GTUIterator<T>::operator*() const
{
    return *_ptr;
}

template <typename T>
T *GTUIterator<T>::operator->() const
{
    return _ptr;
}

template <typename T>
GTUIterator<T> &GTUIterator<T>::operator+(int add)
{
    _ptr += add;
    return *this;
}

template <typename T>
GTUIterator<T> &GTUIterator<T>::operator-(int sub)
{
    _ptr -= sub;
    return *this;
}

template <typename T>
GTUIterator<T> &GTUIterator<T>::operator++()
{
    _ptr++;
    return *this;
}

template <typename T>
GTUIterator<T> GTUIterator<T>::operator++(int)
{
    GTUIterator tmp = *this;
    _ptr++;
    return tmp;
}

template <typename T>
GTUIterator<T> &GTUIterator<T>::operator--()
{
    _ptr--;
    return *this;
}

template <typename T>
GTUIterator<T> GTUIterator<T>::operator--(int)
{
    GTUIterator tmp = *this;
    _ptr--;
    return tmp;
}

template <typename T>
GTUIterator<T> &GTUIterator<T>::operator=(const GTUIterator &operand)
{
    _ptr = operand._ptr;
    return *this;
}

template <typename T>
bool GTUIterator<T>::operator==(const GTUIterator &operand) const
{
    return (_ptr == operand._ptr);
}

template <typename T>
bool GTUIterator<T>::operator!=(const GTUIterator &operand) const
{
    return !(_ptr == operand._ptr);
}

} // namespace bugraStl