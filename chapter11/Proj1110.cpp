#include"head.h"
int main(){
	map<vector<int>::iterator,int> myMap;
	//map<list<int>::iterator,int> myMap1;ԭ��:list�ĵ�������˫�������,���ṩ<����;
	vector<int> vec = {1,3,5,5,6,234,43};
	list<int> list = {324,5,45,3,545,345};
	for(auto i = vec.begin();i!=vec.end();++i){
		myMap[i] = *i;
	}
	//for(auto i = list.begin();i!=list.end();++i){
	//	myMap1[i] = *i;
	//}
	return 0;
}