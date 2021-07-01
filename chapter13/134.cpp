#include "Point.h"

#include <iostream>

Point global;

Point foo_bar(Point arg);
int main(void) {

	Point p;
	std::cout << "begin to count " << std::endl;
	foo_bar(p);

	return 0;
}


Point foo_bar(Point arg) {
	Point local = arg, *heap = new Point(global);
	*heap = local;
	Point pa[4] = { local, *heap };
	return *heap;

}