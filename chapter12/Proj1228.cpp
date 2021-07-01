#include"head.h"
int main(){
	ifstream ifs("F:\\string.txt");

	vector<string> fileLineCopy;
	map<string,set<int>> wordMap;
	string line,word;
	int lineNumber=0;
	getline(ifs,line);
	do{
		istringstream iss(line);
		fileLineCopy.push_back(line);
		while(iss >> word){
			wordMap[word].insert(lineNumber);
		}
		++lineNumber;
	}while(getline(ifs,line));

	string searchStr;
	do{
		cout<< "Please input the string you want to search(q to quit" <<endl;
		cin >> searchStr;
		if(searchStr == "q")
			break;
		cout << "The string " << searchStr <<" shows in"<<endl;
		auto fd = wordMap.find(searchStr);
		if(fd == wordMap.end()){
			cout <<"The string you input didn't find" <<endl;
		}else{
			for(auto num :fd->second){
				cout << "Line "<< num <<"  " << fileLineCopy[num] <<endl;
			}
		}
	}while(true);
	return 0;
}