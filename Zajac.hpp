//Zajac.hpp
//
//Autor: Bartłomiej Sitnik

#ifndef _ZAJAC_HPP_
#define _ZAJAC_HPP_

#include <vector>
#include <utility>
#include <stdexcept>
#include <cstdint>
#include "Wsporzedne.hpp"


/**
 * @class Zajac
 * 
 * @brief Jest to klasa, która przechowuje w kontenerze std::vector<std::vector<bool>> stan naszej polany,
 *        gdzie wartość false oznacza pole, na które zając wskoczyć nie możę (kopiec kreta), bądź nie opłaca mu się to
 *        (Bajtek już wcześniej mógł wskoczyć na dane pole)
 *        Aby sprawdzić, jak szybko Bajtek moźe wskoczyć do nory naleźy:
 *           - utworzyć i zinicjalizoać objekt klasy Zajac za pomocą konstruktora Zajac(int16_t n, int16_t m)
 *           - wczytać stan polany zapomocąfunkcji wczytaj_polane()
 *           - wykonać funkcję bfs_po_polanie(), która zwróci pożądaną wartość bądź -1 jeśli Bajtek nie może znaleźć drogi do nory
 *        Złoźoność pamięciowa: O(n*m)
 *        Złożoność obliczeniowa: O(n*m)
*/
class Zajac
{
    protected:
        std::vector<std::vector <bool>> polana;
        Wsporzedne wsp_Zajaca;
        Wsporzedne wsp_nory;
        int16_t n;
        int16_t m;
    public:
        /** 
         * @brief Tworzy instancję klasy Zajac
         *
         * @param n, m wymiary planszy               
         *
        */
        Zajac(int16_t n, int16_t m) noexcept(false);

        /**
         * @brief Konstruktor domyślny. Wywołuje konstruktor Zajac(int16_t n, int16_t m) z parametrami (0, 0)
        */
        Zajac() noexcept(false);

        /**
         * @brief Funkcja wczytująca polanę z wejścia standardowego std::cin.
         *        Wczytane dane zapisuje w zmiennych prywatnych polana, wsp_Zajaca i wsp_nory
         *        W razie niepoprawnego inputu rzuca std::invalid_argument()
        */
        void wczytaj_polane() noexcept(false);

        /**
         * @brief Funkcja implementuje algorytm przeszukiania wszerz do polany. Najpierw kopiuje stan polany.
         * Potem w kolejnych iteracjach pętli oznacza pola, na które zając może wskoczyć w danej liczbie ruchów.
         * Złoźoność pamięciowa: O(n*m)
         * Złożoność obliczeniowa: O(n*m)
         *
         * @return Najmniejsza liczba kroków, potrzebnych Bajtkowi do dojścia do nory lub -1 jeśli jest to niemożliwe.
        */
        int bfs_po_polanie() noexcept(true);
};

#endif