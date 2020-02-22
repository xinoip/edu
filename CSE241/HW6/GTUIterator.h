#ifndef _GTU_Iterator_h_
#define _GTU_Iterator_h_

namespace bugraStl
{

template <typename T>
class GTUIterator
{
public:
    GTUIterator(T *ptr);

    T &operator*() const;
    T *operator->() const;

    GTUIterator &operator+(int add);
    GTUIterator &operator-(int sub);

    // prefix increment
    GTUIterator &operator++();
    // postfix increment
    GTUIterator operator++(int);
    // prefix decrement
    GTUIterator &operator--();
    // postfix decrement
    GTUIterator operator--(int);

    GTUIterator &operator=(const GTUIterator &operand);

    bool operator==(const GTUIterator &operand) const;
    bool operator!=(const GTUIterator &operand) const;

private:
    T *_ptr;
};

}; // namespace bugraStl

#endif