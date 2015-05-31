/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:07:42 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 18:32:34 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
class Weapon {

	public:
					Weapon(std::string);
					~Weapon(void);
const std::string&	getType(void) { return (this->_type); };
void				setType(std::string);

	private:
std::string		_type;
};

#endif
