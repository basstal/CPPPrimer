#include<string>
using namespace::std;
int main()
{
	string sa="hello world!";
	string sb="hollo world!";
	char ca[]="hello world!";
	char cb[]="hello world!";
	
	if(sa==sb)
		cout<<"equal!";
	else
		cout<<"not equal!";
	char *pa,*pb;
	pa=ca;pb=cb;
	while(pa!=end(ca)&&pb!=end(cb)
	{
		if(*pa!=*pb)
		{
			cout<<"not equal!";
			break;
		}
		++pa;++pb;
	}
	

	return 0;
}
