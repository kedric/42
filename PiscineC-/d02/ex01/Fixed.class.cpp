// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.class.hpp"
#include <cmath>

Fixed::Fixed(void) : _fractionalBits(8) , _RawBits(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const& src) : _fractionalBits(src.getFractionalBits()) {
	std::cout << "Copy constructor called" << std::endl;
	this->_RawBits = src.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(int nb) : _fractionalBits(8) {
	std::cout << "Int constructor called" << std::endl;
	this->_RawBits = (float)nb * pow(2, this->getFractionalBits());


	return;
}

Fixed::Fixed(float nb): _fractionalBits(8) {
	std::cout << "Float constructor called" << std::endl;
	float tmp = nb * pow(2, this->getFractionalBits());
	this->_RawBits = roundf(tmp);
	return;
}

int		Fixed::getFractionalBits(void) const {
	return (this->_fractionalBits);
};

int		Fixed::getRawBits(void) const {
	return (this->_RawBits);
}

Fixed&			Fixed::operator=(Fixed const & rhs){
	std::cout << "Assignation operator called" << std::endl;
	this->_RawBits = rhs.getRawBits();
	return(*this);
};

std::ostream& operator<<(std::ostream& o, Fixed const& b){
	o << b.getRawBits() / pow(2, b.getFractionalBits());
	return (o);
};

int		Fixed::toInt(void) const {
	return (roundf(this->_RawBits / pow(2, this->getFractionalBits())));
};

float	Fixed::toFloat(void) const {
	return(roundf(this->_RawBits / pow(2, this->getFractionalBits())));
};

void	Fixed::setRawBits(int const raw) {
	this->_RawBits = raw;
	return;
};
