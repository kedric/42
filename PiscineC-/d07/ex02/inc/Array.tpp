/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:04:41 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/14 18:12:59 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template< typename T>
class Array
{
private:
unsigned int    _size;
T *             _data;
public:
            Array() : _size(0){
              this->_data = new T[0];
            };
            Array( unsigned int n) : _size(n) {
              this->_data = new T[n];
            };
            Array( Array<T> const &  en ) { *this = en; };
virtual     ~Array() { delete[] this->_data; } ;
unsigned int getSize(){ return this->_size; };
void         setSize(unsigned int Nsize) { this->size = Nsize; };
T &         operator=(Array<T> const & en) { *this = en; } ;


T & operator[](unsigned int i){
        if(i <= this->_size)
            return this->_data[i];
        else{
            throw std::out_of_range("out of Range");
        }
        return *(this->_data + (sizeof(T) * i));
};
};
