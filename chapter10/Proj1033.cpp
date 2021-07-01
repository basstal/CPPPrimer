#include"head.h"
void read(const string &input_File,const string &output_File1,const string &output_File2);
int main(){
	read("F:\\int.txt","F:\\odds.txt","F:\\evens.txt");
	return 0;
}

void read(const string &input_File,const string &output_File1,const string &output_File2){
	ifstream ifs(input_File);
	istream_iterator<int> is_iter(ifs),eof;
	ofstream ofs1(output_File1);
	ofstream ofs2(output_File2);
	ostream_iterator<int> os_iter1(ofs1," ");
	ostream_iterator<int> os_iter2(ofs2," ");

	while(is_iter!=eof){
		if((*is_iter) % 2 == 0)
			os_iter2 = *is_iter;
		else
			os_iter1 = *is_iter;
		++is_iter;
	}
}