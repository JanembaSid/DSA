#include<iostream>


class Employee {

protected: 
	std::string Name;
	std::string Company;
	int Age{};
public:
	

	void IntroduceYourself() {
		std::cout << "My name is " << Name << " and I work at " << Company;
	}
	Employee(std::string name, std::string company, int age) {
		Name = name;
		Age = age;
		Company = company;
	}

	std::string getName() {
		return Name;
	}

	void setName(std::string name) {
		Name = name;
	}

	std::string getCompany() {
		return Company;
	}

	void setCompany(std::string company) {
		Company = company;
	}

};

class Developer :public Employee {
private:
	std::string favProgrammingLang;

public:
	Developer(std::string name, std::string company, int age,std::string FavProgrammingLang): Employee(name,company,age){
		favProgrammingLang = FavProgrammingLang;
	}

	std::string progLang() {
		return favProgrammingLang;
	}

	void devsFavLang() {
		//std::cout << getName() << "'s favorite programming language is " << progLang() << std::endl; 
		// To access the Name without the getter you have to make the variables in protected instead of private
		std::cout << Name << "'s favorite programming language is " << progLang() << std::endl;
	}

};

int main() {

	Developer dev1 = Developer("Sidhesh", "Nintendo", 24, "C++");
	dev1.devsFavLang();

	//for the sub class to get the parent class methods you have to make the inheritence public --> : public Employee
	dev1.IntroduceYourself();

	return 0;
}
