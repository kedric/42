/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:44:25 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 16:09:58 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <string>
# include <iostream>
# include <exception>

template<typename T>
typename T::iterator      easyfind(T & obj, int search){
    typename T::iterator it;
    typename T::iterator ite= obj.end();

    for(it = obj.begin(); it != ite; it++){
        if (*it == search)
            return (it);
    }
    throw std::exception();
};


#endif
