/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:02:06 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 20:11:01 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
    private:

    public:
        class iterator {
                private:
                    MutantStack *_ptr;
                    int    _num;
                public:
                                    ~iterator( void  ){};
                                    iterator( void  ) : _num(-1) , _ptr(NULL){};
                                    iterator(iterator const & in) {};
                int                 getIndex() const { return this->_num; };
                                    iterator(MutantStack *in, bool end){
                                        this->_num = 0;
                                        if (end)
                                            this->_num = in->size();
                                        this->_ptr = in;
                                    };
            iterator&         operator=(iterator const & in);
            bool              operator!=(iterator const & in){ return this->_num != in.getIndex(); };
            T                 operator*(){ return *(&this->_ptr->top() - this->_num); };
            void              operator++() { this->_num++; };
            void              operator--(){ this->_num--; }
        };
                            ~MutantStack( void  ){};
                            MutantStack( void  ){};
MutantStack<T>::iterator    begin() { return MutantStack<T>::iterator(this, false); };
MutantStack<T>::iterator    end( ){ return MutantStack<T>::iterator(this , true) ;};
                            MutantStack(MutantStack const & in){ *this = in; };
MutantStack&                operator=(MutantStack const & in){ return *this=in; };
};

template<typename T>
std::ostream & operator<<(std::ostream& o, T const & p){
    o << p.top();
    return o;
};

#endif
