// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"
#include <iostream>
Pony::Pony(std::string name, std::string color) : _name(name) , _color(color) {
	std::cout << "Construct Pony " << "name : " + this->get_name() << " Color : " + this->get_color() << std::endl;
	return;
}

Pony::~Pony() {
	std::cout << "destroy pony" << std::endl;
	return;
}

bool	Pony::eat(void) {
	this->set_have_eat(true);
	std::cout << this->get_name() + " have eat" << std::endl;
	return (this->get_have_eat());
}

bool	Pony::get_have_eat(void) { return (this->_have_eat); };
std::string	Pony::get_name(void) { return (this->_name); };
std::string	Pony::get_color(void) { return (this->_color); };

void	Pony::set_have_eat(bool in) { this->_have_eat = in;};
