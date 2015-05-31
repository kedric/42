/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:27:47 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/12 19:32:44 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    int i = -100;
    while (i < 200)
    {
        try {
            Bureaucrat taffer("jmancero", i);
            taffer.getGrade();
            std::cout << taffer << std::endl;
            taffer.upGrade();
            std::cout << taffer << std::endl;
            taffer.upGrade();
            std::cout << taffer << std::endl;
            taffer.upGrade();
            std::cout << taffer << std::endl;
            taffer.downGrade();
            std::cout << taffer << std::endl;
            taffer.downGrade();
            std::cout << taffer << std::endl;
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
