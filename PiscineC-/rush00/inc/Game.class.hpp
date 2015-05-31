// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:06:13 by jmancero          #+#    #+#             //
//   Updated: 2015/01/10 17:06:13 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include <string>
# include <iostream>
# include "MyNcurse.class.hpp"


class Game {
	private:
		int			_row;
		int			_col;
		bool		_finish;
		MyNcurse 	_io;

	public:
					~Game( void  );
					Game( void  );
					Game(Game& in) { *this = in; return; }
int					getNbRow() { return this->_row; };
void				setNbRow(int row) { this->_row = row; };
int					getNbCol() { return this->_col; };
void				setNbCol(int col) { this->_col = col; };

void				gameStart();
void				gameStop() { this->_finish = true; };
std::string			getString();
Game&				operator=(Game const & rhs);
};


#endif