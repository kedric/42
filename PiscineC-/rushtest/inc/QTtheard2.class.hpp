/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTtheard2.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:52:08 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 22:01:03 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QTTHEARD2_CLASS_HPP
# define QTTHEARD2_CLASS_HPP

#include <QWidget>
# include <string>
# include <iostream>
# include <QThread>
# include "../inc/QTModTime.class.hpp"



class QTthread2 : public QThread {
    Q_OBJECT
protected:
    void run();
signals:
     void resultUser(const int &);
     void resultSys(const int &);
     void resultIdle(const int &);
    public:
        GetInfo *_gi;

virtual                ~QTthread2( void  );
                        QTthread2(void);
void                    setGi(GetInfo * gi );
                        QTthread2(QTthread2 const & in);
QTthread2&         operator=(QTthread2 const & in);
};

#endif
