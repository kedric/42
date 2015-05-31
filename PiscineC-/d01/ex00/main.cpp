/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:22:22 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 13:53:38 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

void ponyOnTheStack(void){
	std::cout << "enter ponyOnTheStack" << std::endl;
	Pony p("pilon", "Red");
	std::cout << "p.eat()" << std::endl;
	p.eat();
}

void ponyOnTheHeap(void){
	std::cout << "enter ponyOnTheHeap" << std::endl;
	Pony *p = new Pony("poppy", "yello");
	std::cout << "p->eat()" << std::endl;
	p->eat();
	delete p;
}

int main(){
	ponyOnTheHeap();
	ponyOnTheStack();
}
