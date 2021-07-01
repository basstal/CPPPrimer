#include"include.h"
class Proj951{
	friend void print(ostream &strm,const Proj951 & proj);//友元函数必须指明变量名
private:
	unsigned year=0,month=0,day=0;
	vector<string> month_a{"January","February","March","April","May","June","July","August","September","October","November","December"},
		month_b{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
public:
	Proj951(const string &date);
};
Proj951::Proj951(const string &date){
	istringstream sstrm(date);
	string w;
	size_t pos=0,bg=0,tm=0;
	sstrm>>w;
	while((pos = w.find_first_of("/",pos))!=string::npos){
		switch(tm++){
		case 0:
			month=atoi(w.substr(bg).c_str());break;
		case 1:
			day=atoi(w.substr(bg).c_str());break;
		default:;
		}
		++pos;
		bg=pos;
	}
	if(tm==2)
		year=atoi(w.substr(bg).c_str());

	for(int i=0;i!=12;++i)
		if(month_a[i]==w){
			month=i+1;
			break;
		}
	for(int i=0;i!=12;++i)
		if(month_b[i]==w){
			month=i+1;
			break;
		}
	if(day==0){
		sstrm>>w;
		day=atoi(w.c_str());
	}
	if(year==0){
		sstrm>>w;
		year=atoi(w.c_str());
	}
}
void print(ostream &strm,const Proj951 & proj){
	strm<<proj.month<<"/"<<proj.day<<"/"<<proj.year<<endl;
}
int main(){
	Proj951 newDate1("January 1, 1900");
	Proj951 newDate2("1/1/1990");
	Proj951 newDate3("Jan 1 1990");
	print(cout,newDate1);
	print(cout,newDate2);
	print(cout,newDate3);
	return 0;
}
	
