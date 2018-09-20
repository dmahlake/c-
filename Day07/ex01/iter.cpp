/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:16:56 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/14 17:56:05 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>

void display(T const & item)
{
    std::cout << item << std::endl;
}

template<typename T>
void iter(T * point, int len, void(*f)(T const & item))
{
    for (int i = 0; i < len; i++)
    {
        f(point[i]);
    }
}

int main(void)
{
    char str[] = {'A', 'B'};
    int number[] = {0, 1, 2, 3, 4};
    bool dare[] = {true, true, false, true, false};
    std::cout << "passing  Chars"<< std::endl;
    iter(str, 2, display<char>);
    std::cout << "passing  Integer"<< std::endl;
    iter(number, 5, display<int>);
    std::cout << "passing  Bool"<< std::endl;
    iter(dare, 5, display<bool>);
    return (0) ;
}
