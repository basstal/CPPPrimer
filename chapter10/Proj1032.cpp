#include"head.h"
#include"Sales_item.h"

int main(){
	ifstream fstrm("F:\\book.txt");
	if(!fstrm.is_open())
		cout<<"open file failed!"<<endl;
	string line;
	vector<Sales_item> v_si;
	
	while(getline(fstrm,line)){
		istringstream sstrm(line);
		Sales_item si(sstrm);
		v_si.push_back(si);
	}
	
	sort(v_si.begin(),v_si.end(),compareIsbn);
	auto bg=v_si.begin(),ed=v_si.begin();
#ifndef NDEBUG
	cout<<"ready to loop!"<<endl;
#endif
	while(bg!=v_si.end()){
		Sales_item sum;
		auto fd = bg;
		cout<<*bg<<endl;
		ed = find_if(fd,v_si.end(),[fd](const Sales_item &si){
			return si.getIsbn()!=fd->getIsbn();});
		sum = accumulate(bg,ed,sum);
		bg=ed;
		cout<<sum<<endl;
#ifndef	NDEBUG
		
		cout<<"looping"<<endl;
#endif
	}

	return 0;
}