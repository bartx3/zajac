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
 *        (wskoczył tam wcześniej niż )
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
        
        Zajac(int16_t n, int16_t m) noexcept(false);
        Zajac() noexcept(false);
        void wczytaj_polane() noexcept(false);

        int bfs_po_polanie() noexcept(true);
};

#endif