#pragma once

#include <string>
#include <vector>

using ip_t          = std::vector<std::string>; //!< Тип для хранения IP-адресов
using ip_vector_t   = std::vector<ip_t>;        //!< Тип списка IP-адресов

bool operator < (const ip_t &first, const ip_t &second);

///
/// \brief split Разбивает стороку на части
/// \param str Исходная строка
/// \param separator Знак по которому разбивается строка
/// \return Вектор строк на которые была разбита исходная строка
///
std::vector<std::string> split(const std::string &str, char separator);

///
/// \brief printIp Выводит на на стандартный вывод один IP-адрес
/// \param ip
///
inline void printIp(const ip_t &ip);

///
/// \brief printIp Выводит список векторов на стандартный вывод
/// \param vector
///
void printIp(const ip_vector_t &ipVector);

///
/// \brief filterAnyAndPrint Выводит на стандартный вывод только те адреса,
/// в которых любой байт подходит под абразец.
/// \param ipVector Контейнер с IP-адресами
/// \param arg >= 256 - ничего не выводить, < 256 абразец для вывода
///
void filterAnyAndPrint(const ip_vector_t &ipVector, int arg);

template<typename T, typename ... Args>
void printIp(ip_vector_t &ipVector, T first, Args... args)
{
    ip_vector_t filtered;
    auto pos = sizeof... (args);

    for (const auto &ip : ipVector)
    {
        if (std::stoi(ip.at(pos)) == first)
        {
            filtered.push_back(ip);
        }
    }

    return printIp(filtered, args...);
}
