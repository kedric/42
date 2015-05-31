/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 14:19:43 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 16:10:33 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <iostream>

int        main(void){
    std::vector<int> a(60,0);

    for (int i = 0; i < 60; ++i)
    {
        a[i] = i;
    }
    try {
        std::cout << *easyfind(a, 25) << std::endl;
        std::cout << *easyfind(a, 14) << std::endl;
        std::cout << *easyfind(a, 5) << std::endl;
        std::cout << *easyfind(a, 1255) << std::endl;
        std::cout << *easyfind(a, 256) << std::endl;
    } catch (std::exception const & e){
        std::cout << e.what() << std::endl;
    }

};

