/*
 * Proj723.cpp
 *
 *  Created on: 2015-1-10
 *      Author: basstal
 */
#include<string>
#include<iostream>
#include<vector>
using namespace::std;
class Screen;
class Window_mgr{
private:
	std::vector<Screen> screens;
public:
	void clear(int);
	Window_mgr &add(const Screen &);
	Screen show(int)const;
};

class Screen{
	friend void Window_mgr::clear(int);
private:
	int width=0,height=0;
	int cursor=0;
	std::string contents;
public:
	Screen()=default;
	Screen(int wid,int hgt,char ch):width(wid),height(hgt),contents(wid*hgt,ch){}
	Screen(int wid,int hgt):Screen(wid,hgt,' '){}
	
	char get()const{
		return contents[cursor];
	}//读取光标处的字符
	inline char get(int wd,int ht)const;//读取指定宽和高处字符
	Screen &move(int r,int c);//光标移动到指定位置
	Screen &set(char );//设置屏幕字符
	Screen &display(std::ostream &ostrm);//打印屏幕中所有字符
};
inline Screen &Screen::move(int r,int c){
	cursor=width*r+c;
	return *this;
}
inline Screen &Screen::set(char c){
	contents[cursor]=c;
	return *this;
}
inline Screen &Screen::display(std::ostream &ostrm){
	ostrm<<contents;
	return *this;
}
inline void Window_mgr::clear(int i){
	Screen &s=screens[i];
	s.contents=string(s.height*s.width,' ');//为什么自动补全功能不显示private数据成员，clear为友元；
}
Window_mgr &Window_mgr::add(const Screen &s){
	screens.push_back(s);
	return *this;
}
Screen Window_mgr::show(int i)const{
	return screens[i];//注意多个类的情况下，类成员函数定义的位置
}
int main(){
	Screen myScreen(5,5,'X');
	myScreen.move(4,0).set('#').display(std::cout);
	std::cout<<"\n";
	myScreen.display(std::cout);
	std::cout<<"\n";
	Window_mgr myWindows;
	myWindows.add(Screen(24,80,'!')).add(Screen(30,72,'@')).add(Screen(30,80,'$')).add(Screen(25,50,'#'));
	myWindows.clear(3);
	myWindows.show(2).display(std::cout);
	return 0;
}



