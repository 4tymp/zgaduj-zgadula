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
    
    //poczatek kodu,
    int poztrud = poziomtrudnosci();
    // dokoncz bro
    std::cout << "poziom wybrany " << poztrud << "\n";
    

}