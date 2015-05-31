// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 19:00:28 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 19:00:28 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap  :: Standard Destructor" <<std::endl;
	return;
};

ClapTrap::ClapTrap( void ) {
	return;
};

ClapTrap::ClapTrap(std::string name) : _Hp(100), _Max_hp(100), _Energy(100), _Max_energy(100), _Level(1), _Name(name), _Melee(30), _Ranged(20), _Armor(5){
	std::cout << "ClapTrap  :: String Constructor" <<std::endl;
	return;
};

ClapTrap&		ClapTrap::operator=(ClapTrap& rhs) {
	std::cout << "ClapTrap :: Egale operator =" <<std::endl;
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

int				ClapTrap::rangedAttack(std::string const & target) {
	std::cout << "ClapTrap :: "  << this->get_Name() << " attacks " << target
	<< " at range and causing " <<  this->get_Ranged() << " points of damage !" << std::endl;
	return this->get_Ranged();
};

int				ClapTrap::meleeAttack(std::string const & target) {
	std::cout << "ClapTrap :: "  << this->get_Name() << " attacks " << target
	<< " at melee and causing " << this->get_Melee() << " points of damage !" << std::endl;
	return this->get_Melee();
};

int				ClapTrap::takeDamage(unsigned int amount) {
	int damage = 0;
	if(static_cast<int>(amount - this->get_Armor()) > this->get_Hp()) {
		damage = this->get_Hp();
		this->set_Hp(0);
	} else {
		this->set_Hp(this->get_Hp() - amount - this->get_Armor());
		damage = amount - this->get_Armor();
	}
	std::cout << "ClapTrap :: "  << this->get_Name() << " Receve " << damage << " points of damage !" << std::endl;
	return damage;
};

int				ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap :: " << this->get_Name() << "Repaire" <<  amount << "points !" << std::endl;
	int hp;
	hp = (this->get_Hp() + amount < 100) ? this->get_Hp() + amount : 100;
	return 0;
};
