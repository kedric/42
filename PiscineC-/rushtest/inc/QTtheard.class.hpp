/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTtheard.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:52:08 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 21:49:25 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef QTTHEARD_CLASS_HPP
# define QTTHEARD_CLASS_HPP

#include <QWidget>
# include <string>
# include <iostream>
# include <QThread>
# include "../inc/QTModTime.class.hpp"



class QTthread : public QThread {
    Q_OBJECT
protected:
    void run();
signals:
     void resultReady(const QString &s);
    public:
        GetInfo *_gi;

virtual                ~QTthread( void  );
                        QTthread(void);
void                    setGi(GetInfo * gi );
                        QTthread(QTthread const & in);
QTthread&         operator=(QTthread const & in);
};

#endif
