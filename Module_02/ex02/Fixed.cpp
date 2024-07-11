#include "Fixed.hpp"


//Module02 ex00

Fixed::Fixed() : fixedPointNumber_(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointNumber_ = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointNumber_);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	fixedPointNumber_ = raw;
}


//Module02 ex01

/* Function overload (a form of ad-hoc polymorphism): same function declared
multiple times with different parameters (e.g. int and float) */

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber_ = (value << Fixed::fractionalBits_);
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber_ = roundf(value * (1 << Fixed::fractionalBits_));
}

int	Fixed::toInt() const {
	return (this->fixedPointNumber_ >> Fixed::fractionalBits_);
}

float	Fixed::toFloat() const {
	return ((float)this->fixedPointNumber_ / (float)(1 << Fixed::fractionalBits_));
}

std::ostream &operator<<(std::ostream &floatingRepresentation, Fixed const &fixedNumber){
	return (floatingRepresentation << fixedNumber.toFloat());
}


//Module02 ex02

bool	Fixed::operator>(Fixed const &fixed) const {
	return (this->fixedPointNumber_  > fixed.fixedPointNumber_ );
}

bool	Fixed::operator<(Fixed const &fixed) const {
	return (this->fixedPointNumber_  < fixed.fixedPointNumber_ );
}

bool	Fixed::operator>=(Fixed const &fixed) const {
	return (this->fixedPointNumber_  >= fixed.fixedPointNumber_ );
}

bool	Fixed::operator<=(Fixed const &fixed) const {
	return (this->fixedPointNumber_  <= fixed.fixedPointNumber_ );
}

bool	Fixed::operator==(Fixed const &fixed) const {
	return (this->fixedPointNumber_  == fixed.fixedPointNumber_ );
}

bool	Fixed::operator!=(Fixed const &fixed) const {
	return (this->fixedPointNumber_  != fixed.fixedPointNumber_ );
}

Fixed	Fixed::operator+(Fixed const &fixed){
	Fixed result;
	result.setRawBits(this->fixedPointNumber_ + fixed.fixedPointNumber_);
	return (result);
}

Fixed	Fixed::operator-(Fixed const &fixed){
	Fixed result;
	result.setRawBits(this->fixedPointNumber_ - fixed.fixedPointNumber_);
	return (result);
}

Fixed	Fixed::operator*(Fixed const &fixed){
	Fixed result;
	result.fixedPointNumber_ = (this->toFloat() * fixed.toFloat()) * (1 << fractionalBits_);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &fixed){
	if (fixed.toFloat() == 0){
		std::cerr << "Error: division by zero undefined, returning input" << std::endl;
		return *this;
	}
	Fixed result;
	result.fixedPointNumber_ = (this->toFloat() / fixed.toFloat()) * (1 << fractionalBits_);
	return (result);
}

Fixed	Fixed::operator++(){
	this->fixedPointNumber_++;
	return (*this);
}

Fixed	Fixed::operator--(){
	this->fixedPointNumber_--;
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed	tmp(*this); //copy current state
	++(*this); //use pre-increment
	return (tmp);
}

Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	--(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return b;
}
