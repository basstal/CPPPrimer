#include<algorithm>
#include<stack>
#include<iostream>
#include<deque>


int main()
{
	std::deque<std::size_t> deq = {1,1111,1234,5678,88888,999999};
    std::stack<std::size_t> stk(deq);

	std::multiplies<std::size_t> mul;
	while(!stk.empty())
	{
		std::cout << mul(stk.top(),2) <<"\n";
		stk.pop();
	}
	
	/*std::deque<std::string>
            deq = {"pooh","pooh","pooh","pooh","pooh","alan","pooh","cocos","pooh"};

	std::stack<std::string> stk(deq);

	std::equal_to<std::string> eql;
	while(!stk.empty())
	{
		if(eql(stk.top(),"pooh"))
		{
			stk.pop();
			continue;
		}
		
		break;
	}
	std::cout<< stk.top()<<"\n";*/

	/*
	std::size_t cnt=0;
	std::deque<std::size_t> deq = {1,12,134,1111,55555,999999,111,9999,11};
	std::stack<std::size_t> stk(deq);

	std::greater<std::size_t> grt;

	while(!stk.empty())
	{
		if(grt(stk.top(),1024)) ++cnt;
		stk.pop();
	}
	std::cout<<"cnt = "<<cnt<<"\n";*/

	return 0;
}

