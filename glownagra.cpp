#include "glownagra.hpp"
#include "ascii.hpp"
#include "reszta-funkcji.hpp"


std::string poziomtrudnosci(){ //funkcja difficulty picker
    std::string trudnosc;
    std::string potwierdztrudnosc = "n";

    while(potwierdztrudnosc != "t" && potwierdztrudnosc != "T" && potwierdztrudnosc != "tak" && potwierdztrudnosc != "TAK" ){
        czysci();

        belka();
        scianka();
        std::cout << "|                                                    wpisz poziom trudności:                                                   |" << "\n";
        std::cout << "|                                                    latwy | sredni | trudny                                                   |" << "\n";
        scianka();
        belka();

        std::cin >> trudnosc;
        
        //sprawdza czy trudnosci sa w odpowiednim zakresie, wymusza wpisanie odpowiedniego stringa
        while(trudnosc != "latwy" &&  trudnosc != "sredni" && trudnosc != "trudny"){   
            czysci(); 

            belka();
            std::cout << "!                                                                                                                              !" << "\n";
            std::cout << "!                                              ! wybrano błędny poziom trudności !                                             !" << "\n";
            std::cout << "!                                                                                                                              !" << "\n";                
            std::cout << "!                                            ! podaj poziom trudności jeszcze raz !                                            !" << "\n";
            std::cout << "!                                                                                                                              !" << "\n";
            belka();

            std::cin >> trudnosc;
        }
        
        //potwierdzenie wyboru
        czysci();

        belka();
        scianka();
        std::cout << "|                                               wybrałeś " << trudnosc << " poziom trudności                                               ";

        if(trudnosc == "latwy") std::cout << " "; //zrobione zeby szata graficzna sie zgadzala
        std::cout  << "|\n";

        scianka();
        std::cout << "|                                                        zgadza się? t/n                                                       |" << "\n";
        scianka();
        belka();

        std::cin >> potwierdztrudnosc;

    }
    return trudnosc;
}

// glowna funkcja gry zgadywania
void glownagra(std::string &imie, int &ilprob, std::string &poztrud,bool &przegrana){// referencje, dzieki nim w mainie beda dostepne zmienne z tej funkcji!
    
    int cel; //cel w ktory bedziemy strzelac
    int proba = 0; // tutaj beda podstawiane proby zgadywania.

    //czysci();

    ilprob = 0; // ustawia na start ilosc prob na 0

    poztrud = poziomtrudnosci(); // wpisanie poziomu trudnosci z funkcji do zmiennej poztrud
    
    srand(time(0)); // ustawienie ziarna dla losowosci ( time(0) zwraca aktualny czas w sekundach )

    //ustawianie celu ktory bedziemy zgadywac w zaleznosci od poziomu trudnosci.
    if (poztrud == "latwy"){

        cel = rand() % 50 + 1; // łatwy, 1-50

    } else if(poztrud == "sredni"){

        cel = rand() % 100 + 1; // średni, 1-100

    } else if(poztrud == "trudny"){

        cel = rand() % 250 + 1; // trudny, 1-250

    }

    //tryb zakladu
    int zaklad; //liczba zakladana
    std::string pytzak; // pytanie o zaklad
    std::string potwzak;// potwierdzenie zakladu
    przegrana = false; // potrzebne zeby sprawdzac czy bylo cos przegrane

    while(potwzak != "t" && potwzak != "T" && potwzak != "tak" && potwzak != "TAK"){
        czysci();

        belka();
        scianka();
        std::cout << "|                                           czy chcialbys wlaczyc tryb zakladu? t/n                                            |\n";
        scianka();
        belka();

        std::cin >> pytzak;

        if(pytzak == "t" || pytzak == "T" || pytzak == "tak" || pytzak == "TAK"){
            czysci();

            belka();
            scianka();
            std::cout << "|                                         podaj w ilu probach myslisz ze sie zmiescisz                                         |\n";
            scianka();
            belka();

            std::cin >> zaklad;

            while(zaklad < 1){
                belka();
                std::cout << "!                                                                                                                              !" << "\n";
                std::cout << "!                                          ! nie da sie zgadnac w mniej niz 1 probe !                                          !\n";
                std::cout << "!                                                                                                                              !" << "\n";
                belka();

                std::cin >> zaklad;
            }

    
            //potwierdzenie
            czysci();

            belka();
            scianka();
            std::cout << "|                                              jestes pewny swojego zakladu? t/n                                               |\n";
            scianka();
            belka();

            std::cin >> potwzak;

        }else{//potwierdzenie braku zakladu
            czysci();

            belka();
            scianka();
            std::cout << "|                                        jestes pewny, ze nie chcesz sie zakladac? t/n                                         |\n";
            scianka();
            belka();

            std::cin >> potwzak;
        }

    }

    // rozpoczecie zgadywania
    while(proba != cel){
        czysci();// clearowanie terminala

        if(ilprob >= zaklad && (pytzak == "t" || pytzak == "T" || pytzak == "tak" || pytzak == "TAK")){

            przegrana = true; // ustawia przegrana na true, potrzebne zeby po petli nie pytac po imie gracza

            break; // konczy petle tu i teraz
        }
        
        //stary dziad zawsze na gorze ekranu
        belka();
        scianka();
        starydziad(); // printuje starego dziada

        //ramka wypowiedzi dziada
        std::cout << "+--------------------------------------------------------------------------------------------------------------------------+---+";

        if(pytzak == "t" || pytzak == "T" || pytzak == "tak" || pytzak == "TAK"){//wypisywanie ramki zakladu gdy jest wlaczony
            std::cout << "-----------+";
        }
        
        std::cout << "\n"; // zakonczenie linii

        // info o ilosci prob
        std::cout << "|                                                                                                               ";
        std::cout << "ilość prób:|";
        //ify sprawiajace ze ramka sie nie psuje nie wazne ile prob sie ma
        if(ilprob < 100)std::cout << " ";
        if(ilprob < 10)std::cout << " ";
        std::cout << ilprob << "|";//dokonczenie rameczki
        
        if(pytzak == "t" || pytzak == "T" || pytzak == "tak" || pytzak == "TAK"){//wypisywanie zakladu gdy jest wlaczony
            std::cout << "zaklad: ";
            if(zaklad < 100)std::cout << " ";
            if(zaklad < 10)std::cout << " ";
            std::cout << zaklad << "|";
        }
        
        std::cout << "\n"; //zakonczenie tej linii
   

        std::cout << "|                                                                                                                          +---+";
        
        if(pytzak == "t" || pytzak == "T" || pytzak == "tak" || pytzak == "TAK"){//wypisywanie ramki zakladu gdy jest wlaczony
            std::cout << "-----------+";
        }
        
        std::cout << "\n"; // zakonczenie linii

        // informuje czy cel jest wiekszy czy mniejszy od proby
        int loswiad; // losowa wiadomosc
        if (ilprob > 0){
            if(cel > proba){
                loswiad = rand() % 10;  
            }else if(cel < proba){
                loswiad = rand() % 10 + 10;
            }
            std::cout << losowawiadomosc(loswiad, proba) << "\n";
        }else{ // wita sie z graczem przy uruchomieniu
            std::cout << "|                      Witaj w Zgaduj Zgadula! Jestem Zgadula i będę ci pomagał w zgadywaniu. Powodzenia!                      |" << "\n";
        }

        scianka();

        //prosi o zgadniecie liczby w odpowiednim przedziale
        std::cout << "|                                              ";
        std::cout << "zgadnij liczbę w przedziale ";
        if(poztrud == "latwy"){
            std::cout << "1-50 ";
        }else if (poztrud == "sredni"){
            std::cout << "1-100";
        }else if (poztrud == "trudny"){
            std::cout << "1-250";
        }
        std::cout << "                                               |\n";


        
        // ramka koncowa
        scianka();
        belka();


        std::cin >> proba; // pierwsza proba


        //sprawdzenie czy proba jest w przedziale poziomu trudnosci
        if(poztrud == "latwy"){
            while(proba < 1 || proba > 50){
                belka();
                std::cout << "!                                                                                                                              !" << "\n";
                std::cout << "!                                ! wpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz !                                !\n";
                std::cout << "!                                                                                                                              !" << "\n";
                belka();

                std::cin >> proba;
            }
        }else if (poztrud == "sredni"){
            while(proba < 1 || proba > 100){
                belka();
                std::cout << "!                                                                                                                              |" << "\n";
                std::cout << "!                                ! wpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz !                                |\n";
                std::cout << "!                                                                                                                              !" << "\n";
                belka();
                std::cin >> proba;
            }
        }else if (poztrud == "trudny"){
            while(proba < 1 || proba > 250){
                belka();
                std::cout << "!                                                                                                                              !" << "\n";
                std::cout << "!                                ! wpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz !                                !\n";
                std::cout << "!                                                                                                                              !" << "\n";
                belka();
                std::cin >> proba;
            }
        }

        //zamkniecie ramki ogolnej
        belka();


        //dodanie 1 do ilosci prob na koniec petli
        ilprob++;
    }

    //info o przegranym zakladzie zamiast pytania o imie
    if(przegrana == true){
        std::string przegmenu;
        while(przegmenu != "menu"){
            czysci();

            belka();
            scianka();
            asciiprzegrana(); // pokazuje ascii napisu przegrana
            scianka();
            std::cout << "|                                     przegrales! wykonales wiecej prob niz podany zaklad!                                     |\n";
            scianka();
            std::cout << "|                                                    menu - powrot do menu                                                     |\n";
            scianka();
            belka();

            std::cin >> przegmenu;
        }
    }else{ //pytanie o nazwe gracza do wynikow (jezeli nie przegral)
        czysci();

        belka();
        scianka();
        asciiwygrana();
        scianka();
        std::cout << "|                                    ";
        std::cout << "dobrze! udało ci się zgadnąć liczbę " << cel;
        if(cel < 100)std::cout << " "; // musza byc zeby rameczka sie zgadzala
        if(cel < 10)std::cout << " ";
        std::cout << " w " << ilprob;
        if(ilprob < 100)std::cout << " "; //tu to co wyzej
        if(ilprob < 10)std::cout << " ";
        std::cout << " probach!                                    |\n";

        scianka();

        std::cout << "|                                podaj swoje imię, aby dodać je do tablicy najlepszych wynikow.                                |\n";
        scianka();
        belka();
        std::cin >> imie;
    }

}
