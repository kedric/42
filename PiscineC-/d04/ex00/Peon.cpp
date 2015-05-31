// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 12:26:46 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 12:26:46 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"

Peon::~Peon( void  ) {
	std::cout << "Victim " << this->get_name() << " just died for no apparent reason !" << std::endl;
	return;
};

Peon::Peon(std::string name) : _name(name){
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
	std::cout << "Zog zog."<< std::endl;
	return;
};

Peon&		Peon::operator=(Peon const & rhs) {
	this->set_name(rhs.get_name());
	return *this;
};

std::ostream&	operator<<(std::ostream& o, Peon const & rhs){
	std::cout << "I'm "<<  rhs.get_name() << " and i like otters !"  << std::endl;
	return o;
};
