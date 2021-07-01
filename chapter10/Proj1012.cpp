#include"Sales_item.h"
#include"head.h"

int main(){
	vector<Sales_item> v{Sales_item("TheRing",3,25),Sales_item("TheLord",4,23),Sales_item("UnitBook",2,28)};
	stable_sort(v.begin(),v.end(),[](const Sales_item &s1,const Sales_item &s2){return s1.getIsbn()>s2.getIsbn();});
	for(const auto &e:v)
		cout<<e<<endl;
	return 0;
}