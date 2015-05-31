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

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:
	public:
					~ScavTrap( void  );
					ScavTrap( std::string name  );
					ScavTrap(ScavTrap& in) { *this = in; return; }
	ScavTrap&		operator=(ScavTrap& rhs);
	int				challengeNewcomer(std::string const & target);
};

#endif
