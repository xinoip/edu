#ifndef _GTU_Vector_h_
#define _GTU_Vector_h_

#include "GTUContainer.h"

namespace bugraStl
{

template <typename T>
class GTUVector : public GTUContainer<T>
{
public:
    GTUVector();

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