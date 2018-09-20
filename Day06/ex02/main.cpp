/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:51:47 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/13 15:51:51 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Base
{
    public:
        virtual ~Base(){}

};

class A : public Base{};
class B : public Base{};
class C : public Base{};

static Base *generate(void)
{
    char c = rand() % 3;
    Base *b;
    if (!c)
        b = new A();
    else if (c == 1)
        b = new B();
    else
        b = new C();
    return (b);
}
static void identify_from_pointer(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    if (a)
        std::cout << "A" << std::endl;
    else
    {
      B *b = dynamic_cast<B *>(p);
      if (b)
        std::cout << "B" << std::endl;
     else
        std::cout << "C" << std::endl;
    }
} 

static void identify_from_reference(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch(std::exception &e)
        {
            std::cout << "Its doesn't work " << std::endl;
        }
    }
}

int     main(void)
{
    srand(static_cast<unsigned int>(time(NULL)));
    Base *B;
    for (char str = 0; str < 3 ; str++)
    {
        B = generate();
        std::cout << "reference from identify" << std::endl;
         identify_from_reference(*B);
        std::cout << "pointer from identify" << std::endl;
        identify_from_pointer(B);
    }
    delete B;
    return (1);
}