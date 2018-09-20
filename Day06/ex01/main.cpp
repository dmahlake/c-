/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:00:44 by dmahlake          #+#    #+#             */
/*   Updated: 2018/06/13 17:00:47 by dmahlake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

struct Data 
{
    std::string str;
    int num;
    std::string str1;
};

Data * deserialize(void *raw)
{
    Data *deser = new Data;
    std::string temporary;
    int len;

    temporary = reinterpret_cast<char *>(raw);
    len = temporary.length();
    deser->str1 = temporary.substr(len - 8, len);
    deser->num = atoi(temporary.substr(8, len - 8).c_str());
    deser->str = temporary.substr(0, 8);
    return (deser);
}

void* serialize(void)
{
    const char letterArr[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string str;
    for (int i = 0; i < 17; i++) 
    {
        if (i == 8)
        {
            std::stringstream out;
            out << rand() % 2147483647;
            str += out.str();
        }
        else
            str.push_back(letterArr[rand() % static_cast<int>(sizeof(letterArr) - 1)]);
    }
    return reinterpret_cast<void *>(const_cast<char *>(str.c_str()));
}


int main(void)
{
    srand(time(NULL));
    void *serial = serialize();
    std::cout << "Memory address: " << serial << "\nSerialized data: "  << reinterpret_cast<char *>(serial) << std::endl;
    Data *deser = deserialize(serial);
    std::cout << "\nDeserialized data:\nstr: " << deser->str << "\nnum: " << deser->num << "\nstr1: " << deser->str1 << std::endl;
    return (0);
}