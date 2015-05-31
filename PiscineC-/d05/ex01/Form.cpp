/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 20:02:50 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/12 20:45:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form( void  ){
}
Form::Form( Form const &in ) : _name(in.getName()), _grade(in.getGrade()){
};
Form::Form( std::string name , int grade) : _name(name) , _grade(grade){
};

Form::GradeTooHighException::GradeTooHighException(Form const & initby) throw() : _init(initby){

};
std::string      Form::getName() const{
    return this->_name;
};

Form const &      Form::GradeTooLowException::getInit() const {
    return this->_init;
};

Form const &      Form::GradeTooHighException::getInit() const {
    return this->_init;
};

Form::GradeTooLowException::GradeTooLowException(Form const &  initby) throw() : _init(initby){
};

std::ostream& operator<<(std::ostream& o, Form::GradeTooLowException const & in) throw()  {
    Form const & init = in.getInit();
    o << init.getName() << ", Form grade " << init.getGrade() << "Gade so Hight!!";
    return o;
};

std::ostream& operator<<(std::ostream& o, Form::GradeTooHighException const & in) throw() {
    Form const & init = in.getInit();
    o << init.getName() << ", Form grade " << init.getGrade() << " Grade so low!!";
    return o;
};

std::ostream& operator<<(std::ostream& o, Form const & in) throw() {
    o << in.getName() << ", Form grade " << in.getGrade();
    return o;
};

int Form::getGrade() const {
    return this->_grade;
};

bool                    Form::beSigned(Bureaucrat & worker) {
    if (worker.getGrade() > this->getGrade() && this->_signed == false)  {
            this->_signed = true;
            return true;
        } else if (this->_grade < this->getGrade()) {
            throw Form::GradeTooHighException(*this);
            return false;
        } else if (this->_grade < this->getGrade()){
            throw Form::GradeTooLowException(*this);
            return false;
        } else {
            return false;
        }
};


