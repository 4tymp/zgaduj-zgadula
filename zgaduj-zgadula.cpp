#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // biblioteka od randomowosci
#include <ctime> // biblioteka dla time (tez potrzebne do rand)


void czysci(){ // funkcja czyszczaca ekran ( portable! )
    for (int i=0;i<50;i++){
        std::cout << "\n";
    }
}

std::string konwertertrud(int tr){
    //ustawia odpowiedni string w zaleznosci od podanego poziomu trudnosci.
    std::string strtrud;
        if(tr == 1){
            strtrud = "łatwy";
        }else if(tr == 2){
            strtrud = "średni";
        }else if(tr == 3){
            strtrud = "trudny";
        }
        return strtrud;
}

int poziomtrudnosci(){ //funkcja difficulty picker
    int trudnosc;
    std::string potwierdztrudnosc = "n";

    while(potwierdztrudnosc != "t" && potwierdztrudnosc != "T" && potwierdztrudnosc != "y" && potwierdztrudnosc != "Y" ){
        std::cout << "\nwybierz poziom trudności:\n";
        std::cout << "(1)łatwy(1)   (2)średni(2)   (3)trudny(3)\n";

        std::cin >> trudnosc;
        
        //sprawdza czy trudnosci sa w odpowiednim zakresie, wymusza wpisanie odpowiedniej liczby
        while(trudnosc < 1 || trudnosc > 3){   
            std::cout << "\n";  
            std::cout << "wybrano błędny poziom trudności.\n";
            std::cout << "podaj poziom trudności jeszcze raz.\n";
            std::cin >> trudnosc;
        }

        //konwersja z int na nazwe poziomu trudnosci
        std::string strtrud = konwertertrud(trudnosc);
    
        //potwierdzenie wyboru
        std::cout << "\nwybrałeś " << strtrud << " poziom trudności.\n";
        std::cout << "zgadza się? t/n\n";
        std::cin >> potwierdztrudnosc;

    }
    return trudnosc;
}

// glowna funkcja gry zgadywania
void glownagra(std::string &imie, int &ilprob, int &poztrud){// referencje, dzieki nim w mainie beda dostepne zmienne z tej funkcji!
    
    //zbiorowisko zmiennych
    int cel; //cel w ktory bedziemy strzelac
    int proba = 0; // tutaj beda podstawiane proby zgadywania.

    //poczatek kodu
    czysci();

    ilprob = 0; // ustawia na start ilosc prob na 0

    poztrud = poziomtrudnosci(); // wpisanie poziomu trudnosci z funkcji do zmiennej poztrud
    
    srand(time(0)); // ustawienie ziarna dla losowosci ( time(0) zwraca aktualny czas w sekundach )

    //ustawianie celu ktory bedziemy zgadywac w zaleznosci od poziomu trudnosci.
    if (poztrud == 1){

        cel = rand() % 50 + 1; // łatwy, 1-50

    } else if(poztrud == 2){

        cel = rand() % 100 + 1; // średni, 1-100

    } else if(poztrud == 3){

        cel = rand() % 250 + 1; // trudny, 1-250

    }

    // rozpoczecie zgadywania
    while(proba != cel){
        czysci();// clearowanie terminala

        // podaje ilosc prob
        std::cout << "ilość prób: " << ilprob << "\n\n";

        //prosi o zgadniecie liczby w odpowiednim przedziale
        std::cout << "zgadnij liczbę w przedziale ";
        if(poztrud == 1){
            std::cout << "1-50\n";
        }else if (poztrud == 2){
            std::cout << "1-100\n";
        }else if (poztrud == 3){
            std::cout << "1-250\n";
        }

        // informuje czy cel jest wiekszy czy mniejszy od proby
        if (ilprob > 0){
            if(cel > proba){
                std::cout << "zgadywana liczba jest większa od " << proba << "\n";
            }else if(cel < proba){
                std::cout << "zgadywana liczba jest mniejsza od " << proba << "\n";
            }
        }

        std::cin >> proba; // pierwsza proba


        //sprawdzenie czy proba jest w przedziale poziomu trudnosci
        if(poztrud == 1){
            while(proba < 1 || proba > 50){
                std::cout << "\nwpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz\n";
                std::cin >> proba;
            }
        }else if (poztrud == 2){
            while(proba < 1 || proba > 100){
                std::cout << "\nwpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz\n";
                std::cin >> proba;
            }
        }else if (poztrud == 3){
            while(proba < 1 || proba > 250){
                std::cout << "\nwpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz\n";
                std::cin >> proba;
            }
        }

        //dodanie 1 do ilosci prob na koniec petli
        ilprob++;
    }

    czysci();

    std::cout << "dobrze! udało ci się zgadnąć liczbę " << cel << " w " << ilprob << " probach!\n";
    std::cout << "podaj swoje imię, aby dodać je do tablicy najlepszych wynikow\n";
    std::cin >> imie;

    

}

int main(){
    int wybortryb; // potrzebne do wybierania ekranu w menu

    //vectory
    std::vector<std::string> tabgracz;
    std::vector<int> tabproby;
    std::vector<std::string> tabtrud;
    

    //menu wyboru trybu (zapetla sie caly czas)
    while (1){
        czysci();

        wybortryb = 0;// resetuje zmienna wybortryb zeby dalo sie wejsc kilka razy pod rzad w wybrany ekran

        std::cout << "▒███████▒  ▄████  ▄▄▄      ▓█████▄  █    ██  ▄▄▄██▀▀▀        ▒███████▒  ▄████  ▄▄▄      ▓█████▄  █    ██  ██▓    ▄▄▄      " << "\n";
        std::cout << "▒ ▒ ▒ ▄▀░ ██▒ ▀█▒▒████▄    ▒██▀ ██▌ ██  ▓██▒   ▒██           ▒ ▒ ▒ ▄▀░ ██▒ ▀█▒▒████▄    ▒██▀ ██▌ ██  ▓██▒▓██▒   ▒████▄    " << "\n";
        std::cout << "░ ▒ ▄▀▒░ ▒██░▄▄▄░▒██  ▀█▄  ░██   █▌▓██  ▒██░   ░██           ░ ▒ ▄▀▒░ ▒██░▄▄▄░▒██  ▀█▄  ░██   █▌▓██  ▒██░▒██░   ▒██  ▀█▄  " << "\n";
        std::cout << "  ▄▀▒   ░░▓█  ██▓░██▄▄▄▄██ ░▓█▄   ▌▓▓█  ░██░▓██▄██▓            ▄▀▒   ░░▓█  ██▓░██▄▄▄▄██ ░▓█▄   ▌▓▓█  ░██░▒██░   ░██▄▄▄▄██ " << "\n";
        std::cout << "▒███████▒░▒▓███▀▒ ▓█   ▓██▒░▒████▓ ▒▒█████▓  ▓███▒           ▒███████▒░▒▓███▀▒ ▓█   ▓██▒░▒████▓ ▒▒█████▓ ░██████▒▓█   ▓██▒" << "\n";
        std::cout << "░▒▒ ▓░▒░▒ ░▒   ▒  ▒▒   ▓▒█░ ▒▒▓  ▒ ░▒▓▒ ▒ ▒  ▒▓▒▒░           ░▒▒ ▓░▒░▒ ░▒   ▒  ▒▒   ▓▒█░ ▒▒▓  ▒ ░▒▓▒ ▒ ▒ ░ ▒░▓  ░▒▒   ▓▒█░" << "\n";
        std::cout << "░░▒ ▒ ░ ▒  ░   ░   ▒   ▒▒ ░ ░ ▒  ▒ ░░▒░ ░ ░  ▒ ░▒░           ░░▒ ▒ ░ ▒  ░   ░   ▒   ▒▒ ░ ░ ▒  ▒ ░░▒░ ░ ░ ░ ░ ▒  ░ ▒   ▒▒ ░" << "\n";
        std::cout << "░ ░ ░ ░ ░░ ░   ░   ░   ▒    ░ ░  ░  ░░░ ░ ░  ░ ░ ░           ░ ░ ░ ░ ░░ ░   ░   ░   ▒    ░ ░  ░  ░░░ ░ ░   ░ ░    ░   ▒   " << "\n";
        std::cout << "  ░ ░          ░       ░  ░   ░       ░      ░   ░             ░ ░          ░       ░  ░   ░       ░         ░  ░     ░  ░" << "\n";
        std::cout << "░                           ░                                ░                           ░                                " << "\n";
        std::cout << "\n"; // 122 whitespace jakby co
        std::cout << "                            wcisnij odpowiedni przycisk zeby wybrac, zatwierdz klawiszem enter                            " << "\n";
        
        //pokazuje opcje tabela wynikow dopiero jesli vector nie jest pusty
        if(tabgracz.size() > 0 && tabproby.size() > 0 && tabtrud.size() > 0){
            std::cout << "                                     (1)ROZPOCZNIJ GRĘ(1)        (2)TABELA WYNIKOW(2)                                     " << "\n"; 
        }else{
            std::cout << "                                                 (1)ROZPOCZNIJ GRĘ(1)                                                 " << "\n";
        }
        
        //input wybor trybu
        std::cin >> wybortryb;

        if(wybortryb == 1){
            // zmienne z funkcji glownagra, zmienione po referencji
            int proby;
            std::string gracz;
            int trud;

            //odpalanie glownejgry i wyciaganie z niej jej zmiennych przy uzyciu referencji
            glownagra(gracz, proby, trud);

            //konwersja z int na string poziomu trudnosci
            std::string strtrud = konwertertrud(trud); 
            
            // dodawanie wyniku z gry do vectorow
            tabgracz.push_back(gracz);
            tabproby.push_back(proby);
            tabtrud.push_back(strtrud);
        }   

        // caly drugi ekran z tabela wynikow mozna odpalic dopiero jesli w vektorze cos jest
        if(wybortryb == 2 && tabgracz.size() > 0 && tabproby.size() > 0 && tabtrud.size() > 0){
            czysci();

            int tabext = 1; // trzeba bylo dodac ze warte jest 1, bo na 0 wychodzi i nie dalo sie wrocic do ekranu. 

            while(tabext != 0){

                std::cout << "                                ▄▄▄█████▓ ▒█████   ██▓███       █████▒██▓ ██▒   █▓▓█████                                  " << "\n";
                std::cout << "                                ▓  ██▒ ▓▒▒██▒  ██▒▓██░  ██▒   ▓██   ▒▓██▒▓██░   █▒▓█   ▀                                  " << "\n";
                std::cout << "                                ▒ ▓██░ ▒░▒██░  ██▒▓██░ ██▓▒   ▒████ ░▒██▒ ▓██  █▒░▒███                                    " << "\n";
                std::cout << "                                ░ ▓██▓ ░ ▒██   ██░▒██▄█▓▒ ▒   ░▓█▒  ░░██░  ▒██ █░░▒▓█  ▄                                  " << "\n";
                std::cout << "                                  ▒██▒ ░ ░ ████▓▒░▒██▒ ░  ░   ░▒█░   ░██░   ▒▀█░  ░▒████▒                                 " << "\n";
                std::cout << "                                  ▒ ░░   ░ ▒░▒░▒░ ▒▓▒░ ░  ░    ▒ ░   ░▓     ░ ▐░  ░░ ▒░ ░                                 " << "\n";
                std::cout << "                                    ░      ░ ▒ ▒░ ░▒ ░         ░      ▒ ░   ░ ░░   ░ ░  ░                                 " << "\n";
                std::cout << "                                  ░      ░ ░ ░ ▒  ░░           ░ ░    ▒ ░     ░░     ░                                    " << "\n";
                std::cout << "                                             ░ ░                      ░        ░     ░  ░                                 " << "\n";
                std::cout << "                                                                      ░                                                   " << "\n";
                std::cout << "\n";

                

                for(int i = 0; i < 5 ; i++){
                    std::cout << "                    "; //20 whitespace
                    std::cout << i+1 << ". ";
                    std::cout << "gracz: " << tabgracz[i];
                    std::cout << " ilość prob: " << tabproby[i];
                    std::cout << " poziom trudności: " << tabtrud[i];
                    std::cout << "\n";
                }
                std::cout << "                                                      (0)wyjdz(0)                                                         " << "\n";

                std::cin >> tabext;

            }

        }
    } 
    
}


                   

