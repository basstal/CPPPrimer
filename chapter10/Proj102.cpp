#include"head.h"
int main(){
	list<string> lis{"jsdhfiu","sdghkjdh","jdkfsghdfk","ghfdjk"};
	cout << count(lis.begin(),lis.end(),"ccc")<<endl;
	return 0;
}