#ifndef STRVEC_H
#define STRVEC_H
#include<string>
#include<initializer_list>
#include<memory>
class StrVec {
public:
	typedef std::size_t size_type;

	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec &);
	//StrVec(const StrVec &&)noexcept;
	//StrVec &operator=(StrVec &&)noexcept;
	StrVec & operator=(const StrVec &);
	~StrVec();

	void push_back(const std::string &);
	std::size_t size()const { return first_free - elements; }
	std::size_t capacity() const { return cap - elements; }
	std::string * begin()const { return elements; }
	std::string * end()const { return first_free; }

	void reserve(std::size_t n);

	void resize(std::size_t n);
	void resize(std::size_t n, const std::string &s);
private:
	std::allocator<std::string> alloc;
	void chk_n_alloc() {
		if (size() == capacity())reallocate();
	}
	std::pair<std::string*, std::string *> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string * elements;//指向string数组的头部
	std::string * first_free;//指向string数组的第一个空位置
	std::string * cap;//指向allocate申请的string数组末尾
};


//-------------------public function--------------------------
//StrVec::StrVec(StrVec &&sv) :elements(sv.elements), first_free(sv.first_free), cap(sv.cap)noexcept {
//	sv.elements = sv.first_free = sv.cap = 0;
//}
//StrVec &StrVec::operator=(StrVec &&sv)noexcept {
//	if (this != &sv) {
//		free();
//		elements = sv.elements;
//		first_free = sv.first_free;
//		cap = sv.cap;
//	}
//	sv.elements = sv.first_free = sv.cap = 0;
//	return *this;
//}
StrVec::StrVec(const StrVec & sv) {
	auto newdata = alloc_n_copy(sv.begin(), sv.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(std::initializer_list<std::string> il) {
	auto newdata = alloc.allocate(il.size());
	auto elem = newdata;
	
	for (auto bg = il.begin(); bg != il.end();)
		alloc.construct(elem++, *bg++);
	elements = newdata;
	first_free = cap = elem;
}
StrVec & StrVec::operator =(const StrVec & sv) {
	auto newdata = alloc_n_copy(sv.begin(), sv.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}
StrVec::~StrVec() {
	free();
}
void StrVec::push_back(const std::string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
void StrVec::reserve(std::size_t n) {
	if (n > capacity()) {
		reallocate();
	}
}
void StrVec::resize(std::size_t n) {
	resize(n, std::string());
}
void StrVec::resize(std::size_t n, const std::string &s) {
	auto newdata = alloc.allocate(n);
	auto dest = newdata;
	auto elem = elements;
	if (n <= size())
		for (std::size_t i = 0; i != n; ++i)
			alloc.construct(dest++, std::move(*elem++));
	else {
		std::size_t i = 0;
		for (; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		for (; i != n; ++i) {
			alloc.construct(dest++, std::string(s));
		}
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = newdata + n;
}


//----------------------------private function---------------------------------
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
	auto data = alloc.allocate(e - b);
	return{ data,std::uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}


	//for_each(&elements,&first_free,[](std::string *p){alloc.destroy(p);});
	//alloca.deallocate(elements,cap-elements);
}
void StrVec::reallocate() {
	auto newcap = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements;
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
}

#endif