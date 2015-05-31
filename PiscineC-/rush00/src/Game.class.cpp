/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 00:04:42 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/11 00:38:45 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Game.class.hpp"

				Game::~Game( void )   {

	return;
};

				Game::Game( void ) {

	return;
};

void				Game::gameStart() {
	this->_finish = true;
	while(this->_finish){
		this->_io.getEntry();
		this->_io.refreshAll();
	}
	return;
};

std::string		Game::getString() {
	std::string a;
	a += _finish;
	return a;
};


std::ostream&  operator<<(std::ostream& o, Game& g) {
	o << g.getString();
	 return o;
	  }call getCPP

				Game::~Game( void)  {
	
	return;
};

				Game::Game( void)  {
	
	return;
};

void				Game::gameStart()  {
	
	return;
};

std::string		Game::getString()  {
	
	return;
};

Game				Game::operator=( Game const & rhs)  {
	
	return;
};

