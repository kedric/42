// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:05:00 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 15:05:00 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap :: Standard Destructor " <<std::endl;
	return;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap :: String Constructor" <<std::endl;
	this->set_Energy(50);
	this->set_Max_energy(50);
	this->set_Melee(20);
	this->set_Ranged(15);
	this->set_Armor(3);
	return;
};

ScavTrap&		ScavTrap::operator=(ScavTrap& rhs) {
	std::cout << "SlapTrap :: Egale operator =" <<std::endl;
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

int				ScavTrap::challengeNewcomer(std::string const & target) {
	std::string a[5][2] = {{"do a gangnam style dance","true"},{"do a somersault ","true"},{"become invisible","false"},{"guess what is in my pocket","false"},{"kiss my ass","false"}};
	int retRand = rand() % 5;
	if (get_Energy() > 25){
		this->set_Energy(get_Energy() - 25);
		std::cout << "ScavTrap :: " << this->get_Name() << " challenge " << target << " with " << a[retRand][0] + " " << std::endl;
		if(a[retRand][1] == "true") {
				return this->rangedAttack(target);
		} else {
				return this->meleeAttack(target);
		}
	}
	return 0;
};
