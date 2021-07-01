#include<string>
#include<cctype>
#include<iostream>
using namespace::std;
int main()
{	
	string str;
	size_t i=0;
	int aCnt=0,eCnt=0,iCnt=0,oCnt=0,uCnt=0,Cnt=0;
	int kg=0,zb=0,hh=0,ff=0,fi=0,fl=0;
	getline(cin,str);
	while(i!=str.size()){
		switch(toupper(str[i++])){
		case 'A':++aCnt;
			break;
		case 'E':++eCnt;
			break;
		case 'I':++iCnt;
			break;
		case 'O':++oCnt;
			break;
		case 'U':++uCnt;
			break;
		case ' ':++kg;
			break;
		case '\t':++zb;
			break;
		case '\n':++hh;
			break;
		case 'F':
			switch(toupper(str[i])){
			case 'F':++ff;
				break;
			case 'L':++fl;
				break;
			case 'I':++fi;
				break;
			}
		default:++Cnt;
		}
	}
	cout <<"aCnt = "<<aCnt <<endl;
	cout<< "eCnt = "<<eCnt<<endl;
	cout <<"iCnt=" <<iCnt<<endl;
	cout <<"oCnt="<<oCnt<<endl;
	cout <<"uCnt="<<uCnt<<endl;
  	cout<<"Cnt="<<Cnt<<endl;
	return 0;
}
