// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 12:26:46 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 12:26:46 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PEON_HPP
# define PEON_HPP

#include <string>
#include <iostream>

class Peon {
	private:
std::string			_name;
	public:
 					~Peon( void  );
 					Peon(std::string);
 					Peon(Peon& in) { *this = in; return; }
Peon&				operator=(Peon const & rhs);
std::string			get_name() const {  return this->_name; }
void				set_name(std::string in) { this->_name = in; return; }
};

std::ostream&	operator<<(std::ostream& o, Peon const & rhs);

#endif
