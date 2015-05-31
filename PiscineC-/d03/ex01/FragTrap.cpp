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
	srand(time(NULL));
	return;
};

FragTrap::FragTrap(std::string name) : _Hp(100), _Max_hp(100), _Energy(100), _Max_energy(100),_Level(1), _Name(name), _Melee(30), _Ranged(20), _Armor(5){
	std::cout << "FR4G-TP  :: String Constructor" <<std::endl;
	srand(time(NULL));
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

int				FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP  :: "  << this->get_Name() << " attacks " << target
	<< " at range and causing " <<  this->get_Ranged() << " points of damage !" << std::endl;
	return this->get_Ranged();
};

int				FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP  :: "  << this->get_Name() << " attacks " << target
	<< " at melee and causing " << this->get_Melee() << " points of damage !" << std::endl;
	return this->get_Melee();
};

int				FragTrap::takeDamage(unsigned int amount) {
	int damage = 0;
	if(static_cast<int>(amount - this->get_Armor()) > this->get_Hp()) {
		damage = this->get_Hp();
		this->set_Hp(0);
	} else {
		this->set_Hp(this->get_Hp() - amount);
		damage = amount - this->get_Armor();
	}
	std::cout << "FR4G-TP  :: "  << this->get_Name() << "Receve" << damage << "points of damage !" << std::endl;
	return damage;
};

int				FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FR4G-TP  :: " << this->get_Name() << "Repaire" <<  amount << "points !" << std::endl;
	int hp;
	hp = (this->get_Hp() + amount < 100) ? this->get_Hp() + amount : 100;
	return 0;
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
