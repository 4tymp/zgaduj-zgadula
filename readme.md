WITAMY W ZGADUJ ZGADULA!

Zgaduj Zgadula to gra polega na zgadywaniu liczb działająca w terminalu.

Plik którego zawartość teraz czytasz jest podzielony na:
    1. Wszystkie mozliwości gry
    2. Instrukcje uruchomienia gry
    3. Dokladne instrukcje dotyczace kazdego fragmentu gry


1. Wszystkie mozliwości gry

    Gra Zgaduj Zgadula posiada:
    - Ekran tytułowy, w którym mozemy przejść do gry, sprawdzić tabelę najlepszych wyników (tylko jezeli jakies juz sa), oraz wyjsc z programu
    
    - Ekran najlepszych wynikow, w ktorym pokazywane jest TOP 5 graczy z najmniejsza iloscia prob, posortowany wedlug poziomow trudnosci (mozemy wybrac ktory poziom trudnosci chcemy wyswietlac w danym momencie). W tym ekranie mozemy rowniez zapisac wyniki do osobnego pliku oraz je wczytać. Ekran posiada tez mozliwosc powrotu to ekranu tytulowego

    - 3 poziomy trudnosci (latwy, sredni, trudny) do wyboru przed rozgrywka

    - Tryb zakladu, w ktorym podajemy maksymalna ilosc prob w jaka myslimy ze zgadniemy wylosowana liczbe, jezeli tryb zakladu zostanie wybrany i wykonamy wiecej prob niz zaklad gra konczy sie przegrana i wynik nie jest wpisywany do tabeli wynikow.

    - Licznik prob podczas rozgrywki, ktory jest widoczny zawsze i na biezaco sie aktualizuje. Dodatkowo jesli tryb zakladu zostal wlaczony podczas gry ukaze sie rowniez wielkosc zakladu abysmy mieli porownanie z naszymi probami

    - W przypadku podania blednej liczby ukazuja sie losowe wiadomosci, ktore nakierowują na liczbę której szukamy

    - W przypadku trafienia odpowiedniej liczby pokazany zostaje ekran zwycięstwa, po czym jesteśmy proszeni o nazwę, po czym nasz wynik jest wpisywany do tabeli wyników

    - Gra posiada prymitywną oprawę graficzną ASCII, oraz Zgadulę, czyli czarodzieja który przeprowadza nas przez całą rozgrywkę

2. Instrukcje uruchomienia gry

    Gdy posiadamy juz pliki naszej gry na swoim komputerze (mozna to osiagnac poprzez sklonowanie repozytorium lub po prostu pobranie wszystkich skompresowanych plikow w formacie zip) musimy otworzyc terminal na naszym sprzecie.

    !!! BARDZO POLECAMY URUCHOMIANIE GRY ZGADUJ ZGADULA NA TERMINALU KTORY JEST W PELNYM EKRANIE, INACZEJ ELEMENTY GRAFICZNE GRY MOGA SIE NIE ZMIESCIC, JEZELI PROBLEM CALY CZAS WYSTEPUJE POLECAMY ZMIEJSZENIE ROZMIARU TEKSTU UZYWAJAC SKROTU KLAWIATUROWEGO `COMMAND/CTRL -` !!!

    Po uruchomieniu terminala uzywajac komendy `cd` nalezy przejsc do katalogu z gra, nastepnie wykonac `g++ zgaduj-zgadula.cpp glownagra.cpp ascii.cpp reszta-funkcji.cpp -o Zgaduj-Zgadula`.

    Wtedy zostaje nam juz wykonanie `./Zgaduj-Zgadula` i gra powinna się uruchomić.

3. Dokladne instrukcje dotyczace kazdego fragmentu gry

    A - Ekran tytulowy
   
      Pierwsze co widzisz po uruchomieniu gry! Przy pierwszym uruchomieniu mozesz wykonac dwie komendy - `start` i `wyjdz`. Komendy wykonujemy wpisujac ich nazwe, po czym zatwierdzamy klawiszem enter. 
      !UWAGA! Przy pierwszym uruchomeniu gry nie mamy jeszcze zadnego wyniku, przez co trzecia opcja - `tabela` sie nie pokazuje. Pokaze sie ona po pierwszej wygranej rozgrywce.

      `start` - rozpoczyna rozgrywkę. Po więcej informacji o ekranie rozgrywki przejdz do segmentu B.

      `tabela` - przechodzi do ekranu tabeli wynikow. Po wiecej informacji o ekranie tabeli wynikow przejdz do segmentu C. 

      `wyjdz` - konczy program, wychodzisz z gry.

    B - Ekran rozgrywki

      - okno wyboru poziomu trudnosci
           Na początku bedziesz musial wybrac poziom trudnosci. Do wyboru jest: `latwy` `sredni` i `trudny`. Dokladnie takie komendy mowisz wpisac aby wybrac preferowany poziom. Jezeli wpiszesz cokolwiek innego w tym oknie, nie boj sie! Program to wykryje i bedzie czekal na poprawny poziom trudnosci jeszcze raz.
           Po wybraniu poziomu trudnosci zobaczysz okno, ktore bedzie chcialo od ciebie potwierdzenia czy na pewno wybrales poziom ktory chciales. Jezeli jest on poprawny, mozesz wpisac `t`, `T`, `tak`, `TAK` i zatwierdzic klawiszem enter. Wprowadzenie czegokolwiek innego skutkuje powrotem do okna wyboru trudnosci.

      - okno zakladu
           - nastepnie przed toba pojawi sie okno zakladu. Na poczatku pyta ono czy chcesz się załozyc. Zaklad polega na wpisaniu maksymalnej liczby prob, w ktora wygrasz gre. Jezeli nie zmiescisz sie w podanym zakladzie, przegrasz i nie bedziesz wpisany na tabele wynikow. Jezeli chcesz sie zalozyc, mozesz wpisac `t`, `T`, `tak` lub `TAK`. W przypadku wpisania czegokolwiek innego nie bedziesz sie zakladal.

           - zaklad - tak: zostaniesz poproszony o podanie wielkosci zakladu, po czym w oknie potwierdzenia bedziesz poproszony o potwierdzenie wlaczenia trybu zakladu. Jezeli sie nie zgodzisz, wrocisz do poczatku okna zakladu.

           - zaklad - nie: zostaniesz poproszony o potwierdzenie, ze nie chcesz sie zakladac. Jezeli nie potwierdzisz, wrocisz do poczatku okna zakladu

      - Ekran gry
           Teraz zaczyna się twoja rozgrywka! Pierwsze co przykuwa oko, to nasz znajomy czarodziej - Zgadula. To on będzie cię przeprowadzał przez rozgrywkę. Ponizej widzisz jego okno dialogowe, a w nim:

           - Ilość prób, które wykonałeś
           - Wielkość zakładu (o ile tryb zakładu jest włączony)
           - Podpowiedź dotycząca liczby (dopiero jezeli conajmniej jeden glos zostal wykonany, inaczej Zgadula po prostu sie z nami wita) - Pamietaj, ze Zgadula ci podpowiada, ale doczytaj się uwaznie! Zgadula to maly psotnik i jego podpowiedzi sa czesto dosyc zawile.
           - Przypomnienie w jakim przedziale musisz zgadnac liczbe

           Teraz mozesz juz zgadywac! Nalezy wpisac liczbę, którą zgadujesz i zatwierdzic klawiszem enter. Jezeli wpiszesz liczbę poza przedziałem, na spokojnie - zostaniesz poproszony o podanie poprawnej liczby, a twoja ilość prób się nie zwiększy.
            Po pierwszym zgadywaniu Zgadula zacznie ci podpowiadać, abyś mógł jak najszybciej trafić w cel. Czytaj uwaznie podpowiedzi Zgaduli i zapamietaj jakie liczby juz wpisywales!

           Pamietaj, ze jezeli wlaczyles tryb zakladu nie mozesz przekroczyc iloscia prob wielkosci swojego zakladu. Jezeli nie uda ci się zgadnac liczby w wielkosci zakladu, gra skonczy sie przegrana.

           W koncu, gdy udalo zgadnac ci sie liczbe, zostaniesz przeniesiony do ekranu zwyciestwa, gdzie bedzie podana ilosc twoich prob oraz poziom trudnosci. Bedziesz rowniez proszony o podanie imienia, dzieki ktoremu bedziesz widoczny na tabeli wynikow!

    C - Ekran tabeli wynikow

      Po wejsciu do ekranu tabeli wynikow domyslnym wyswietlanym poziomem trudnosci bedzie latwy. Mozesz zmieniac widoczne tabele wedlug poziomow trudnosci uzywajac komend `latwy`, `sredni` i `trudny`. Jezeli sprobujesz wykonac komende, ktora nie jest podana na dole ekranu i nie jest poziomem trudnosci zostanie pokazany domyslny, tryb latwy.
      Jezeli nie ma wynikow dla wybranego poziomu trudnosci w miejscu wynikow zobaczymy komunikat "brak wynikow dla poziomu x" gdzie x == wybrany poziom trudnosci.
      Wyniki beda na bierzaco samoistnie sortowane, w kolejnosci od najlepszego wyniku (najmniej prob) do najgorszego (najwiecej prob) i bedzie widocznych tylko 5 najlepszych graczy dla kazdego poziomu trudnosci.

      Reszta komend:
          `zapisz` - Zapisuje wyniki aktualnej sesji i wypisuje je do zewnetrznego pliku "wyniki.txt"
          `wczytaj` - Czysci wyniki aktualnej sesji i wczytuje wyniki zapisane w pliku "wyniki.txt" jezeli plik nie istnieje, nie wyczysci aktualnej sesji i nie wczyta czegos, co nie istnieje.
          `wyjdz` - Wraca do ekranu tytulowego

    D - Wyjscie z gry

      Juz nas opuszczasz? No coz, bylo milo.
      Aby wyjsc z programu nalezy na ekranie tytulowym wpisac komende `wyjdz`.


Dziekuje za czas poswiecony ograniu mojej gierki, jest to moj pierwszy programistyczny projekt wiec wiele dla mnie znaczy, mam nadzieje ze dobrze sie bawiles :)
~ Tymoteusz Pieczka
