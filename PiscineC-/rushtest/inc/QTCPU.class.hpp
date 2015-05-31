/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTCPU.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:57:06 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 18:11:19 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QTCPU_CLASS_HPP
# define QTCPU_CLASS_HPP

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


class QTCPU : public QGridLayout, public IMonitorModule{
    private:
                        QTCPU();
            QString _name;

    public:
virtual                ~QTCPU( void  );
                        QTCPU(GetInfo* gi, QString name);
                        QTCPU(QTCPU const & in);
std::string             getName();
void                    setName(QString const & newName);
QTCPU&           operator=(QTCPU const & in);
};



#endif
