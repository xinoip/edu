#ifndef _GTU_Set_h_
#define _GTU_Set_h_

#include "GTUContainer.h"

namespace bugraStl
{

template <typename T>
class GTUSet : public GTUContainer<T>
{
public:
    GTUSet();

    bool empty() const;
    int size() const;
    int max_size() const;

    void insert(const T &element);
    void erase(GTUIterator<T> position);

    void clear();

    GTUIterator<T> begin() const;
    GTUIterator<T> end() const;

    GTUIteratorConst<T> cbegin() const;
    GTUIteratorConst<T> cend() const;

private:
    int _capacity;
    int _size;
    std::shared_ptr<T> _data;
};

}; // namespace bugraStl

#endif