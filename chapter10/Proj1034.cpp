#include"head.h"


int main(){
	vector<string> vec{"jkasdjf","gfjdh","fdjkgh","fghd","gkfl","ghfdkl","hgfkdj","ghfdjk","dfgkjh","fgjlkjdfg"};
	for(auto rev_iter = vec.rbegin();rev_iter != vec.rend();++rev_iter){
		cout << *rev_iter<<endl;
	}
	for(auto iter = vec.end()-1;iter!=vec.begin()-1;--iter){
		cout << *iter <<endl;
	}
	return 0;
}