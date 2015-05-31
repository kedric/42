/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 22:57:24 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 21:00:11 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP
#include <QApplication>
#include <QWidget>
#include <QThread>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <list>
#include <ctime>

#include "../inc/QThostname.class.hpp"
#include "../inc/QTCPU.class.hpp"
#include "../inc/IMonitorDisplay.class.hpp"
#include "../inc/QTModTime.class.hpp"


class WinQT : public IMonitorDisplay{
    public:
void                    addModules(QGridLayout*  in);
			WinQT(int,char**, GetInfo *GI);
virtual		~WinQT();
void		parseArgs(int,char**);
int			run();
void		addHostname();
void		addCpu();
void		addTime();

	private:
		GetInfo *_gi;
		int _nb_module;
		QApplication*	_app;
		QGridLayout *	_layout;
		QWidget*		_fenetre;
		QHBoxLayout * test;
						WinQT();
						WinQT(WinQT const & in);
WinQT&				operator=(WinQT const & in);

};

#endif
