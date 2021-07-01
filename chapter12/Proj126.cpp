#include"head.h"
void readVector(vector<int> &vec);
shared_ptr<vector<int>> createVector();
void printVector(const vector<int> &vec);
int main(){

	shared_ptr<vector<int>> vec;
	vec = createVector();
	readVector(*vec);
	printVector(*vec);

	return 0;
}

shared_ptr<vector<int>> createVector(){
	return make_shared<vector<int>>();
}

void readVector(vector<int> &vec){
	int a;
	while(cin >> a){
		vec.push_back(a);
	}
}
void printVector(const vector<int> &vec){
	for(const auto &v : vec)
		cout << v <<" ";
	cout<<endl;
}