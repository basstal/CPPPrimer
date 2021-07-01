#include<iostream>
#include<vector>

using namespace::std;
int main()
{
	vector<int> v1,v2;
	v1={1,3,5,7,9};
	v2={1,3,5,7,9,53,4,7,1,15};
	bool fg=true;
	vector<int> &s=v1>v2?v2:v1,&b=v1>v2?v1:v2;
	
	for(auto sp=s.begin(),bp=b.begin();sp!=s.end();++sp,++bp)
		if(*sp!=*bp)
		{
			fg=false;
			break;
		}
	cout<<(fg?"true":"false")<<endl;
	return 0;
}
	
