/*
 * Proj753.cpp
 *
 *  Created on: 2015-1-10
 *      Author: basstal
 */
#include<iostream>
class Debug{
private:
	bool hw;
	bool io;
	bool other;
public:
	constexpr Debug(bool b=true):hw(b),io(b),other(b){}
	constexpr Debug(bool h,bool i,bool o):hw(h),io(i),other(o){}
	constexpr bool any(){return hw||io||other;}

	void setHw(bool hw) {
		this->hw = hw;
	}

	void setIo(bool io) {
		this->io = io;
	}

	void setOther(bool other) {
		this->other = other;
	}

};
int main(){
	constexpr Debug io_sub(false,true,false);
	if(io_sub.any())
		std::cerr<<"print appropriate error messages"<<std::endl;
	constexpr Debug prod(false);
	if(prod.any())
		std::cerr<<"print an error message"<<std::endl;
}


