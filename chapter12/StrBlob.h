#ifndef STRBLOB_H_
#define STRBLOB_H_
#include<string>
#include<vector>
#include<memory>
#include<stdexcept>
class StrBlobPtr;
class StrBlob{
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob():data(std::make_shared<std::vector<std::string>>()){}
	StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}
	

	StrBlobPtr begin();
	StrBlobPtr end();
	std::string &at(size_type sz);
	bool empty()const{return data->empty();}
	void push_back(const std::string &);
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
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &s,size_t sz=0):wptr(s.data),curr(sz){}
	StrBlobPtr(StrBlob *s,size_t sz=0):wptr(s->data),curr(sz){}

	std::string & deref() const;
	StrBlobPtr & incr();
	bool operator!=(const StrBlobPtr &)const;
private:
	std::shared_ptr<std::vector<std::string>> check(size_t,const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
};
bool StrBlobPtr::operator!=(const StrBlobPtr &ptr)const{
	if(ptr.curr!=this->curr)
		return true;
	return false;
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
void StrBlob::push_back(const std::string &s){
	data->push_back(s);
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
#endif