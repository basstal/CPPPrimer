#include<iostream>
#include<stdexcept>
using namespace::std;
int main()
{
	int ia,ib;
	
	cin>>ia>>ib;
	try{	
		if(ib==0)
			throw runtime_error("除数为0!");
		cout<<ia/ib<<endl;
	}catch(runtime_error err){
		cout<<err.what()<<endl;
	}
	
	return 0;
}
