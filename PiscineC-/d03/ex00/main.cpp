/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:41:26 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/08 21:11:24 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(){
	FragTrap player1("the virgine");
	FragTrap player2(player1);

	player2 = player1;

	player1.vaulthunter_dot_exe("mouton");
	player2.takeDamage(25);
	return 0;
};
