#ifndef _CONSTSTRBLOBPTR_H_
#define _CONSTSTRBLOBPTR_H_

#include "StrBlob.h"

class ConstStrBlobPtr
{
public:
	typedef std::vector<std::string>    tp;

	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &sb, std::size_t sz = 0) :
		wp(sb.data), curr(sz){}

	const std::string& dereference() const;
	ConstStrBlobPtr& incr();

	//?Exercise - 14.30 ConstStrBlobPtr
	//?const function member returns const std::string &/*
	const std::string& operator* () const;
	const std::string* operator->() const;

private:
	std::shared_ptr<const tp>
	check(std::size_t i, const std::string &msg) const;

	std::weak_ptr<const tp> wp;
	std::size_t curr;
};
#endif // !_CONSTSTRBLOBPTR_H_
