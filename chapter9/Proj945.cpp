#include"include.h"
string fullName(string & name,const string &suffix,const string &prefix);
int main(){
	string src="jun ";
	string my=fullName(src,"ke ","Wang ");
	cout<<my<<endl;
	return 0;
}


//string fullName(string & name,const string &suffix,const string &prefix){
//	name.insert(name.begin(),prefix.cbegin(),prefix.cend());
//	name.append(suffix);
//	return name;
//}

string fullName(string & name,const string &suffix,const string &prefix){
	size_t pos=0;
	name.insert(pos,prefix);
	pos+=name.size();
	name.insert(pos,suffix);
	return name;
}