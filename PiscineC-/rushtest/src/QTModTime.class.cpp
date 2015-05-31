/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTModTime.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:56:47 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 20:31:11 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/QTModTime.class.hpp"

QTModTime::~QTModTime(void){

};
QTModTime::QTModTime(GetInfo* gi, QString name) : QGridLayout(){
    this->_name = name;

    std::string tmp = "Time : ";
    QLabel *header  = new QLabel(name + " :");

    this->_time = gi->getTime();
    QLabel *lable_time = new QLabel(this->_time.c_str());
    this->addWidget(header, 0,0);
    this->addWidget(lable_time, 1,0);
    QTthread *t = new QTthread();
    connect(t, SIGNAL(resultReady(QString)), lable_time, SLOT(setText(QString)));
    t->start();

};
QTModTime::QTModTime(QTModTime const & in){
    (void)in;
    return;
};

std::string QTModTime::getName( ) {
    return this->_name.toStdString();
}

void QTModTime::refresh(QString newTime){
    std::cout << "newTime"<< newTime.toStdString() << std::endl;
}
void QTModTime::setName(QString const & newName){
    this->_name = newName;
}

QTModTime&          QTModTime::operator=(QTModTime const & in){
    (void)in;
    return(*this);
};
