// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MyNcurse.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:06:13 by jmancero          #+#    #+#             //
//   Updated: 2015/01/10 17:06:13 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MYNCURSE_CLASS_HPP
# define MYNCURSE_CLASS_HPP
#include "object.h"

#include <string>
#include <iostream>
#include <ncurses.h>
#include <cstdio>

class MyNcurse {
	private:
		int _row;
		int _col;
		int _Prow;
		int _Pcol;
		Object object[60];

	public:
 				~MyNcurse( void  );
 				MyNcurse( void  );
 				MyNcurse(MyNcurse& in) { *this = in; return; }
bool			mvPrintw(int row, int col, std::string str);
void			refreshAll();
std::string		getEntry();
void			printTime();
void			PrintPlayer();
bool			movePlayer(int );
void			Move(int, int, int, int, char);
int				getNbRow() { return this->_row; };
int				getPRow() { return this->_Prow; };
void			setNbRow(int row) { this->_row = row; };
void			setPRow(int row) { this->_Prow = row; };
int				getNbCol() { return this->_col; };
int				getPCol() { return this->_Pcol; };
void			setNbCol(int col) { this->_col = col; };
void			setPCol(int col) { this->_Pcol = col; };
bool			NewBullet() ;
MyNcurse&		operator<<(std::string& rhs);
MyNcurse&		operator=(MyNcurse& rhs);

};

#endif
