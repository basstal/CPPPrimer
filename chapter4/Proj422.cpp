
#include<string>
#include<iostream>
using namespace::std;

int main()
{
	string finalGrade;
	int grade;
	cin>>grade;
	/*finalGrade=(grade>60)?((grade>75)?((grade>80)?"high pass":"pass"):"low pass"):"fail";*/

	if(grade>60&&grade<=75)
		finalGrade="low pass";
	if(grade>75&&grade<=80)
		finalGrade="pass";
	if(grade>80)
		finalGrade="high pass";
	if(grade<=60)
		finalGrade="fail";
		
	cout<<finalGrade<<endl;

	return 0;
}
