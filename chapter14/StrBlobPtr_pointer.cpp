#include "StrBlobPtr_pointer.h"

StrBlobPtr &StrBlobPtr::operator*() const
{
	return *pointer;
}

StrBlobPtr *StrBlobPtr::operator->() const
{
	return & this->operator*();
}

