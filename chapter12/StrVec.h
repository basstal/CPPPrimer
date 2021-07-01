#include<string>
#include<memory>

class StrVec{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec &);
	StrVec & operator=(const StrVec &);
	~StrVec();

	void push_back(const std::string &);
	std::string * begin()const {return elements;}
	std::string * end()const{return first_free;}
	std::size_t size()const {return first_free - elements;}
	void reserve(size_t n);
	void resize(size_t n,const std::string &s);
	std::size_t capacity() const{return cap-elements;}
	std::string at(size_t n)const{return *(elements+n);}
private:
	std::allocator<std::string> alloc;
	void chk_n_alloc(){
		if(size() == capacity())reallocate();
	}
	std::pair<std::string*,std::string *> alloc_n_copy(const std::string*,const std::string*);
	void free();
	void reallocate();
	std::string * elements;//指向string数组的头部
	std::string * first_free;//指向string数组的第一个空位置
	std::string * cap;//指向allocate申请的string数组末尾
};


//-------------------public function--------------------------
StrVec::StrVec(const StrVec & sv){
	auto newdata = alloc_n_copy(sv.begin(),sv.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(std::initializer_list<std::string> il){
	auto newdata=alloc.allocate(il.size());
	auto elem=newdata;
	for(auto bg=il.begin();bg!=il.end();++bg)
		alloc.construct(elem++,*bg);
	elements=newdata;
	first_free=elem;
	cap=newdata+il.size();
}
StrVec & StrVec::operator =(const StrVec & sv){
	auto newdata = alloc_n_copy(sv.begin(),sv.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
StrVec::~StrVec(){
	free();
}
void StrVec::push_back(const std::string &s){
	chk_n_alloc();
	alloc.construct(first_free++,s);
}
void StrVec::reserve(size_t n){
	if(n>capacity()){
		auto newdata=alloc.allocate(n);
		auto dest=newdata;
		auto elem=elements;
		for(size_t i=0;i!=size();++i)
			alloc.construct(dest++,std::move(*elem++));
		free();
		elements=newdata;
		first_free=dest;
		cap=newdata+n;
	}
}
void StrVec::resize(size_t n,const std::string &s=""){
	auto newdata=alloc.allocate(n);
	auto dest=newdata;
	auto elem=elements;
	if(n<=size())
		for(int i=0;i!=n;++i)
			alloc.construct(dest++,std::move(*elem++));
	else{
		for(int i=0;i!=size();++i)
			alloc.construct(dest++,std::move(*elem++));
		for(int i=size();i!=n;++i)
			alloc.construct(dest++,std::string(s));
	}
	free();
	elements=newdata;
	first_free=dest;
	cap=newdata+n;
}


//----------------------------private function---------------------------------
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b,const std::string *e){
	auto data = alloc.allocate(e-b);
	return {data,uninitialized_copy(b,e,data)};
}
void StrVec::free(){
	if(elements){
		for(auto p = first_free;p!=elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements,cap-elements);
	}
}
void StrVec::reallocate(){
	auto newcapacity = size()?size()*2 : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0;i!=size();++i)
		alloc.construct(dest++,std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}