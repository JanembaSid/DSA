#include <iostream>

class Person {
	//Data hiding
private:
	std::string Name;
	std::string purposeInLife;

public:
	//Getter and setter functions
	std::string getName() {
		return Name;
	}

	void setName(std::string name) {
		Name = name;
	}

	std::string getPurpose() {
		return purposeInLife;
	}

	void setPurpose(std::string purpose) {
		purposeInLife = purpose;
	}

	Person(std::string name,std::string purpose) {
		Name = name;
		purposeInLife = purpose;
	}
};

int main() {
	Person p1("Sidhesh","Eat donuts");
	std::cout << p1.getPurpose() << std::endl;
	std::cout << p1.getName() << std::endl;

	p1.setName("Aadhyyanth");
	p1.setPurpose("Eat Sidhi's donuts");

	std::cout << p1.getPurpose() << std::endl;
	std::cout << p1.getName() << std::endl;
	return 0;
}