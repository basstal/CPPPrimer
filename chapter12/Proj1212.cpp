#include"head.h"
void process(shared_ptr<int> ptr);
int main(){
	auto p = new int(100);
	auto sp = make_shared<int>();//默认初始化，值未知
	process(sp);
	/*process(new int(100));
	process(p);*///int *类型不能转换成shared_ptr<int>
	process(shared_ptr<int>(p));
	return 0;
}
void process(shared_ptr<int> ptr){
}