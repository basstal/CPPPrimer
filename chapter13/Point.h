#pragma once

#include <iostream>

class Point {
public:
	Point() = default;
	Point(const Point &);

private:
	int i=0;
};

Point::Point(const Point &p):i(p.i){
	std::cout << "copy construct !" << std::endl;
	
}