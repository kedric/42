// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 12:25:41 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 12:25:41 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"

Victim::~Victim( void  ) {
	std::cout << "Victim " << this->get_name() << " just died for no apparent reason !" << std::endl;
	return;
};

Victim::Victim(std::string name) : _name(name){
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
	return;
};
std::ostream&	operator<<(std::ostream& o, Victim const & rhs) {
	std::cout << "I'm " << rhs.get_name() << " and i like otters !" << std::endl;
	return o;
};

Victim&		Victim::operator=(Victim const & rhs) {
	this->set_name(rhs.get_name());
	return *this;
};
