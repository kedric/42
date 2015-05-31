// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* ptrStr = &str;
	std::string& refStr = str;

	std::cout << *ptrStr << std::endl;
	std::cout << refStr << std::endl;

	return (0);
}
