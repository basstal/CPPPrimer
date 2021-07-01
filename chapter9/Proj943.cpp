#include"include.h"
void replace(string &s,const string &oldVal,const string &newVal);
int main(){
	string s("fire out of range of iiithouytutyuy");
	cout << s <<endl;
	replace(s,"of","crizy");
	replace(s,"tho","though");
	cout << s;
	return 0;
}

//void replace(string &s,const string &oldVal,const string &newVal){
//	auto begin=s.begin(),replace=begin;
//	auto cobegin=oldVal.cbegin();
//	while(begin!=s.end()){
//		replace=begin;
//		cobegin=oldVal.cbegin();
//		while(*begin==*cobegin&&cobegin!=oldVal.cend()){++begin;++cobegin;}
//		if(cobegin==oldVal.cend()){
//			replace=s.erase(replace,begin);
//			auto ds=replace-s.begin();
//			s.insert(replace,newVal.cbegin(),newVal.cend());
//			begin=s.begin()+ds+newVal.size();
//			continue;
//		}
//		begin=replace+1;
//	}
//}


//void replace(string &s,const string &oldVal,const string &newVal){
//	size_t oval=oldVal.size(),pos=0;
//	string cmp=s.substr(pos,oval);
//	while(pos!=s.size()){
//		if(cmp==oldVal){
//			s.replace(pos,oval,newVal);
//			pos+=newVal.size();
//		}else{
//			++pos;
//		}
//		cmp=s.substr(pos,oval);
//	}
//}
	