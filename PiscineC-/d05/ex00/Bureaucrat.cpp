/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:16:59 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 13:09:16 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat( void  ){
}
Bureaucrat::Bureaucrat( Bureaucrat const &in ) : _name(in.getName()), _grade(in.getGrade()){
};
Bureaucrat::Bureaucrat( std::string name , int grade) : _name(name) , _grade(150){
    this->setGrade(grade);
};
bool         Bureaucrat::setGrade(int grade){

    if (grade <= 150 && grade > 0)  {
        this->_grade = grade;
        return true;
    } else if (grade < 1) {
        throw Bureaucrat::GradeTooLowException(*this);
        return false;
    } else{
        throw Bureaucrat::GradeTooHighException(*this);
        return false;
    }
};
Bureaucrat::GradeTooHighException::GradeTooHighException(Bureaucrat const & initby) throw() : _init(initby){

};
std::string      Bureaucrat::getName() const{
    return this->_name;
};

Bureaucrat const &      Bureaucrat::GradeTooLowException::getInit() const {
    return this->_init;
};

Bureaucrat const &      Bureaucrat::GradeTooHighException::getInit() const {
    return this->_init;
};

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat const &  initby) throw() : _init(initby){
};

std::ostream& operator<<(std::ostream& o, Bureaucrat::GradeTooLowException const & in) throw()  {
    Bureaucrat const & init = in.getInit();
    o << init.getName() << ", bureaucrat grade " << init.getGrade();
    return o;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat::GradeTooHighException const & in) throw() {
    Bureaucrat const & init = in.getInit();
    o << init.getName() << ", bureaucrat grade " << init.getGrade();
    return o;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const & in) throw() {
    o << in.getName() << ", bureaucrat grade " << in.getGrade();
    return o;
};

int Bureaucrat::getGrade() const {
    return this->_grade;
};

bool         Bureaucrat::upGrade(){
    return this->setGrade(this->getGrade() - 1);

};
bool         Bureaucrat::downGrade(){
    return this->setGrade(this->getGrade() + 1);
};
