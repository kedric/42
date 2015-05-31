/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesEngine.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazian <akazian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:38:03 by akazian           #+#    #+#             */
/*   Updated: 2015/01/18 22:05:31 by akazian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/CursesEngine.class.hpp"
#include "../inc/GetInfo.class.hpp"
#include <ncurses.h>
#include <string.h>
#include <list>
#include <iostream>
#include <stdlib.h>

CursesEngine::CursesEngine(){}
CursesEngine::CursesEngine(std::list<std::string> arg){
	initscr();	/* start curses*/
	raw();		/* disabled line buffering */
	int	size = 2;
	std::list<std::string>::iterator it = arg.begin();
	std::list<std::string>::iterator ite = arg.end();
	for (; it != ite ; it++){
		if (*it == "HostName"){
			this->modules["HostName"] = newwin(4, 98, size,2);
			box(this->modules["HostName"], 1, 1);
			size += 4;
		}
		else if (*it == "CPU") {
			this->modules["CPU"] = newwin(5, 98, size, 2);
			box(this->modules["CPU"], 1, 1);
			size += 5;
		}
		else if (*it == "Time"){
			this->modules["Time"] = newwin(3, 98, size, 2);
			box(this->modules["Time"], 1, 1);
			size += 3;
		}
		size++;
	}
	this->main = newwin(size,100,1,1);
	mvwprintw(this->main, 0, 2, "q - to quit");
	keypad(this->main, TRUE);
	noecho();
	cbreak();
	curs_set(0);

	/* list color */
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE); /* main win */
	wbkgd(this->main, COLOR_PAIR(1));
	wrefresh(this->main);
}
CursesEngine::CursesEngine(CursesEngine const & src): IMonitorDisplay(){
	*this = src;
}

CursesEngine::~CursesEngine(){
	delwin(this->modules["HostName"]);
	delwin(this->modules["CPU"]);
	delwin(this->modules["Time"]);
	delwin(this->main);
	endwin();
}

int	CursesEngine::run(){
	timeout(0);
	int ch = getch();
	if (ch == 'q')
		return 0;
	wbkgd(this->main, COLOR_PAIR(1));
	wrefresh(this->main);
	if (this->modules["HostName"]){
		this->updateHost(this->modules["HostName"]);
	}
	if (this->modules["Time"]){
		this->updateTime(this->modules["Time"]);
	}
	if (this->modules["CPU"]){
		this->updateCpu(this->modules["CPU"]);
	}

	return 1;	
}

void	CursesEngine::updateHost(WINDOW *win){
	GetInfo GI;
	mvwprintw(win, 1, 1, GI.getHostName().c_str());
	mvwprintw(win, 2, 1, GI.getUserName().c_str());
	box(win, 1, 1);
	wrefresh(win);
}
void	CursesEngine::updateCpu(WINDOW *win){
	GetInfo GI;
   	std::map<std::string,float>ret = GI.getCpuUsage();
	int user = ret["cpu_user"] / 2;
	for (int i = 1; i < user + 1; i++) {
		mvwprintw(win, 1, i, "#");
	}
	int sys = ret["cpu_sys"] / 2;
	for (int i = 1; i < sys + 1; i++){
		mvwprintw(win, 2, i, "#");
	}
	int idle = ret["cpu_idle"] / 2;
	for (int i = 1; i < idle + 1; i++){
		mvwprintw(win, 3, i, "#");
		box(win, 1, 1);
	}
	wrefresh(win);
}
void	CursesEngine::updateTime(WINDOW *win){
	GetInfo GI;
	mvwprintw(win, 1, 1, GI.getTime().c_str());
	box(win, 1, 1);
	wrefresh(win);
}

/* Operator */
CursesEngine & CursesEngine::operator=(CursesEngine const & src){
	this->main = src.main;
	return *this;
}
