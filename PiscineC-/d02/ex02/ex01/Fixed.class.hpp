// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed{
	public:
				Fixed(void);
				Fixed(int);
				Fixed(float);
				~Fixed(void);
				Fixed(Fixed const & toCopy);
int				getRawBits(void) const;
void			setRawBits(int const raw);
int				getFractionalBits(void) const;
int				toInt(void) const;
float			toFloat(void) const;
Fixed&			operator=(Fixed const & rhs);

	private:
const int				_fractionalBits;
int						_RawBits;

};

std::ostream&	operator<<(std::ostream& o, Fixed const& b);
#endif
