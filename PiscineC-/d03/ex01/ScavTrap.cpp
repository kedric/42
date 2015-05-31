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
	srand(time(NULL));
	return;
};

ScavTrap::ScavTrap(std::string name) : _Hp(100), _Max_hp(100), _Energy(50), _Max_energy(50), _Level(1), _Name(name), _Melee(20), _Ranged(15), _Armor(3){
	std::cout << "ScavTrap :: String Constructor" <<std::endl;
	srand(time(NULL));
	return;
};

ScavTrap&		ScavTrap::operator=(ScavTrap& rhs) {
	std::cout << "ScavTrap :: Egale operator =" <<std::endl;
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

int				ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "ScavTrap :: "  << this->get_Name() << " attacks " << target
	<< " at range and causing " <<  this->get_Ranged() << " points of damage !" << std::endl;
	return this->get_Ranged();
};

int				ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "ScavTrap :: "  << this->get_Name() << " attacks " << target
	<< " at melee and causing " << this->get_Melee() << " points of damage !" << std::endl;
	return this->get_Melee();
};

int				ScavTrap::takeDamage(unsigned int amount) {
	int damage = 0;
	if(static_cast<int>(amount - this->get_Armor()) > this->get_Hp()) {
		damage = this->get_Hp();
		this->set_Hp(0);
	} else {
		this->set_Hp(this->get_Hp() - amount - this->get_Armor());
		damage = amount - this->get_Armor();
	}
	std::cout << "ScavTrap :: "  << this->get_Name() << "Receve " << damage << " points of damage !" << std::endl;
	return damage;
};

int				ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "ScavTrap :: " << this->get_Name() << "Repaire" <<  amount << "points !" << std::endl;

	return 0;
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
