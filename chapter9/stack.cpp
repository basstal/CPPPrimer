#include<stack>
#include<string>
#include<iostream>
#include<cstdlib>
using namespace::std;
double calculate(stack<double> &s,char c);
double top_p(stack<double> &s);
int main(){
	stack<double> num;
	stack<char> oprt;
	string nums("1234567890");

	string expr;
	cin>>expr;
	size_t pos=0,prev;
	oprt.push('#');
	while(pos!=expr.size()){
		if(isdigit(expr[pos])){
			prev=pos;
			pos = expr.find_first_not_of(nums,pos);
			string n(expr,prev,pos-prev);
			prev=pos+1;
			num.push(atof(n.c_str()));
#ifndef NDEBUG
			cout<<"input "<<n<<" into stack<double>"<<endl;
#endif
			continue;
		}
		else{
			switch(expr[pos]){
			case '(':oprt.push(expr[pos]);
#ifndef NDEBUG
				cout<<"input "<<expr[pos]<<" into stack<char>"<<endl;
#endif
				break;
			case '+':
			case '-':
				while(oprt.top()!='#'&&oprt.top()!='('&&num.size()>1){
					num.push(calculate(num,oprt.top()));
					oprt.pop();
				}
				oprt.push(expr[pos]);
#ifndef NDEBUG
				cout<<"input "<<expr[pos]<<" into stack<char>"<<endl;
				cout<<"now stack<char> top is "<<oprt.top()<<endl;
				cout<<"now stack<double> top is "<<num.top()<<endl;
#endif
				break;
			case '*':
			case '/':
				while((oprt.top()=='*'||oprt.top()=='/')&&num.size()>1){
					num.push(calculate(num,oprt.top()));
					oprt.pop();
				}
				oprt.push(expr[pos]);
#ifndef NDEBUG
				cout<<"input "<<expr[pos]<<" into stack<char>"<<endl;
				cout<<"now stack<char> top is "<<oprt.top()<<endl;
				cout<<"now stack<double> top is "<<num.top()<<endl;
#endif
				break;
			case ')':
				while(oprt.top()!='('&&num.size()>1){
					num.push(calculate(num,oprt.top()));
					oprt.pop();
				}
				oprt.pop();
				break;
			default:
				while(oprt.top()!='#'){
					num.push(calculate(num,oprt.top()));
					oprt.pop();
				}
				cout<<num.top()<<endl;
				return 0;
			}
		}
		++pos;
	}
	while(oprt.top()!='#'){
		num.push(calculate(num,oprt.top()));
		oprt.pop();
	}
	cout<<num.top()<<endl;
	return 0;
}
					

double calculate(stack<double> &s,char c){
	double a,b;
	switch(c){
	case '*':a=top_p(s);
		b=top_p(s);
		return a*b;
	case '/':a=top_p(s);
		b=top_p(s);
		return b/a;
	case '+':a=top_p(s);
		b=top_p(s);
		return a+b;
	case '-':a=top_p(s);
		b=top_p(s);
		return b-a;
	default:cerr<<"wrong operator!where comes the "<<c<<endl;
		return -1;
	}
}

double top_p(stack<double> &s){
	double tmp=s.top();
	s.pop();
#ifndef NDEBUG
	cout<<"return value tmp is "<<tmp<<endl;
#endif
	return tmp;
}