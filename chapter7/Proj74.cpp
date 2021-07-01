/*
 * Proj74.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<string>
#include<iostream>
class Person{
	friend std::istream &read(std::istream &istrm,Person &ps);
	friend std::ostream &print(std::ostream &ostrm,const Person &ps);
private:
	std::string name;
	std::string address="nowhere";
public:
	Person(const std::string &nm,const std::string &addr):name(nm),address(addr){}
	explicit Person(std::istream &istrm){
		istrm>>name>>address;
	}
	Person(const std::string &nm="noname"):name(nm){}
	std::string getName()const{return name;}
	std::string getAddr()const{return address;}
};
std::istream &read(std::istream &istrm,Person &ps){
	istrm>>ps.name>>ps.address;
	return istrm;
}
std::ostream &print(std::ostream &ostrm,const Person &ps){
	ostrm<<"name "<<ps.name<<",address "<<ps.address;
	return ostrm;
}



