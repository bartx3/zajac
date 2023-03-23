//main.cc
//
//Autor: Bartłomiej Sitnik

#include "Zajac.hpp"
#include "func.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    int16_t n, m;
    try
    {
        safetly_input_short(n);     //Wczytujemy n i m
        safetly_input_short(m);
        if (n < 1 || n > 1000 || m < 1 || m > 1000)
            throw std::invalid_argument("m lub n poza zakresem");
        
        Zajac Z(n, m);                  //Inicjalizacja i wczytanie polany
        Z.wczytaj_polane();
        int odp = Z.bfs_po_polanie();   //Przeprowadzamy BFS
        if (odp == -1)
            std::cout<<"NIE"<<std::endl;
        else
            std::cout<<odp<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}
