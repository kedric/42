/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesEngine.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazian <akazian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:38:31 by akazian           #+#    #+#             */
/*   Updated: 2015/01/18 20:33:51 by akazian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CURSES_ENGINE_CLASS_HPP
# define	CURSES_ENGINE_CLASS_HPP

# include <ncurses.h>
# include <map>
# include "../inc/IMonitorDisplay.class.hpp"
# include "../inc/IMonitorModule.class.hpp"
# include <list>

class	CursesEngine : public IMonitorDisplay {

	private:
		WINDOW	*main;
		std::map<std::string, WINDOW *>	modules;
		CursesEngine();

		CursesEngine & operator=(CursesEngine const & src);

	public:
		CursesEngine(std::list<std::string> arg);
		virtual ~CursesEngine();
		CursesEngine(CursesEngine const & src);

		int	run();
		void	updateHost(WINDOW *win);
		void	updateCpu(WINDOW *win);
		void	updateTime(WINDOW *win);
};

# else

class CursesEngine;

#endif
