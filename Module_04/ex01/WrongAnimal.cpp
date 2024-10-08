#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = assign.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal noise" << std::endl;
}
