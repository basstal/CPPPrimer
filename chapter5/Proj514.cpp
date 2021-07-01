#include<string>
#include<iostream>

using namespace::std;
int main()
{
	string s,prv,m;
	size_t cnt=1,max=1;

	while(cin>>s)
	{
		if(prv.empty())
		{
			prv=s;
			continue;
		}
		if(prv==s)
		{
			cnt++;
			if(cnt>max)
			{
				m=s;
				max=cnt;
			}
		}
		else
			cnt=1;
		prv=s;
	}
	cout<<"出现次数最多的单词是"<<m<<"出现了"<<max<<"次"<<endl;
	return 0;	
}
