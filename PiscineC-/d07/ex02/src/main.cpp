/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:04:41 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/14 19:08:07 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "../inc/Array.tpp"

int main(){
    Array<int> b(6);
    b[1] = 56;
    std::cout << b[1] << std::endl;
    try {
        std::cout << b[56] << std::endl;
    } catch (std::exception const & e) {
        std::cout << e.what() << std::endl;
    }
}
