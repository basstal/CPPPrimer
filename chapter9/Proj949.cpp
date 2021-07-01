#include"include.h"

int main(){
	string cender("tilkjhfdbqypjg");
	int pos,count;
	ifstream file("F:\\string.txt");
	if(!file.is_open()){
		cout << "open file failed!" <<endl;
	}
	string word,lword;
	while(file >> word){
		pos=0;
		count = word.size();
		while((pos = word.find_first_of(cender,pos))!=string::npos){
			--count;++pos;
		}
		if(count==word.size()&&count > lword.size())
			lword = word;
	}
	
	cout <<lword<<endl;
	return 0;
}