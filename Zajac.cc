//Zajac.cc
//
//Autor: Bartłomiej Sitnik

#include "Zajac.hpp"
#include <iostream>

Zajac::Zajac(int16_t n, int16_t m) noexcept(false) : wsp_Zajaca(0,0), wsp_nory(0,0), n {n}, m {m}
{
    if (n<0 || m<0)
        throw std::invalid_argument(std::string("Ujemny jeden z wymiarow nory. n: ")+std::to_string(n)+std::string(" m: ")+std::to_string(m));
    polana = std::vector<std::vector <bool>>(n, std::vector <bool>(m));
}

Zajac::Zajac() : Zajac(0, 0) {}

void Zajac::wczytaj_polane() noexcept(false)
{
    if ((signed int)polana.size()!=n 
      && n!=0
      && (signed int)polana[0].size()!=m)
        polana = std::vector<std::vector <bool>>(n, std::vector <bool>(m));

    bool Zajacset = false;
    bool noraset = false;

    for (int16_t i = 0; i < n; i++)
    {
        char c;
        for (int16_t j = 0; j < m; j++)
        {
            std::cin >> c;
            switch (c)
            {
                case '.':       //wolne pole
                    polana[i][j] = true;
                break;

                case 'x':       //kopiec kreta
                    polana[i][j] = false;
                break;

                case 'z':       //początkowe położenie zająca
                    polana[i][j] = false;
                    if (Zajacset==true)
                        throw std::invalid_argument(std::string("za wiele zajecy"));
                    Zajacset=true;
                    wsp_Zajaca = Wsporzedne(i, j);
                break;

                case 'n':       //położenie nory
                    polana[i][j] = true;
                    if (noraset==true)
                        throw std::invalid_argument(std::string("za wiele nor"));
                    noraset=true;
                    wsp_nory = Wsporzedne(i, j);
                break;

                default:
                    throw std::invalid_argument(std::string("niepoprawny input"));
                break;
            }
        }
    }
    if (Zajacset==false)
                    throw std::invalid_argument(std::string("brak Zajaca"));
    if (noraset==false)
                    throw std::invalid_argument(std::string("brak nory"));
}

int Zajac::bfs_po_polanie() noexcept(true)
{
    int licznik = 0;
    std::vector<Wsporzedne>zasieg_Zajaca(1, wsp_Zajaca);
    std::vector<Wsporzedne>potencjalny_zasieg_Zajaca;
    while (zasieg_Zajaca.size() > 0)
    {
        for (Wsporzedne pole_z_Zajacem : zasieg_Zajaca)
        {
            auto zasieg_z_pola = pole_z_Zajacem.dostepne_pola();
            for (Wsporzedne pole : zasieg_z_pola)
            {
                if (pole.x >= 0 && pole.x < n && pole.y >= 0 && pole.y < m && polana[pole.x][pole.y] == true)
                {
                    if (pole == wsp_nory)
                        return (licznik+1);     //znaleźliśmy naszą norę
                    
                    polana[pole.x][pole.y] = false;
                    potencjalny_zasieg_Zajaca.push_back(pole);
                }
            }
        }
        //nie znaleźliśmy nory, patrzymy, czy można zrobić to w kolejnym kroku
        licznik++;
        zasieg_Zajaca = potencjalny_zasieg_Zajaca; 
        potencjalny_zasieg_Zajaca.clear();
    }
    //nie dośliśmy do nory, ani nie mamy kolejnych kroków
    return (-1);
}