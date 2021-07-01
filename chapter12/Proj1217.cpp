#include"head.h"
int main(){
	int ix =1024,*pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//IntP p0(ix);//invalid conversion from 'int' to 'std::unique_ptr<int>::pointer...
	IntP p1(pi);
	p1.reset();
	IntP p2(pi2);
	IntP p3(&ix);
	p3.reset();
	IntP p4(new int(2048));
	//IntP p5(p2.get());//可能有后续错误,不使用get()初始化另一个智能指针;
	cout<<*p2<<endl;
	cout<<*p4<<endl;

	return 0;
}