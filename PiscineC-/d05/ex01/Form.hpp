/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:03:19 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/12 20:30:11 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>


class Bureaucrat;
class Form {
    private:
    std::string const   _name;
    int         const   _grade;
    bool                _signed;
    public:
        class GradeTooHighException : public std::exception
        {
            private:
                Form          const & _init;
                                    GradeTooHighException();

            public:
                                    GradeTooHighException(GradeTooHighException const &e);
                                    GradeTooHighException(Form const &  initby) throw();
            virtual                 ~GradeTooHighException() throw() {} ;
            Form const &      getInit() const;
            GradeTooHighException&  operator=(GradeTooHighException const & in) throw();
        };
        class GradeTooLowException : public std::exception
        {
            private:
                Form const & _init;
                GradeTooLowException();

            public:
                virtual             ~GradeTooLowException(void) throw() {};
                                    GradeTooLowException(Form const &  initby) throw();
                                    GradeTooLowException(GradeTooLowException const &e) throw();
            Form const &      getInit() const;
            GradeTooLowException&   operator=(GradeTooLowException const & in);
        };

virtual                 ~Form( void  );
                        Form(std::string name , int grade);
                        Form(Form const &in);
Form&                   operator=(Form const & in);
std::string             getName() const ;
int                     getGrade() const;
bool                    beSigned(Bureaucrat & worker);

};

std::ostream& operator<<(std::ostream& o, Form::GradeTooLowException const & in) throw() ;
std::ostream& operator<<(std::ostream& o, Form::GradeTooHighException const & in) throw() ;
std::ostream& operator<<(std::ostream& o, Form const & in) throw() ;
#endif

