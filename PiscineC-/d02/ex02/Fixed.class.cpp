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
#include <cstdio>
#include <cmath>

Fixed::Fixed(void) : _fractionalBits(8) , _RawBits(0){
	return;
}

Fixed::Fixed(Fixed const& src) : _fractionalBits(8) {
	this->_RawBits = src.getRawBits();
}

Fixed::~Fixed(void) {
	return;
}

Fixed::Fixed(int nb) : _fractionalBits(8) {
	this->_RawBits = (float)nb * pow(2, this->_fractionalBits);
	return;
}

Fixed::Fixed(float nb): _fractionalBits(8) {
	float tmp = nb * pow(2, this->_fractionalBits);
	this->_RawBits = roundf(tmp);
	return;
}

int		Fixed::getFractionalBits(void) const {
	return (this->_fractionalBits);
};

int		Fixed::getRawBits(void) const {
	return (this->_RawBits);
}

std::ostream&	operator<<(std::ostream& o, Fixed const& b){
	o << b.getRawBits() / pow(2, b.getFractionalBits());
	return (o);
};

int		Fixed::toInt(void) const {
	return (roundf(this->_RawBits / pow(2, this->_fractionalBits)));
};

float	Fixed::toFloat(void) const {
	return(this->_RawBits / pow(2, this->_fractionalBits));
};

void	Fixed::setRawBits(int const raw) {
	this->_RawBits = raw;
	return;
};

Fixed&			Fixed::operator=(Fixed const & rhs){
	this->_RawBits = rhs.getRawBits();
	return(*this);

};

Fixed			Fixed::operator+(const Fixed& rhs) {
	float tmp = this->toFloat() + rhs.toFloat();
	return (Fixed(tmp));
};

Fixed			Fixed::operator-( const Fixed& rhs) {
	float tmp = this->toFloat() - rhs.toFloat();
	return (Fixed(tmp));
};

Fixed			Fixed::operator*( const Fixed& rhs) {
	float tmp = this->toFloat() * rhs.toFloat();
	return (Fixed(tmp));
};

Fixed			Fixed::operator/( const Fixed& rhs) {
	float tmp = this->toFloat() / rhs.toFloat();
	return (Fixed(tmp));
};

bool			Fixed::operator<( const Fixed& rhs){
	return (this->toFloat() < rhs.toFloat());
};

bool			Fixed::operator>(const Fixed& rhs){
	return (this->toFloat() > rhs.toFloat());
};

bool			Fixed::operator>=( const Fixed& rhs){
	return (this->toFloat() >= rhs.toFloat());
};

bool			Fixed::operator<=(const Fixed& rhs){
	return (this->toFloat() <= rhs.toFloat());
};

bool			Fixed::operator==(const Fixed& rhs){
	return (this->toFloat() == rhs.toFloat());
};

bool			Fixed::operator!=(const Fixed& rhs){
	return (this->toFloat() != rhs.toFloat());
};

Fixed			Fixed::operator++(int a){
	Fixed ret(*this);
	this->_RawBits++;
	a = 0;
	return (ret);
};

Fixed&			Fixed::operator++(void) {
	int tmp = this->getRawBits();
	tmp++;
	this->setRawBits(tmp);
	return (*this);
};

Fixed			Fixed::operator--(int a){
	Fixed ret(*this);
	this->_RawBits--;
	a = 0;
	return (ret);
};

Fixed&			Fixed::operator--(void) {
	int tmp = this->getRawBits();
	tmp--;
	this->setRawBits(tmp);
	return (*this);
};

const Fixed&			Fixed::max(Fixed const & a, Fixed const & b){
	return (a.getRawBits() >  b.getRawBits()) ? a : b;
};
const Fixed&			Fixed::min(Fixed const & a, Fixed const & b){
	return (a.getRawBits() <  b.getRawBits()) ? a : b;
};

