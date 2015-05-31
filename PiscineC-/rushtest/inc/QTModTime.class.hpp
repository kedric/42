/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTModTime.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:57:06 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 20:15:36 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QTMODETIME_CLASS_HPP
# define QTMODETIME_CLASS_HPP

#include <string>
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include "../inc/GetInfo.class.hpp"
#include "../inc/IMonitorModule.class.hpp"
#include "../inc/QTtheard.class.hpp"



class QTModTime : public QGridLayout, public IMonitorModule{
    private:
        std::string _time;
                        QTModTime();
            QString _name;

    public:
virtual                ~QTModTime( void  );
                        QTModTime(GetInfo* gi, QString name);
                        QTModTime(QTModTime const & in);
void                    refresh(QString newTime);
std::string                 getName();
void                    setName(QString const & newName);
QTModTime&           operator=(QTModTime const & in);
};



#endif

