
class Employee {
public:

	Employee();
	Employee(std::string n):name(n){
		id = unique++;
	}
	Employee(const Employee&) = delete;

	Employee &operator=(const Employee &) = delete;
private:
	static int unique = 10;
	std::string name;
	int id;
};