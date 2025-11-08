#include <iostream>
#include <string>
#include <cstdlib> // biblioteka od randomowosci
#include <ctime> // biblioteka dla time (tez potrzebne do rand)

void czysci(){ // funkcja czyszczaca ekran ( portable! )
    for (int i=0;i<50;i++){
        std::cout << "\n";
    }
}

int poziomtrudnosci(){ //funkcja difficulty picker
    int trudnosc;
    std::string textrudnosc;
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

        //ustawia odpowiedni string w zaleznosci od podanego poziomu trudnosci.
        if(trudnosc == 1){
            textrudnosc = "łatwy";
        }else if(trudnosc == 2){
            textrudnosc = "średni";
        }else if(trudnosc == 3){
            textrudnosc = "trudny";
        }

        //potwierdzenie wyboru
        std::cout << "\nwybrałeś " << textrudnosc << " poziom trudności.\n";
        std::cout << "zgadza się? t/n\n";
        std::cin >> potwierdztrudnosc;

    }
    return trudnosc;
}

int main(){
    //zbiorowisko zmiennych
    int cel; //cel w ktory bedziemy strzelac
    int ilprob = 0; // ilosc prob zgadniecia
    int proba = 0; // tutaj beda podstawiane proby zgadywania.

    //poczatek kodu

    int poztrud = poziomtrudnosci(); // wpisanie poziomu trudnosci z funkcji do zmiennej poztrud
    
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

    std::cout << "dobrze! udało ci się zgadnąć liczbę " << cel << " w " << ilprob << " probach!\n";
    

}