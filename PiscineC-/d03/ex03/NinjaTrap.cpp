// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:05:00 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 15:05:00 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"
#include <ctime>

NinjaTrap::~NinjaTrap( void ) {
	std::cout << "NinjaTrap :: Standard Destructor " <<std::endl;
	return;
};

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name){
	std::cout << "NinjaTrap :: String Constructor" <<std::endl;
	this->set_Hp(60);
	this->set_Max_hp(60);
	this->set_Energy(120);
	this->set_Max_energy(120);
	this->set_Melee(60);
	this->set_Ranged(5);
	this->set_Armor(0);
	return;
};

NinjaTrap&		NinjaTrap::operator=(NinjaTrap& rhs) {
	std::cout << "NinjaTrap :: Egale operator =" <<std::endl;
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

int				NinjaTrap::ninjaShoebox(ClapTrap & enemy) {
	enemy.takeDamage(this->meleeAttack(enemy.get_Name()));
	std::cout << "the ninja attack ClapTrap " + enemy.get_Name() << std::endl;
	return 0;
};

int				NinjaTrap::ninjaShoebox(FragTrap & enemy) {
	enemy.takeDamage(this->meleeAttack(enemy.get_Name()));
	std::cout << "the ninja attack FragTrap " + enemy.get_Name() << std::endl;
	return 0;
};

int				NinjaTrap::ninjaShoebox(ScavTrap & enemy) {
	enemy.takeDamage(this->meleeAttack(enemy.get_Name()));
	std::cout << "the ninja attack ScavTrap " + enemy.get_Name() << std::endl;
	return 0;
};

