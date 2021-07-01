#include "ConstStrBlobPtr.h"


/**
 *  Return a shared_ptr,if the vector still available and the index within
 *  the range [first, last)
 */
std::shared_ptr<const ConstStrBlobPtr::tp>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    std::shared_ptr<const tp>
            result = wp.lock();

    if(!result)
        throw   std::runtime_error("unbound.");

    if(i >= result->size())
        throw   std::out_of_range(msg);

    return result;
}


/**
 * return the const string of the current index.
 */
const std::string &
ConstStrBlobPtr::dereference() const
{
    std::shared_ptr<const tp>
            sp = check(curr, "the index is out of range");

    return (*sp)[curr];
}


/**
 * increment the current index.
 */
ConstStrBlobPtr &
ConstStrBlobPtr::incr()
{
    check(curr, "out of range");
    ++curr;

    return *this;
}

//! *
const std::string &
ConstStrBlobPtr::operator *() const
{
    auto p = check(curr,"dereference past end.");
    return (*p)[curr];
}

//! ->
const std::string *
ConstStrBlobPtr::operator ->() const
{
    //! delegate the real work to the dereference operator
    return & this->operator *();
}