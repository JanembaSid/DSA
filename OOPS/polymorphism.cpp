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
	//default case for all employees - when there is no child class object
	virtual void Work() {
		std::cout << Name << " is working hard!"<<std::endl;
	}

};

class Developer :public Employee {
private:
	std::string favProgrammingLang;

public:
	Developer(std::string name, std::string company, int age, std::string FavProgrammingLang) : Employee(name, company, age) {
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
	using Employee::Work;
	void Work() {
		std::cout << Name << " is coding in " << favProgrammingLang<<std::endl;
	}

};

class Teacher :public Employee {
public:
	std::string Subject;
	Teacher(std::string name, std::string company, int age, std::string subject)
		:Employee(name,company,age)
	{
		Subject = subject;
	}

	void teach() {
		std::cout << Name << " is teaching " << Subject << std::endl;
	}
	using Employee::Work;
	void Work() {
		std::cout << Name << " is catching a Mewtwo right now!"<<std::endl;
	}
};

int main() {

	Developer dev1 = Developer("Sidhesh", "Nintendo", 24, "C++");
	Teacher t1 = Teacher("Professor Oak","Pallet Town",69,"Pokemon");

	/*dev1.devsFavLang();
	t1.teach();*/
	
	// Calling the Work method directly, gives different output based on which sub class the object is based on 
	dev1.Work();
	t1.Work();

	//same thing but now using pointers based off of the parent/super class
	Employee* e1 = &dev1;
	Employee* e2 = &t1;

	//Need to make the function virtual --> so that it will implement the deepest implementation based off the scope or which class the object was most scoped to (most derived class)
	e1->Work();
	e2->Work();
	return 0;
}
