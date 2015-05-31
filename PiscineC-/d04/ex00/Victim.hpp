// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 12:25:41 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 12:25:41 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <string>
#include <iostream>

class Victim {
	private:
std::string		_name;
	public:
 				~Victim( void  );
 				Victim(std::string name);
 				Victim(Victim& in) { *this = in; return; }
Victim&			operator=(Victim const & rhs);
std::string		get_name() const {  return this->_name; }
void			set_name(std::string in) { this->_name = in; return; }
};

std::ostream&	operator<<(std::ostream& o, Victim const & rhs);
#endif
