/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QThostname.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:56:47 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 19:20:26 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/QThostname.class.hpp"

QThostname::~QThostname(void){

};
QThostname::QThostname(GetInfo* gi, QString name) : QGridLayout(){
    this->_name = name;

    std::string tmp = "Host Name : ";
    tmp += gi->getHostName();
    QLabel *lable_name  = new QLabel(tmp.c_str());

    tmp = "username : ";
    tmp += gi->getUserName();
    QLabel *lable_user = new QLabel(tmp.c_str());

    std::map<std::string,std::string> osDict = gi->getOs();
    tmp = "OS Type : " + osDict["os_type"];
    QLabel *lable_os_type = new QLabel(tmp.c_str());
    tmp = "nombre Thread : " + osDict["ncpu"];
    QLabel *lable_os_nbTheard = new QLabel(tmp.c_str());

    this->addWidget(lable_name, 0,0);
    this->addWidget(lable_user, 1,0);
    this->addWidget(lable_os_type, 2,0);
    this->addWidget(lable_os_nbTheard, 3,0);
};
QThostname::QThostname(QThostname const & in){
    (QThostname)in;
};

std::string QThostname::getName(){
    return this->_name.toStdString();
}
void QThostname::setName(QString const & newName){
    this->_name = newName;
}

QThostname&          QThostname::operator=(QThostname const & in){
    (void)in;
    return(*this);
};
