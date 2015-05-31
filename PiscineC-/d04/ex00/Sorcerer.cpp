// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 12:18:54 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 12:18:54 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"

Sorcerer::~Sorcerer( void  ) {
	std::cout << this->get_name() << ", " << this->get_title()
	<< ", is dead. Consequences will never be the same !" << std::endl;
	return;
};

Sorcerer::Sorcerer( std::string name, std::string title ) : _name(name), _title(title){
	std::cout << this->get_name() << ", "<< this->get_title() << ", is born !"<< std::endl;
	return;
};

Sorcerer&		Sorcerer::operator=(Sorcerer const & rhs) {
	this->set_name(rhs.get_name());
	this->set_title(rhs.get_title());
	return *this;
};

std::ostream&	operator<<(std::ostream& o, Sorcerer const & rhs){
	std::cout << "I am "<<  rhs.get_name() << ", " <<
	rhs.get_title() << ", and I like ponies !" << std::endl;
	return o;
};


void				Sorcerer::polymorph(Victim const & V) {
	std::cout << V.get_name() << " has been turned into a cute little sheep !" << std::endl;

	return;
};

void				Sorcerer::polymorph(Peon const & P) {
	std::cout << P.get_name() << " has been turned into a pink pony !" << std::endl;
	std::cout << "Bleuark..." << std::endl;
	return;
};

