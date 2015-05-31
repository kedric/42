/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:03:20 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/14 18:14:29 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template< typename T>
class Array
{
private:
unsigned int _size;
public:
            Array();
            Array( unsigned int n);
            Array( T const &  Array );
virtual     ~Array();
unsigned int getSize();
void         setSize(unsigned int Nsize);


T & operator[](unsigned int i);

};
