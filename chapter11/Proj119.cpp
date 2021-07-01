#include"head.h"
int main(){
	map<string,list<int>> myMap;
	string word,line;
	size_t lineNum=0;
	ifstream ifs("F:\\string.txt");
	while(getline(ifs,line)){
		++lineNum;
		istringstream iss(line);
		while(iss >> word){
			myMap[word].push_back(lineNum);
		}
	}
	for(auto &w : myMap["are"] )
		cout << w <<" ";
	cout<<endl;
	return 0;
}