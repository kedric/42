// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:05:00 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 15:05:00 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <ctime>

FragTrap::~FragTrap( void ) {
	std::cout << "FR4G-TP  :: Standard Destructor" <<std::endl;
	return;
};


FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FR4G-TP  :: String Constructor" <<std::endl;
	return;
};

FragTrap&		FragTrap::operator=(FragTrap& rhs) {
	std::cout << "FR4G-TP  :: Egale operator =" <<std::endl;
	this->set_Hp(rhs.get_Hp());
	this->set_Max_hp(rhs.get_Max_hp());
	this->set_Energy(rhs.get_Energy());
	this->set_Max_energy(rhs.get_Max_energy());
	this->set_Level(rhs.get_Level());
	this->set_Name(rhs.get_Name());
	this->set_Melee(rhs.get_Melee());
	this->set_Ranged(rhs.get_Ranged());
	this->set_Armor(rhs.get_Armor());
	return *this;
};

int				FragTrap::vaulthunter_dot_exe(std::string const & target) {
	std::string a[5][2] = {{"fireBall","true"},{"gun","true"},{"stone","false"},{"baton","false"},{"dague","false"}};
	int retRand = rand() % 5;
	if (get_Energy() > 25){
		this->set_Energy(get_Energy() - 25);
		std::cout << "FR4G-TP  :: " << this->get_Name() << " attack " << target << " with " << a[retRand][0] + " " << std::endl;
		if(a[retRand][1] == "true") {
				return this->rangedAttack(target);
		} else {
				return this->meleeAttack(target);
		}
	}
	return 0;
};
