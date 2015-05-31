// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 16:58:20 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 16:58:20 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"

virtual			AWeapon::~AWeapon( void  )  {

	return;
};

 				AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _APCost(apcost), _Damage(damage) {

	return;
};

AWeapon&			AWeapon::operator=(AWeapon const & rhs)  {
	*this = rhs;
	return *this;
};

void		AWeapon::attack() const {

};
