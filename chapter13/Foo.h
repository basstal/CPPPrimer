#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
class Foo{
public:
	Foo(std::vector<int> v):data(v){}
	Foo sorted() &&;
	Foo sorted() const &;
private:
	std::vector<int> data;
};

Foo Foo::sorted() &&{
	std::cout<<"Foo Foo::sorted() &&"<<std::endl;
	sort(data.begin(),data.end());
	return *this;
}

Foo Foo::sorted() const &{
	std::cout<<"Foo Foo::sorted() const &"<<std::endl;
	//Foo ret(*this);
	/*sort(ret.data.begin(),ret.data.end());*/
	return Foo(*this).sorted();
}