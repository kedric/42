// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//    Zombie.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Zombie.hpp"
#include <iostream>
#include <ctime>


std::string		Zombie::get_type(void) { return (this->_type); };
void			Zombie::set_type(std::string in) { this->_type = in; };
std::string		Zombie::get_name(void) { return (this->_name); };
void			Zombie::set_name(std::string in) { this->_name = in; };

Zombie::Zombie() {
	return;
}

Zombie::Zombie(std::string name, std::string type) : _type(type), _name(name) {
	return;
}

Zombie::~Zombie() {
	return;
}

void		Zombie::announce(void) {
	std::cout << "<" + this->get_name() + " (" + this->get_type() + ")> Braiiiiiiinnnssss..." << std::endl;

	return;
}

