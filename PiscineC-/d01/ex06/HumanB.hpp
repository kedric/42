/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:13:40 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 18:52:03 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string);
		~HumanB(void);
void	attack();
void	setWeapon(Weapon& club);

	private:
std::string	_name;
Weapon*		_Weapon;
};

#endif
