/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:41:26 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/08 20:20:17 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(){
	FragTrap player1("the virgine");
	FragTrap player3("player3");
	ScavTrap player4("orge");
	ScavTrap player5("player5");
	ScavTrap player6(player4);

	ClapTrap player7("ClapTrap");

	player3 = player1;
	player4 = player5;

	player3.takeDamage(6);
	player5.takeDamage(30) ;

	player1.vaulthunter_dot_exe("mouton");
	player3.vaulthunter_dot_exe("chat");

	player4.challengeNewcomer("mouton");
	player5.challengeNewcomer("chat");

	return 0;
};
