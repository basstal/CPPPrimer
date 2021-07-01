#include"head.h"


int main(){
	int n=5;
	bool flg;
	auto lambda=[&n]()->bool{return (--n!=0)?false:true;};
	while(false == (flg=lambda()))
		cout<<n<<" false"<<endl;
	cout<<n<<" true"<<endl;
	return 0;
}