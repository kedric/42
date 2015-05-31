/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:08:05 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 18:53:42 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon& Weapon);
		~HumanA(void);
void	attack(void);


	private:
Weapon*		_Weapon;
std::string	_name;

};

#endif
