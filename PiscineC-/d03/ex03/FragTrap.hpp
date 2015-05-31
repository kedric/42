// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 15:05:00 by jmancero          #+#    #+#             //
//   Updated: 2015/01/08 15:05:00 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	private:

	public:
					~FragTrap( void  );
					FragTrap( std::string name );
					FragTrap(FragTrap& in) { *this = in; return; }
	FragTrap&		operator=(FragTrap& rhs);
	int				vaulthunter_dot_exe(std::string const & target);

};

#endif
