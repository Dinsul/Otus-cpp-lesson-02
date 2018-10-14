#pragma once

#include <string>
#include <vector>

using ip_vector_t = std::vector<std::vector<std::string>>; //!< Тип для хранения IP-адресов

///
/// \brief split Разбивает стороку на части
/// \param str Исходная строка
/// \param separator Знак по которому разбивается строка
/// \return Вектор строк на которые была разбита исходная строка
///
std::vector<std::string> split(const std::string &str, char separator);
