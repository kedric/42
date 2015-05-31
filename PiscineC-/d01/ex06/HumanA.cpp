/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:07:54 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 18:53:53 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include <iostream>
HumanA::HumanA(std::string name, Weapon& Weapon) :_Weapon(&Weapon), _name(name){

}

HumanA::~HumanA(void){

}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with his " << this->_Weapon->getType() << std::endl;
}
