#ifndef STRBLOB_H_
#define STRBLOB_H_
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>
class StrBlobPtr;
class StrBlob{
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob &b1,const StrBlob &b2);
	friend bool operator!=(const StrBlob &b1,const StrBlob &b2);
	friend bool operator<(const StrBlob &b1,const StrBlob &b2);
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob():data(std::make_shared<std::vector<std::string>>()){}
	StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
	
	StrBlob(const StrBlob &s):data(std::make_shared<std::vector<std::string>>(new std::vector<std::string>>(*s.data))){}
	StrBlob &operator=(const StrBlob &s);
	std::string &operator[](std::size_t n){
		check(n,"index out of range");
		return data->at(n);
	}
	const std::string &operator[](std::size_t n)const{
		check(n,"index out of range");
		return data->at(n);
	}
	StrBlobPtr begin();
	StrBlobPtr end();
	std::string &at(size_type sz);
	bool empty()const{return data->empty();}
	StrBlob &push_back(const std::string &)&&;
	void pop_back();
	std::string &front();
	std::string &back();
	const std::string &front()const;
	const std::string &back()const;
	size_type size()const{return data->size();}
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i,const std::string &msg)const;
};
class StrBlobPtr{	
	//实现指针算数运算的加法和减法运算符
	friend StrBlobPtr operator+(const StrBlobPtr &ptr,std::size_t n);
	friend StrBlobPtr operator-(const StrBlobPtr &ptr,std::size_t n);

	friend bool operator==(const StrBlobPtr &p1,const StrBlobPtr &p2);
	friend bool operator!=(const StrBlobPtr &p1,const StrBlobPtr &p2);
	friend bool operator<(const StrBlobPtr &p1,const StrBlobPtr &p2);
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &s,size_t sz=0):wptr(s.data),curr(sz){}
	StrBlobPtr(StrBlob *s,size_t sz=0):wptr(s->data),curr(sz){}
	//前置递增递减运算符
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	//后置递增递减运算符
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	//解引用运算符
	std::string &operator*() const 
	{
		auto p = check(curr,"dereference past end");
		return (*p)[curr];
	}
	//箭头运算符
	std::string *operator->() const 
	{
		return & this->operator*();
	}


	std::string & deref() const;
	StrBlobPtr & incr();
private:
	std::shared_ptr<std::vector<std::string>> check(size_t,const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
};

StrBlob &StrBlob::operator=(const StrBlob &s){
	data = std::make_shared<std::vector<std::string>>(new std::vector<std::string>>(*s.data)));
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t sz,const std::string & s)const{
	auto at = wptr.lock();
	if(!at)
		throw std::runtime_error(s);
	else if(sz >= at->size())
		throw std::out_of_range(s);
	return at;
}
std::string & StrBlobPtr::deref() const{
	auto p = check(curr,"dereference past end");
	return (*p)[curr];
}
StrBlobPtr &StrBlobPtr::incr(){
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this,data->size());
}
StrBlob &StrBlob::push_back(const std::string &)&&{
	data->push_back(s);
	return *this;
}
void StrBlob::pop_back(){
	check(0,"pop on empty StrBlob!");
	data->pop_back();
}
std::string &StrBlob::front(){
	check(0,"front on empty StrBlob!");
	return data->front();
}
std::string &StrBlob::back(){
	check(0,"back on empty StrBlob!");
	return data->back();
}
const std::string &StrBlob::front()const{
	check(0,"back on empty StrBlob!");
	return data->front();
}
const std::string &StrBlob::back()const{
	check(0,"back on empty StrBlob!");
	return data->back();
}
void StrBlob::check(size_type i,const std::string &msg)const{
	if(i>=data->size())
		throw std::out_of_range(msg);
}
std::string &StrBlob::at(size_type sz){
	check(sz,"size out of range!");
	return data->at(sz);
}



//前置递增递减运算符
StrBlobPtr &StrBlobPtr::operator++()
{
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
	--curr;
	check(curr,"decrement past begin of StrBlobPtr");
	return *this;
}

//后置递增递减运算符
StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr ret=*this;

	++*this;
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret=*this;

	--*this;
	return ret;
}


//------------------------------friend function-------------------------
bool operator==(const StrBlob &b1,const StrBlob &b2){
	return b1.data==b2.data;
}
bool operator!=(const StrBlob &b1,const StrBlob &b2){
	return !(b1==b2);
}

bool operator==(const StrBlobPtr &p1,const StrBlobPtr &p2){
	return (p1.wptr==p2.wptr)&&(p1.curr==p2.curr);
}
bool operator!=(const StrBlobPtr &p1,const StrBlobPtr &p2){
	return !(p1==p2);
}
bool operator<(const StrBlobPtr &p1,const StrBlobPtr &p2){
	if(p1.wptr!=p2.wptr)
		throw runtime_error("p1.wptr!=p2.wptr");
	return p1.curr<p2.curr;
}
bool operator<(const StrBlob &b1,const StrBlob &b2){
	size_t i=0;
	while((i!=b1.size())&&(i!=b2.size())&&(b1.at(i)==b2.at(i)))
		++i;
	if((i!=b2.size())||(b1.at(i)<b2.at(i)))
		return true;
	return false;
}

//实现指针算数运算的加法和减法运算符
inline StrBlobPtr operator+(const StrBlobPtr &ptr,std::size_t n)
{
	StrBlobPtr ret = ptr;

	ret += n;
	return ret;
}

inline StrBlobPtr operator-(const StrBlobPtr &ptr,std::size_t n)
{
	StrBlobPtr ret = ptr;

	ret-=n;
	return ret;
}



#endif