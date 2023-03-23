//Wsporzedne.cc
//
//Autor: Bartłomiej Sitnik

#include "Wsporzedne.hpp"
#include <stdexcept>
#include <string>

Wsporzedne::Wsporzedne(int16_t x, int16_t y) noexcept(true) : x {x}, y {y} {} 
Wsporzedne::Wsporzedne() noexcept(true) : Wsporzedne::Wsporzedne((int16_t)0, (int16_t)0) {}

std::vector <Wsporzedne> Wsporzedne::dostepne_pola() noexcept(false)
{
    if (x > (INT16_MAX-2) || x < (INT16_MIN+2) || y > (INT16_MAX-2) || y < (INT16_MIN+2))
        throw std::out_of_range (std::string("graniczne wartości - Bajtek z tego pola może wyskoczyć poza watości 16-bitowych zmiennych. Koordynaty: ") +
                                std::to_string(x) + std::string(" ") + std::to_string(x));
                                
    return (std::vector<Wsporzedne> {Wsporzedne(x+2, y+1), Wsporzedne(x+1, y+2),
                    Wsporzedne(x-1, y+2), Wsporzedne(x-2, y+1), 
                    Wsporzedne(x-2, y-1), Wsporzedne(x-1, y-2),
                    Wsporzedne(x+1, y-2), Wsporzedne(x+2, y-1)});
}

bool Wsporzedne::operator==(Wsporzedne right) noexcept(true)
{
    return (x == right.x && y == right.y);
}