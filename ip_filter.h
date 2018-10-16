#pragma once

#include <string>
#include <vector>

using ip_t          = std::vector<std::string>; //!< Тип для хранения IP-адресов
using ip_vector_t   = std::vector<ip_t>;        //!< Тип списка IP-адресов

///
/// \brief split Разбивает стороку на части
/// \param str Исходная строка
/// \param separator Знак по которому разбивается строка
/// \return Вектор строк на которые была разбита исходная строка
///
std::vector<std::string> split(const std::string &str, char separator);

inline void printIp(ip_t ip);

///
/// \brief printIp Выводит список векторов на стандартный вывод
/// \param vector
///
void printIp(ip_vector_t ipVector);

void filterAndPrint(ip_vector_t ipVector, int arg0 = 256, int arg1 = 256, int arg2 = 256, int arg3 = 256);
void filterAnyAndPrint(ip_vector_t ipVector, int arg);


