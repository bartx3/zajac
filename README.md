# zajac
Zadanie rekrutacyjne do koła naukowego

Zgodnie z treścią zadania, rozwiązanie opracowałem w C++. Ze względu na użycie względnie małych wartości, zdecydowałem się na używanie zmiennych typu int16_t.

Utworzyłem klasy Wsporzedne oraz Zajac

Klasa Wsporzedne zawiera:
-zmienne publiczne x, y będące 16-bitowymi zmiennymi całkowitymi,
-publiczny konstruktor 2-argumentowy inicjalizowany żądanymi wartościami zmiennych x, y
-publiczny konstruktor domyślny mający efekt w postaci wywołania powyższego konstruktora dla wartości 0, 0
-publiczną metodę zwracającą vector, zawierający pola na które Bajtek jest w stanie skoczyć. Zaznaczyć tutaj należy, że funkcja ta zwraca pola niezależnie od tego, czy obie współrzędne pól są nieujemne, czy nie. Gdyby podanie tych pól wiązało się z over- lub underflowem, funkcja rzuca wyjątek.

Klasa Zajac zawiera:
- chonione obiekty typu wsporzedne (wsp_zajaca i wsp_nory) przechowujące współrzędne zająca i nory
- chroniony vector<vector<bool>> plansza, zawierający informacje na temat tego, na jakie pola moze wskoczyc zając
- publiczny konstruktor inicjalizujący powyzsze zmienne na podstawie podanych parametrów m i n
- publiczny konstruktor domyślny
- publiczną metodę int wczytaj_polane(), wczytującą ze strumienia cin podane w nim dane o polanie, sformatowane zgodnie z trescia zadania. W razie podania niepoprawnych danych, wyrzuca wyjątek.
- publiczną metodę bfs_po_polanie() zawierającą implementację algorytmu przeszukiwania grafu wszerz, w celu odnalezienia najkrotszej możliwej ścieżki od zająca do nory. Funkcja zwraca długość znalezionej ścieżki bądź -1 jeśli ścieżka nie istnieje.

Ponadto napisałem w pliku nagłówkowym func.hpp znajduje się funkcja safetly_input_short, która pozwala na bezpieczne pobranie wartości całkowitej 16-bitowej z cin i umieszczenie w zmiennej. W przypadku jakichkolwiek odstępstw, funkcja ta wyrzuca wyjatek.

