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

///
/// \brief printIp Выводит на на стандартный вывод один IP-адрес
/// \param ip
///
inline void printIp(ip_t ip);

///
/// \brief printIp Выводит список векторов на стандартный вывод
/// \param vector
///
void printIp(ip_vector_t ipVector);

///
/// \brief filterAndPrint Выводит на стандартный вывод только те адреса,
/// которые соответствуют шаблону. argX 256 - выводить всегда, > 256 - выводить
/// только если данное поле совпадает.
/// \param ipVector Контейнер с IP-адресами
/// \param arg0 старший байт IP-адресса
/// \param arg1
/// \param arg2
/// \param arg3 младший байт IP-адресса
///
void filterAndPrint(ip_vector_t ipVector, int arg0 = 256, int arg1 = 256, int arg2 = 256, int arg3 = 256);

///
/// \brief filterAnyAndPrint Выводит на стандартный вывод только те адреса,
/// в которых любой байт подходит под абразец.
/// \param ipVector Контейнер с IP-адресами
/// \param arg >= 256 - ничего не выводить, > 256 абразец для вывода
///
void filterAnyAndPrint(ip_vector_t ipVector, int arg);


