#include"head.h"
void process(shared_ptr<int> ptr);
int main(){
	auto p = new int(100);
	auto sp = make_shared<int>();//Ĭ�ϳ�ʼ����ֵδ֪
	process(sp);
	/*process(new int(100));
	process(p);*///int *���Ͳ���ת����shared_ptr<int>
	process(shared_ptr<int>(p));
	return 0;
}
void process(shared_ptr<int> ptr){
}