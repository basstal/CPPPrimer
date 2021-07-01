#define _SCL_SECURE_NO_WARNINGS

#include"TextQuery.h"
#include"QueryResult.h"
using std::cin;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main() {
	string infile;
	cout << "filename : ";
	cin >> infile;
	ifstream ifs(infile);
	TextQuery tq(ifs);

	while (true) {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}


	system("pause");
	return 0;
}