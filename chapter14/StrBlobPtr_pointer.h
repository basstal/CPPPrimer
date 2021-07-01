#ifndef _STRBLOBPTR_POINTER_H_
#define _STRBLOBPTR_POINTER_H_

#include "StrBlobPtr.h"

class StrBlobPtr_pointer
{
public:
	StrBlobPtr_pointer() = default;
	StrBlobPtr_pointer(StrBlobPtr *ptr):pointer(ptr){}


	StrBlobPtr &operator*() const;
	StrBlobPtr *operator->() const;

private:
	StrBlobPtr *pointer = nullptr;
}

#endif // !_STRBLOBPTR_POINTER_H_
