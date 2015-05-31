/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:27:47 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/12 20:43:30 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Form form1("declaratin de drois de l homme et du citoyen", 149);
    Form form2("un pv", 10);
    int i = -100;
    while (i < 200)
    {
        try {
            Bureaucrat taffer("jmancero", i);
            taffer.getGrade();
            taffer.signForm(form2);
            taffer.signForm(form1);
            std::cout << taffer << std::endl;
            taffer.upGrade();
            taffer.signForm(form2);
            taffer.signForm(form1);
            std::cout << taffer << std::endl;
            taffer.upGrade();
            taffer.signForm(form2);
            taffer.signForm(form1);
            std::cout << taffer << std::endl;
            taffer.upGrade();
            taffer.signForm(form2);
            taffer.signForm(form1);
            std::cout << taffer << std::endl;
            taffer.downGrade();
            taffer.signForm(form2);
            taffer.signForm(form1);
            std::cout << taffer << std::endl;
            taffer.downGrade();
            taffer.signForm(form2);
            taffer.signForm(form1);
            std::cout << taffer << std::endl;
            taffer.signForm(form2);
            taffer.signForm(form1);
            taffer.downGrade();
        } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout <<"set Buraucrat whith " << i << " impossible; too low" << std::endl;
        }catch (Bureaucrat::GradeTooHighException& e) {
            std::cout <<"set Buraucrat whith " << i << " impossible; too High" << std::endl;
        }
        i = i + 10;
    }
    return 0;
}
