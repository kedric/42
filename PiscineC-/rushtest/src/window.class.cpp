/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 23:02:20 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 21:39:54 by akazian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/window.class.hpp"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include <QDebug>


void     WinQT::addModules(QGridLayout*  in){
    this->_layout->addLayout(in,0 ,this->_nb_module);
    this->_nb_module++;
};

void WinQT::addHostname(){
    QThostname *tmp = new QThostname(this->_gi, "HostName");
    this->addModules(tmp);
};
void WinQT::addCpu(){
    QTCPU *tmp = new QTCPU(this->_gi, "CPU");
    this->addModules(tmp);
};
void WinQT::addTime(){
    QTModTime *tmp = new QTModTime(this->_gi, "Time");
    this->addModules(tmp);
};

void WinQT::parseArgs(int argc,char** argv){
    std::string tmp;
    for(int i = 1; i < argc; i++){
        tmp = argv[i];
        if(tmp == "hostname")
            this->addHostname();
        if (tmp == "cpu")
          this->addCpu();
        if (tmp == "time")
            this->addTime();
    }
};

WinQT::~WinQT(){};

WinQT::WinQT(int argc,char** argv, GetInfo * GI)
{
    this->_gi = GI;
    this->_nb_module = 0;
    this->_app = new QApplication(argc, argv);
    this->_fenetre = new QWidget();
    this->_layout = new QGridLayout;

    this->parseArgs(argc,argv);

}

int WinQT::run()
{
    this->_fenetre->setLayout(this->_layout);
    this->_fenetre->show();

    return this->_app->exec();
}
