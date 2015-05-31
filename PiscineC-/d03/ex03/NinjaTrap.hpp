// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:05:00 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 15:05:00 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_CLASS_HPP
# define NINJATRAP_CLASS_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

	private:

	public:
					~NinjaTrap( void  );
					NinjaTrap( std::string name );
					NinjaTrap(NinjaTrap& in) { *this = in; return; }
	NinjaTrap&		operator=(NinjaTrap& rhs);
	int				ninjaShoebox(std::string const & target);
	int				ninjaShoebox(ClapTrap & enemy);
	int				ninjaShoebox(FragTrap & enemy);
	int				ninjaShoebox(ScavTrap & enemy);

};

#endif
