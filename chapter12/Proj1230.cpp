#include"TextQuery.h"
void runQueries(ifstream &input);
ostream &print(ostream &ostrm,const QueryResult qrst);
int main(){
	ifstream input("F:\\string.txt");
	runQueries(input);
	return 0;
}

void runQueries(ifstream &input){
	TextQuery tq(input);
	while(true){
		cout << "enter word to look for, or q to quit\n";
		string s;
		if(!(cin >>s) || s == "q") break;
		print(cout,tq.query(s));
	}
}
