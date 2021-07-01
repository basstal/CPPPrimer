#include<iostream>
#include<vector>
using namespace::std;
int main()
{
	/*int ia[10]={1,3,5,7,9};
	int ib[10]={2,4,6,8,10};
	int ea[10]={1,3,5,7,9};
	size_t i;
	for(i=0;i!=10;++i)
		if(ia[i]!=ea[i])
		{
			cout<<"不相等";
			break;
		}
	if(i==10)
		cout<<"相等";
	cout<<endl;*/

	vector<int> ia(10,25),ib(10,7),ea(10,25);
	if(ia==ea)
		cout<<"相等";
	else 
		cout<<"不相等";
	cout<<endl;

		
	
	return 0;
}
