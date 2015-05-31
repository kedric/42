/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTCPU.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:56:47 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 20:54:28 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/QTCPU.class.hpp"
 #include <QProgressBar>
#include "../inc/QTtheard2.class.hpp"

QTCPU::~QTCPU(void){

};
QTCPU::QTCPU(GetInfo* gi, QString name) : QGridLayout(){
    this->_name = name;

    QString tmp = "CPU :";
    QLabel *header  = new QLabel(tmp);
    std::map<std::string,float> cpuInfo = gi->getCpuUsage();

    tmp = "User : ";
    QProgressBar *lable_Cpu = new QProgressBar();
    lable_Cpu->setValue(cpuInfo["cpu_user"]);

    tmp = "Sys : " + QString::number(cpuInfo["cpu_sys"]);
    QProgressBar *lable_Sys = new QProgressBar();
    lable_Sys->setValue(cpuInfo["cpu_sys"]);

    tmp = "Idle : " + QString::number(cpuInfo["cpu_idle"]);
    QProgressBar *lable_Idle = new QProgressBar();
    lable_Idle->setValue(cpuInfo["cpu_idle"]);

    this->addWidget(header, 0,0);
    this->addWidget(lable_Cpu, 1,0);
    this->addWidget(lable_Sys, 2,0);
    this->addWidget(lable_Idle, 3,0);
    QTthread2 *t2 = new QTthread2();
    t2->setGi(gi);
    connect(t2, SIGNAL(resultUser(int)), lable_Cpu, SLOT(setValue(int)));
    connect(t2, SIGNAL(resultSys(int)), lable_Sys, SLOT(setValue(int)));
    connect(t2, SIGNAL(resultIdle(int)), lable_Idle, SLOT(setValue(int)));
    t2->start();


};
QTCPU::QTCPU(QTCPU const & in){
    (void)in;
};

std::string QTCPU::getName(){
    return this->_name.toStdString();
}
void QTCPU::setName(QString const & newName){
    this->_name = newName;
}

QTCPU&          QTCPU::operator=(QTCPU const & in){
    (void)in;
    return(*this);
};
