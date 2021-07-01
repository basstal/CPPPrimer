
#include <iostream>
#include <string>
#include <map>
#include <functional>
int add(int n,int m)
{
	return n+m;
}

auto mod = [](int n,int m)
{
	return n%m;
};

class divide
{
public:
	int operator()(int n,int m)
	{
		return n/m;
	}
};


//std::map<std::string,std::function<int(int,int)>> binops =
//{
//	{"+",add},
//	{"-",std::minus<int>()},
//	{"*",[](int m,int n){return m*n;}},
//	{"/",divide()},
//	{"%",mod}
//};

//! the map
//
//Proj1444.cpp:32:1: error: could not convert '{{"+", add}, {"-", std::minus<int>(
//)}, {"*", <lambda closure object>__lambda1{}}, {"/", divide()}, {"%", mod}}' fro
//m '<brace-enclosed initializer list>' to 'std::map<std::basic_string<char>, std:
//:function<int(int, int)> >'
// };
std::map<std::string, std::function<int(int, int)>>  binops =
{
    {"+", add},                                 //  function pointer
    {"-", std::minus<int>()},                   //  library functor
    {"/", divide()},                            //  user-defined functor
    {"*", [] (int i, int j) { return i*j; }},   //  unnamed lambda
    {"%", mod}                                  //  named lambda object
};


int main()
{
    while(true)
    {
        std::cout << "\npleasr enter: num operator num :\n";
        int n1 , n2;    std::string s;
        std::cin >> n1 >> s >> n2;

        std::cout << binops[s] (n1, n2);
    }

    return 0;
}



