// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 15:39:21 by jmancero          #+#    #+#             //
//   Updated: 2015/01/09 15:39:21 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include <string>
#include <iostream>

class PlasmaRifle {
	private:
	public:
 				  ~PlasmaRifle( void  );
 				  PlasmaRifle( void  );
 				PlasmaRifle(PlasmaRifle& in) { *this = in; return; }
PlasmaRifle&		  operator=(PlasmaRifle& rhs);
};

#endif