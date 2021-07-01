#include"head.h"
using namespace::std::placeholders;
bool check_size(const string &s,size_t sz);
void biggies(vector<string> &words,vector<string>::size_type sz);
string make_plural(const int cnt,const string &w,const string &ed);
void elimDups(vector<string> & words);
int main(){
	vector<string> words{"fox","jumps","over","quick","red","quick","blow","slow","the","turtle"};
	biggies(words,4);
	return 0;
}


bool check_size(const string &s,size_t sz){
	return s.size()<sz;
}
void biggies(vector<string> &words,vector<string>::size_type sz){
	elimDups(words);
	stable_sort(words.begin(),words.end(),[](const string &s1,const string &s2){return s1.size()>s2.size();});
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
	auto myCheck = bind(check_size,_1,sz);
	auto wc = stable_partition(words.begin(),words.end(),myCheck);
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
	auto count = words.end()-wc;
	cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer "<<endl;
	for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
	cout<<endl;
}



string make_plural(const int cnt,const string &w,const string &ed){
	return (cnt>1)?w+ed:w;
}
void elimDups(vector<string> & words){
	sort(words.begin(),words.end());
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
	auto end_unique = unique(words.begin(),words.end());
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
	words.erase(end_unique,words.end());
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
}