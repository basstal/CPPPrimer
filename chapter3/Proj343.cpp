#include<iostream>

using namespace::std;
using int_array=int[4];
int main()
{
	int ia[3][4]={
		{1,3,5},
		{2,4,6},
		{7,8,9}
	};
	

	/*for(int (&iw)[4]:ia)
	{
		for(int &n:iw)
			cout<<n<<" ";
		cout<<endl;
	}*/

	/*for(size_t w=0;w!=3;++w)
	{
		for(size_t n=0;n!=4;++n)
			cout<<ia[w][n]<<" ";
		cout<<endl;
	}*/

	for(int_array *w=ia;w!=ia+3;++w)
	{
		for(int *n=*w;n!=*w+4;++n)
			cout<<*n<<" ";
		cout<<endl;
	}
	return 0;
}
