/*
 * Proj636.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<string>
using namespace::std;
string (&func())[10];
typedef string string_arr[10];
//using string_arr = string [10];
string_arr *func0();
auto func1()->string (&)[10];
decltype(string_arr) *func2();



