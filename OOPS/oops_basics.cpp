
#include<iostream>


class Employee {
public:
	std::string Name;
	std::string Company;
	int Age{};

	void IntroduceYourself() {
		std::cout << "My name is " << Name << " and I work at " << Company;
	}
	Employee(std::string name,std::string company, int age) {
		Name = name;
		Age = age;
		Company = company;
	}
};


int main() {

	// Creating an object using default constructor or no constructor

	/*Employee emp1;
	emp1.Name = "Sidhesh";
	emp1.Age = 24;
	emp1.Company = "Nintendo";
	emp1.IntroduceYourself();*/


	// Using the above defined constructor
	Employee emp2 = Employee("Aadhyyanth","NYU Hospital",27);
	emp2.IntroduceYourself();
	return 0;
}
