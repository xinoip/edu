#ifndef _GTU_Iterator_Const_h_
#define _GTU_Iterator_Const_h_

namespace bugraStl
{

template <typename T>
class GTUIteratorConst
{
public:
    // TODO: Implement GTUIteratorConst class
    GTUIteratorConst(T *ptr);

    T operator*() const;
    T *operator->() const;

    GTUIteratorConst &operator+(int add);
    GTUIteratorConst &operator-(int sub);

    // prefix increment
    GTUIteratorConst &operator++();
    // postfix increment
    GTUIteratorConst operator++(int);
    // prefix decrement
    GTUIteratorConst &operator--();
    // postfix decrement
    GTUIteratorConst operator--(int);

    GTUIteratorConst &operator=(const GTUIteratorConst &operand);

    bool operator==(const GTUIteratorConst &operand) const;
    bool operator!=(const GTUIteratorConst &operand) const;

private:
    T const *_ptr;
};

}; // namespace bugraStl

#endif