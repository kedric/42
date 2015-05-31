// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:05:00 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 15:05:00 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include <string>
#include <iostream>

class ScavTrap {

	private:
	int				_Hp;
	int				_Max_hp;
	int				_Energy;
	int				_Max_energy;
	int				_Level;
	std::string		_Name;
	int				_Melee;
	int				_Ranged;
	int				_Armor;

	public:
					~ScavTrap( void  );
					ScavTrap( std::string name  );
					ScavTrap( void );
					ScavTrap(ScavTrap& in) { *this = in; return; }
	ScavTrap&		operator=(ScavTrap& rhs);
	int				rangedAttack(std::string const & target);
	int				meleeAttack(std::string const & target);
	int				takeDamage(unsigned int amount);
	int				beRepaired(unsigned int amount);
	int				challengeNewcomer(std::string const & target);
	int				get_Hp() { return this->_Hp; }
	void			set_Hp(int in) { this->_Hp = in; return; }
	int				get_Max_hp() { return this->_Max_hp; }
	void			set_Max_hp(int in) { this->_Max_hp = in; return; }
	int				get_Energy() { return this->_Energy; }
	void			set_Energy(int in) { this->_Energy = in; return; }
	int				get_Max_energy() { return this->_Max_energy; }
	void			set_Max_energy(int in) { this->_Max_energy = in; return; }
	int				get_Level() { return this->_Level; }
	void			set_Level(int in) { this->_Level = in; return; }
	std::string		get_Name() { return this->_Name; }
	void			set_Name(std::string in) { this->_Name = in; return; }
	int				get_Melee() { return this->_Melee; }
	void			set_Melee(int in) { this->_Melee = in; return; }
	int				get_Ranged() {  return this->_Ranged; }
	void			set_Ranged(int in) { this->_Ranged = in; return; }
	int 			get_Armor() {  return this->_Armor; }
	void			set_Armor(int in) { this->_Armor = in; return; }
};

#endif
