#pragma once

#include<string>
#include<iostream>
class HasPtr {
public:

	//copy constructor
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &);


	//copy-assignment operator
	HasPtr &operator=(const HasPtr &);


	//destructor
	~HasPtr() { std::cout << "destructor" << std::endl; }
private:
	std::string *ps;
	int i;

};

//类内部可以访问类的非公有private成员
HasPtr::HasPtr(const HasPtr &hp):ps(new std::string(*hp.ps)),i(hp.i) {}

HasPtr &HasPtr::operator=(const HasPtr &hp) {
	ps = new std::string(*hp.ps);
	i = hp.i;
	return *this;
}