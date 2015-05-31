/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QThostname.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:57:06 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 19:19:40 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QTHOSTNAME_CLASS_HPP
# define QTHOSTNAME_CLASS_HPP

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


class QThostname : public QGridLayout, public IMonitorModule{
    private:

                        QThostname();
            QString _name;

    public:
virtual                ~QThostname( void  );
                        QThostname(GetInfo* gi, QString name);
                        QThostname(QThostname const & in);
std::string                 getName();
void                    setName(QString const & newName);
QThostname&           operator=(QThostname const & in);
};



#endif

