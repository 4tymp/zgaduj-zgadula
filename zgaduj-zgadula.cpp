#include <iostream>
#include <string>

std::string poziomtrudnosci(){ //funkcja difficulty picker
    int trudnosc;
    std::string textrudnosc;

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
    return textrudnosc;
}

int main(){
    //zbiorowisko zmiennych
    std::string textrudnosc, rozpoczynacz;
    std::string potwierdztrudnosc;
    

    //poczatek kodu,
    poziomtrudnosci();

    //potwierdzenie wyboru
    std::cout << "wybrałeś " << textrudnosc << " poziom trudności.\n";
    std::cout << "zgadza się? y/n\n";
    std::cin >> potwierdztrudnosc;
    if (potwierdztrudnosc == "n" || potwierdztrudnosc == "N"){
        poziomtrudnosci();
    }else if (potwierdztrudnosc == "y" || potwierdztrudnosc == "Y"){
        std::cout << "rozpoczynamy!";
    }
    
    //DOKONCZ TO BO NIE DZIALA PETLA JAKAS CZY COS??
    

}