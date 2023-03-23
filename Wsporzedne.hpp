//Wsporzedne.hpp
//
//Autor: Bartłomiej Sitnik

#ifndef _WSPORZEDNE_HPP_
#define _WSPORZEDNE_HPP_

#include <vector>
#include <cstdint>

/**
 * @class Wsporzedne
 * 
 * @brief Jest to klasa, która pozwala w elegancki sposób przechowywać współrzędne x i y w 16-bitowych zmiennych.
 * Zapewnia przy tym metodę generującą std::vector<Wsporazedne> wsporzednych pol,
 * na które Bajtek może wskoczyć.
*/

class Wsporzedne
{
    public:
        int16_t x;
        int16_t y;
        /**
         * @brief konstruktor inicjalizujący naszą zmienną od razu z zadanymi współrzędnymi
         * 
         * @param współrzędne x i y pola podane jako liczby całkowite 16-bitowe
        */
        Wsporzedne(int16_t x, int16_t y) noexcept(true);
        /**
         * @brief konstruktor domyślny - wywołuje Wsporzedne(0, 0)
        */
        Wsporzedne() noexcept(true);
        /**
         * @brief Generator pól dostępnych dla Bajtka z pola o współrzędnych przechowywanych w zmiennych x i y
         * 
         * @param Funkcja nie pobiera żadnego parametru
        */
        std::vector <Wsporzedne> dostepne_pola() noexcept(false);

        /**
         * @brief Przeładowany operator w celu porównywania czy współrzędne są takie same
        */
        bool operator==(Wsporzedne right);
};

#endif