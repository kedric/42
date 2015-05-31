/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:16:59 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 13:12:05 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat {
    private:
    std::string const   _name;
    int                 _grade;
    public:
        class GradeTooHighException : public std::exception
        {
            private:
                Bureaucrat          const & _init;
                                    GradeTooHighException();

            public:
                                    GradeTooHighException(GradeTooHighException const &e);
                                    GradeTooHighException(Bureaucrat const &  initby) throw();
            virtual                 ~GradeTooHighException() throw() {} ;
            Bureaucrat const &      getInit() const;
            GradeTooHighException&  operator=(GradeTooHighException const & in) throw();
            };
            class GradeTooLowException : public std::exception
        {
            private:
                Bureaucrat const & _init;
                GradeTooLowException();

            public:
            virtual const char* what() const throw() {
                return "help";
            };
                virtual             ~GradeTooLowException(void) throw() {};
                                    GradeTooLowException(Bureaucrat const &  initby) throw();
                                    GradeTooLowException(GradeTooLowException const &e) throw();
            Bureaucrat const &      getInit() const;
            GradeTooLowException&   operator=(GradeTooLowException const & in);
        };

virtual                 ~Bureaucrat( void  );
                        Bureaucrat(std::string name , int grade);
                        Bureaucrat(Bureaucrat const &in);
Bureaucrat&             operator=(Bureaucrat const & in);
std::string             getName() const ;
int                     getGrade() const;
bool                    upGrade();
bool                    downGrade();
bool                    setGrade(int grade);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat::GradeTooLowException const & in) throw() ;
std::ostream& operator<<(std::ostream& o, Bureaucrat::GradeTooHighException const & in) throw() ;
std::ostream& operator<<(std::ostream& o, Bureaucrat const & in) throw() ;
#endif
