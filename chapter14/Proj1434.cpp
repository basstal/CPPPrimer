
#include <string>
#include <iostream>
class If_Than_Else
{
public:
	If_Than_Else() = default;
	int operator()(bool b,int p1,int p2)
	{
		return b?p1:p2;
	}

private:

};

int main()
{
	If_Than_Else test;
	std::cout<< test(false,5,10) <<std::endl;

	return 0;

}

