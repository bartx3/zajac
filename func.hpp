//func.hpp
//
//Autor: Bartłomiej Sitnik

#ifndef _ZAJAC_FUNC_HPP_
#define _ZAJAC_FUNC_HPP_

#include <cstdint>

/**
 * @brief funkcja do bardziej rygorystycznego wczytywania liczby 16-bitowej z domyślnego strumienia std::cin
 * 
 * @param referencja do zmiennej typu short int, którą chcemy wczytać
 * 
 * @return funkcja typu void. W razie jeśli w std::cin wczytany argument nie jest liczbą całkowitą,
 *         mieszczącą się w 16 bitach, rzuci wyjątek std::invalid_argument
*/
void safetly_input_short(int16_t & s) noexcept(false);

#endif