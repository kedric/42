// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   map.class.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:54:30 by jmancero          #+#    #+#             //
//   Updated: 2015/01/10 16:54:30 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_CLASS_HPP
# define MAP_CLASS_HPP

#include <string>
#include <iostream>

class map {
	private:
std::string**		_map;
	public:
				~map( void );
				map( void );
				map(map& in) { *this = in; return; }
map&			operator=(map& rhs);
std::string		_getCase(int x, int y);
void			_setCase(int x, int y, std::string to);
void			moveObject();
std::string		getMapString();

};

#endif
