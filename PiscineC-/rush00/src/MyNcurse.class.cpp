// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MyNcurse.class.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:06:13 by jmancero          #+#    #+#             //
//   Updated: 2015/01/10 17:06:13 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../inc/MyNcurse.class.hpp"
#include <ctime>

MyNcurse::~MyNcurse( void ) {
	curs_set(1);
	endwin();
	return;
};

MyNcurse::MyNcurse( void ) : _row(0), _col(0), _Prow(0), _Pcol(0){
	WINDOW *win = initscr();
	timeout(100);
	keypad(win, true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, this->_row, this->_col);
	this->_Prow = this->_row - 1;
	this->_Pcol = this->_col/ 2;
	return;
};

void	MyNcurse::refreshAll(){
	this->printTime();
};

bool MyNcurse::mvPrintw(int row, int col, std::string str) {
	mvprintw(row,col,str.c_str());
	return true;
};

void		MyNcurse::PrintPlayer(){
	mvprintw(this->_Prow, this->_Pcol, "^");
	doupdate();
}

void		MyNcurse::Move(int fromRow, int fromCol, int toRow, int toCol, char c){
	mvdelch(fromRow, fromCol);
	refresh();
	this->setPRow(toRow);
	this->setPCol(toCol);
	mvaddch(toRow, toCol, c);
	refresh();

}

bool		MyNcurse::NewBullet(){

	return true;
};

bool		MyNcurse::movePlayer(int key){
	if (key != -1) {
		mvprintw(10,0,"%d", this->getPRow());
		if(KEY_RIGHT == key){
			this->Move(getPRow(), getPCol(), getPRow(), getPCol() + 1, '^');
		}else if (key == KEY_LEFT &&  this->_col > this->getPCol() + 1) {
			this->Move(getPRow(), getPCol(), getPRow(), getPCol() - 1, '^');
		}else if (key == KEY_UP && this->getPRow() > 0) {
			this->Move(getPRow(), getPCol(), getPRow() - 1, getPCol(), '^');
		}else if (key == KEY_DOWN && this->_row > getPRow() + 1){
			this->Move(getPRow(), getPCol(), getPRow() + 1, getPCol(), '^');
		}
	}
	return true;
};

std::string  MyNcurse::getEntry() {
	int key = 0;
	std::string a = "";
	key = getch();

	this->movePlayer(key);
	this->PrintPlayer();
	refresh();
	return a;
};

void MyNcurse::printTime(){
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	std::string tmp = asctime (timeinfo);
	mvprintw(0,getNbCol() - tmp.length(), tmp.c_str());
}


MyNcurse &		MyNcurse::operator=(MyNcurse& rhs)  {
	(void)rhs;
	return rhs;
};

MyNcurse & MyNcurse::operator<<(std::string& rhs) {
	(void)rhs;
	// mvprintw(0,0,rhs.c_str());
	return *this;
}
