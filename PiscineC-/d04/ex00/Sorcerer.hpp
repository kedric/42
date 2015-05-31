// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 12:13:43 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 12:13:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
# define SORCERER_HPP
#include <string>
#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
	private:
std::string		_name;
std::string		_title;
	public:
 				~Sorcerer( void  );
 				Sorcerer( std::string name, std::string title );
 				Sorcerer(Sorcerer& in) { *this = in; return; }
void			polymorph(Victim const & );
void			polymorph(Peon const & );
Sorcerer&		operator=(Sorcerer const &  rhs);
std::string		get_name() const {  return this->_name; }
void			set_name(std::string in) { this->_name = in; return; }
std::string		get_title() const {  return this->_title; }
void			set_title(std::string in) { this->_title = in; return; }
};

std::ostream&	operator<<(std::ostream& o, Sorcerer const & rhs);
#endif
