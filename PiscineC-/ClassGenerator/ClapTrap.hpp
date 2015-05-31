// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 02:55:29 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 02:55:29 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class FragTrap {
	private:
int				_Hp;
int				_Max_hp;
int				_Energy;
int				_Max_energy;
int				_Level;
std::string		_Name;
std::string		_Melee;
std::string		_Ranged;
std::string		_Armor;
	public:
 				~FragTrap( void  );
 				FragTrap( void  );
 				FragTrap(FragTrap& in) { *this = in; return; }
FragTrap&		operator=(FragTrap& rhs);
 				~ClassName2( void  );
 				ClassName2( void  );
 				ClassName2(ClassName2& in) { *this = in; return; }
ClassName2&		operator=(ClassName2& rhs);
int				rangedAttack(std::string const & target);
int				meleeAttack(std::string const & target);
int				meleeAttack(unsigned int amount);
int				beRepaired(unsigned int amount);
int				get_Hp() {  return this->_Hp; }
void				set_Hp(int in) { this->_Hp = in; return; }
int				get_Max_hp() {  return this->_Max_hp; }
void				set_Max_hp(int in) { this->_Max_hp = in; return; }
int				get_Energy() {  return this->_Energy; }
void				set_Energy(int in) { this->_Energy = in; return; }
int				get_Max_energy() {  return this->_Max_energy; }
void				set_Max_energy(int in) { this->_Max_energy = in; return; }
int				get_Level() {  return this->_Level; }
void				set_Level(int in) { this->_Level = in; return; }
std::string		get_Name() {  return this->_Name; }
void				set_Name(std::string in) { this->_Name = in; return; }
std::string		get_Melee() {  return this->_Melee; }
void				set_Melee(std::string in) { this->_Melee = in; return; }
std::string		get_Ranged() {  return this->_Ranged; }
void				set_Ranged(std::string in) { this->_Ranged = in; return; }
std::string		get_Armor() {  return this->_Armor; }
void				set_Armor(std::string in) { this->_Armor = in; return; }
};

#endif