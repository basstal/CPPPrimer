#include<string>
#include<iostream>
#include<memory>

class HasPtr{
	friend void swap(HasPtr &,HasPtr &);
	friend void print(const HasPtr &);
	//friend bool oprt_less(const HasPtr &hp1,const HasPtr &hp2);
public:
	HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
	HasPtr(const HasPtr &);
	//HasPtr(HasPtr &&);
	HasPtr &operator=(HasPtr);
	//HasPtr &operator=(HasPtr &&);
	bool operator<(const HasPtr &)const;

	void printStr();
	~HasPtr(){std::cout<<"~HasPtr()"<<std::endl;}
private:
	std::shared_ptr<std::string> ps;
	int i;
};
//HasPtr::HasPtr(HasPtr &&hp):ps(hp.ps),i(hp.i){
//	std::cout<<"HasPtr::HasPtr(HasPtr &&hp)"<<std::endl;
//}
//HasPtr &HasPtr::operator=(HasPtr &&hp){
//	std::cout<<"HasPtr &HasPtr::operator=(HasPtr &&hp)"<<std::endl;
//	if(this!=&hp){
//		ps=hp.ps;
//		i=hp.i;
//	}
//	return *this;
//}
void HasPtr::printStr(){
	std::cout << *ps <<std::endl;
}
HasPtr::HasPtr(const HasPtr &hp):i(hp.i),ps(std::make_shared<std::string>(*hp.ps)){
	std::cout << "HasPtr::HasPtr(const HasPtr &hp)" <<std::endl; 
}
HasPtr &HasPtr::operator=(HasPtr hp){
	std::cout << "HasPtr &HasPtr::operator=(HasPtr hp)"<< std::endl;
	swap(*this,hp);
	return *this;
}
bool HasPtr::operator<(const HasPtr &hp1)const{
	return (*ps).size() < (*hp1.ps).size();
}

//----------------------------------friend function----------------------------------------------
void swap(HasPtr &,HasPtr &);
void print(const HasPtr &);
bool oprt_less(const HasPtr &hp1,const HasPtr &hp2);
void print(const HasPtr &hp){
	std::cout<<" This HasPtr has string -> "<<*hp.ps<<" and i-> "<<hp.i<<std::endl;
}

void swap(HasPtr &a,HasPtr &b){
	using std::swap;
	std::cout<<" swapping "<<std::endl;
	swap(a.ps,b.ps);
	swap(a.i,b.i);
}
//bool oprt_less(const HasPtr &hp1,const HasPtr &hp2){
//	return *hp1.ps<*hp2.ps;
//}