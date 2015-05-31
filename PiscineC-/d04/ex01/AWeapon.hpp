// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 16:58:20 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 16:58:20 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>
#include <iostream>

class AWeapon {
	private:
std::string const	_name;
int					_APCost;
int					_Damage;
	public:
virtual				~AWeapon( void  );
 					AWeapon(std::string const & name, int apcost, int damage);
 					AWeapon(AWeapon const & in) { *this = in; return; }
AWeapon&			operator=(AWeapon const & rhs);
std::string const &	get_name() { return this->_name; }
int					getAPCost() {  return this->_APCost; }
int					getDamage() {  return this->_Damage; }
virtual void		attack() const = 0;

};

#endif
