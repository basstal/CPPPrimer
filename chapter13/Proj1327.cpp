class HasPtr{
	friend void swap(HasPtr &,HasPtr &);
public:
	HasPtr(const string &s = string()):str(new string(s)),i(0),use(new std::size_t(1)){}
	HasPtr(const HasPtr & hp):str(hp.str),use(hp.use),i(hp.i) {++*use;}
	HasPtr & operator=(const HasPtr &);
	bool operator<(const HasPtr &);
	~HasPtr();
private:
	std::string * str;
	size_t * use;
	int i;
};
bool HasPtr::operator <(const HasPtr & hp){
	return (*str).size() < (*hp.str).size();
}
void swap(HasPtr &a,HasPtr &b){
	using std::swap;
	cout << "swapping "<<endl;
	swap(a.str,b.str);
	swap(a.use,b.use);
	swap(a.i,b.i);
}
HasPtr & HasPtr::operator =(const HasPtr & hp){
	++*hp.use;
	if(--*use == 0){
		delete str;
		delete use;
	}
	str = hp.str;
	i = hp.i;
	use = hp.use;
	return *this;
}
HasPtr::~HasPtr(){
	if(--*use == 0){
		delete use;
		delete str;
	}
}