#include "GTUSet.h"
#include <exception>

namespace bugraStl
{

template <typename T>
GTUSet<T>::GTUSet()
{
    _capacity = 0;
    _size = 0;
    // TODO: Change to make shared
    std::shared_ptr<T> tmp(new T[_capacity]);
    _data = tmp;
}

template <typename T>
bool GTUSet<T>::empty() const
{
    return (_size == 0);
}

template <typename T>
int GTUSet<T>::size() const
{
    return _size;
}

template <typename T>
int GTUSet<T>::max_size() const
{
    return _capacity;
}

template <typename T>
void GTUSet<T>::insert(const T &element)
{
    for (auto itr = begin(); itr != end(); itr++)
    {
        if (*itr == element)
        {
            throw std::invalid_argument("GTUSet: (ex) Object already exists!");
        }
    }

    if (size() < max_size())
    { // Space available, just put element
        *(end()) = element;
        _size++;
    }
    else
    { // Increase space by 10 and then put element
        _capacity += 10;
        std::shared_ptr<T> tmp(new T[this->_capacity]);

        // Copy current data to new data
        for (auto itr = begin(), index = 0; itr != end(); itr++, index++)
        {
            tmp.get()[index] = *itr;
        }

        // Free old data
        _data = nullptr;
        // Swap with new data
        _data = tmp;

        // Add element to end
        *(end()) = element;
        _size++;
    }
}

template <typename T>
void GTUSet<T>::erase(GTUIterator<T> position)
{
    std::shared_ptr<T> tmp(new T[this->_capacity - 1]);

    for (auto itr = begin(), index = 0; itr != end(); itr++, index++)
    {
        if (itr == position)
        {
            index--;
        }
        else
        {
            tmp.get()[index] = *itr;
        }
    }
    _size--;

    // Free old data
    _data = nullptr;
    // Swap with new data
    _data = tmp;
}

template <typename T>
void GTUSet<T>::clear()
{
    _capacity = 0;
    _size = 0;
    _data = nullptr;
}

template <typename T>
GTUIterator<T> GTUSet<T>::begin() const
{
    return GTUIterator<T>(_data.get());
}

template <typename T>
GTUIterator<T> GTUSet<T>::end() const
{
    return GTUIterator<T>(_data.get() + _size);
}

template <typename T>
GTUIteratorConst<T> GTUSet<T>::cbegin() const
{
    return GTUIteratorConst<T>(_data.get());
}

template <typename T>
GTUIteratorConst<T> GTUSet<T>::cend() const
{
    return GTUIteratorConst<T>(_data.get() + _size);
}

} // namespace bugraStl