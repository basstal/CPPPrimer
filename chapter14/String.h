#include<iostream>
#include<algorithm>
#include<cctype>
#define NDEBUG
class String{
	friend void print(const String &);
	friend ostream &operator<<(ostream &strm,const String &str);
	friend bool operator==(const String &s1,const String &s2);
	friend bool operator!=(const String &s1,const String &s2);
	friend bool operator<(const String &s1,const String &s2);
public:
	String();
	String(const char *c);
	String(const String&);
	String(String &&)noexcept;
	String &operator=(String &&)noexcept;
	String &operator=(const String &);
	char &operator[](std::size_t n){
		return *(begin+n)
	}
	const char &operator[](std::size_t n)const{
		return *(begin+n);
	}
	~String();

	size_t size()const{return end-begin;}
	
private:
	std::allocator<char> alloc;
	char * begin;
	char * end;
	void construction(const char *c,size_t sz); 
	size_t getSize(const char *c);
	void free();
};

//---------------------------------public function----------------------------
String::String(String &&s):begin(s.begin),end(s.end)noexcept{
	s.begin=s.end=0;
	std::cout<<"String::String(String &&s)"<<std::endl;
}	
String &String::operator=(String &&s)noexcept{
	if(this!=&s){
		free();
		begin=s.begin;
		end=s.end;
	}
	s.begin=s.end=0;
	return *this;
}
String::String():begin(nullptr),end(nullptr){}
String::String(const char *c){
	std::cout<<"String::String(const char *c)"<<std::endl;
	if(c){
#ifndef NDEBUG
		std::cout<<"in if(c)"<<std::endl;
#endif
		construction(c,getSize(c));
#ifndef NDEBUG
		print(*this);
#endif
	}
	else{
		begin=nullptr;
		end=nullptr;
	}
}
String::String(const String &s){
	std::cout<<"String::String(const String &s)"<<std::endl;
#ifndef NDEBUG
	std::cout<<"*s.begin="<<*(s.begin)<<" s.size()="<<s.size()<<std::endl;
#endif
	construction(s.begin,s.size());
#ifndef NDEBUG
	print(*this);
#endif
}
String &String::operator=(const String &s){
	std::cout<<"String &operator=(const String &s)"<<std::endl;
	auto tmp=alloc.allocate(s.size());
	auto dest=tmp;
	auto p=s.begin;
	auto i=0;
	for(;i!=s.size();++i)
		alloc.construct(dest++,*p++);
	free();
	begin=tmp;
	end=tmp+i;
	return *this;
}
String::~String(){
	free();
}


//--------------------------------private function-----------------------------
void String::construction(const char *c,size_t sz){
#ifndef NDEBUG
	std::cout<<"sz="<<sz<<std::endl;
#endif
	auto newdata=alloc.allocate(sz);
	auto dest=newdata;
	auto p=c;
	for(int i=0;i!=sz;++i)
		alloc.construct(dest++,*p++);
	begin=newdata;
	end=newdata+sz;
}
size_t String::getSize(const char *c){
#ifndef NDEBUG
	std::cout<<"in getSize()"<<std::endl;
#endif
	size_t sz=0;
	auto p=c;
	while(isprint(*p++)){++sz;

#ifndef NDEBUG
	std::cout<<"*p="<<*p<<std::endl;
	std::cout<<"sz="<<sz<<std::endl;
#endif
	}
	return sz;
}
void String::free(){
	std::for_each(&begin,&end,[this](char *c){(this->alloc).destroy(c);});
	alloc.deallocate(begin,end-begin);
}


//--------------------------friend function------------------------------
void print(const String &s){
	auto bg=s.begin;
	while(bg!=s.end)
		std::cout<<*bg++;
	std::cout<<std::endl;
}
ostream &operator<<(ostream &strm,const String &str){
	auto bg=str.begin;
	while(bg!=str.end)
		strm<<*str.bg;
	return strm;
}
bool operator==(const String &s1,const String &s2){
	return (s1.begin==s2.begin)&&(s1.end==s2.end);
}
bool operator!=(const String &s1,const String &s2){
	return !(s1==s2);
}
bool operator<(const String &s1,const String &s2){
	size_t i=0;
	auto bg1=s1.begin,bg2=s2.begin;
	while((bg1!=s1.end)&&(bg2!=s2.end)&&(*bg1==*bg2)){
		++bg1;++bg2;
	}
	if((bg2!=s2.end)||(*bg1<*bg2))
		return true;
	return false;
}
