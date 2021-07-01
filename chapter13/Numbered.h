#include<cstdlib>
#include<iostream>
class Numbered;
void f(const Numbered &s);
//void f(Numbered s);
class Numbered{
	friend void f(const Numbered &s);
	//friend void f(Numbered s);
public:
	Numbered();
	Numbered(const Numbered &);
private:
	double mysn;
};
Numbered::Numbered(){
	mysn = rand();
}
Numbered::Numbered(const Numbered &num){
	mysn = rand();
}
void f(const Numbered &s){
	std::cout<<s.mysn<<std::endl;
}
//void f(Numbered s){
//	std::cout<<s.mysn<<std::endl;
//}