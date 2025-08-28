#include <iostream>

//creating a contract when used has to provide implementation the function inside
class AbstractCars {
	//when a dev sees this class he/she/them/pizza will understand there is a method for this and doesn't worry about how it is implemented
	virtual void haveASteeringWheel() = 0;

};
class electricCars:AbstractCars {
public:
	std::string wheels;
	std::string electricEngine;
	void haveASteeringWheel() {
		std::cout << "Steering wheel added!";
	}
};

int main() {
	electricCars tesla;
	tesla.haveASteeringWheel();

	return 0;
}