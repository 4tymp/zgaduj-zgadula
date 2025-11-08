#include <iostream>
#include <string>

int poziomtrudnosci(){ //funkcja difficulty picker
    int trudnosc;
    std::string textrudnosc;
    std::string potwierdztrudnosc = "n";

    while(potwierdztrudnosc != "t" && potwierdztrudnosc != "T" && potwierdztrudnosc != "y" && potwierdztrudnosc != "Y" ){
        std::cout << "wybierz poziom trudności:\n";
        std::cout << "(1)łatwy(1)   (2)średni(2)   (3)trudny(3)\n";

        std::cin >> trudnosc;
        
        //sprawdza czy trudnosci sa w odpowiednim zakresie, wymusza wpisanie odpowiedniej liczby
        while(trudnosc < 1 || trudnosc > 3){     
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
        std::cout << "wybrałeś " << textrudnosc << " poziom trudności.\n";
        std::cout << "zgadza się? t/n\n";
        std::cin >> potwierdztrudnosc;

    }
    return trudnosc;
}

int main(){
    //zbiorowisko zmiennych
    int cel; //cel w ktory bedziemy strzelac
    int ilprob = 1; // ilosc prob zgadniecia, domyslnie 1.
    int proba; // tutaj beda podstawiane proby zgadywania.

    //poczatek kodu,
    int poztrud = poziomtrudnosci();

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

        std::cout << "ilość prób: " << ilprob << "\n";
        std::cout << "zgadnij liczbę w przedziale ";

        if(poztrud == 1){
            std::cout << "1-50\n";
        }else if (poztrud == 2){
            std::cout << "1-100\n";
        }else if (poztrud == 3){
            std::cout << "1-250\n";
        }

        std::cin >> proba;

        ilprob++;
    }

    std::cout << "dobrze! udało ci się zgadnąć liczbę " << cel << " w " << ilprob << " probach!\n";
    

}