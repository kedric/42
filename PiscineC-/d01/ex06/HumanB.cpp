/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:13:23 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 18:52:48 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"
# include <iostream>

HumanB::HumanB(std::string name) : _name(name){

}

HumanB::~HumanB(void){

}

void	HumanB::setWeapon(Weapon& club){
	this->_Weapon = &club;
}
void	HumanB::attack(void){
	std::cout << this->_name << " attacks with his " << this->_Weapon->getType() << std::endl;
}
