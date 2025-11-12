/*siemanko. mozesz dziwic sie czemu czesto tutaj cos dziwnie wyglada, albo mozesz dziwic sie, ze cos daloby sie napisac o wiele lepiej z uzyciem zmiennych. juz tlumacze dlaczego tak jest: wszystko dla stylu! przez to jak ten projekt koniec koncow wyglada, wymiary wszystkiego w terminalu musialy sie zgadzac co do joty zeby
zadna rura nie poszla poza swoje miejsce. dlatego tez przy zwyklym tekscie jest czesto tyle spacji!
no i tyle ze wstepu, peace out ~ TmP*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // biblioteka od randomowosci
#include <ctime> // biblioteka dla time (tez potrzebne do rand)

#include "glownagra.hpp"
#include "ascii.hpp"
#include "reszta-funkcji.hpp"

int main(){
    std::string wybortryb; // potrzebne do wybierania ekranu w menu

    //vectory
    std::vector<std::string> tabgracz;
    std::vector<int> tabproby;
    std::vector<std::string> tabtrud;
    

    //menu wyboru trybu (zapetla sie caly czas)
    while (1){
        czysci();

        belka();        
        scianka();
        tytul(); // pokazuje ekran tytulowy ascii
        scianka();
        std::cout << "|                               wpisz odpowiednia komende zeby wybrac, zatwierdz klawiszem enter                               |" << "\n";
        
        //pokazuje opcje tabela wynikow dopiero jesli vector nie jest pusty
        if(tabgracz.size() > 0 && tabproby.size() > 0 && tabtrud.size() > 0){
            std::cout << "|                            start - ROZPOCZNIJ GRĘ   tabela - TABELA WYNIKOW   wyjdz - WYJDZ Z GRY                            |" << "\n"; 
        }else{
            std::cout << "|                                        start - ROZPOCZNIJ GRĘ   wyjdz - WYJDZ Z GRY                                          |" << "\n";
        }
        scianka();
        belka();
        
        //input wybor trybu
        std::cin >> wybortryb;

        if(wybortryb == "start"){

            
            // zmienne z funkcji glownagra, zmienione po referencji
            int proby;
            std::string gracz;
            std::string trud;
            bool przegrana;

            //odpalanie glownejgry i wyciaganie z niej jej zmiennych przy uzyciu referencji
            glownagra(gracz, proby, trud, przegrana);

            if(przegrana != true){
                // dodawanie wyniku z gry do vectorow (tylko jesli gracz nie przegral)
                tabgracz.push_back(gracz);
                tabproby.push_back(proby);
                tabtrud.push_back(trud);
            }
        }   

        // caly drugi ekran z tabela wynikow mozna odpalic dopiero jesli w vektorze cos jest
        if(wybortryb == "tabela" && tabgracz.size() > 0 && tabproby.size() > 0 && tabtrud.size() > 0){
            czysci();

            std::string tabokno = "latwy"; //ustawia domyslnie, ze pojawia sie ekran latwych wynikow 

            while(tabokno != "wyjdz"){

                czysci();

                belka();
                scianka();
                topfive(); // pokazuje ascii napis top five
                scianka();
                

                if(tabokno != "latwy" && tabokno != "sredni" && tabokno != "trudny" && tabokno != "wyjdz"){ // dzieki temu nie mozna wpisywac innych tabeli niz te ktore istnieja
                    tabokno = "latwy"; // domyslnie ustawia na latwy
                }
                //info o poziomie
                std::cout << "|                                            aktualnie wyswietlam tabele dla: " << tabokno << "                                           ";
                if (tabokno == "latwy") std::cout << " "; //piszemy takie rzeczy zeby szata graficzna sie zgadzala
                std::cout << "|\n"; // zakonczenie tego wiersza

                scianka();
                belka();
                
                std::cout << "\n"; // estetyka

                //sortowanie wedlug najlepszego wyniku po probach
                std::vector<int> indx(tabproby.size());
                for(int i = 0; i < indx.size(); i++){
                    indx[i] = i; // ustawia wartosci vectora indx jako indexy ( [0,1,2] itp )
                }
                

                std::sort(indx.begin(), indx.end(), [&](int a, int b) { // a i b to indexy ktore bedziesz porownywac, [&] po prostu referencjuje wszystko dookola, zeby funkcja miala dostep poza swoim scopem.
                    return tabproby[a] < tabproby[b]; // tutaj dzieje sei sortowanie, jezeli liczba pod indexem a jest mniejsza niz b, a idzie przed b. 
                });

                //jakby co to mega dlugo sie nad tym meczylem, zdecydownie najciezsza czesc calej gierki poki co XD jakby vector byl tylko jeden to luz, ale ze wszystkie trzy musza sie zgadzac to juz masakra byla
                
                int top = 0; // musi istniec zeby pokazywalo max 5 wynikow, nie wiecej
                //printowanie max top 5
                for(int i = 0; i < indx.size() && top < 5 ; i++){
                    int j = indx[i]; // to jest posortowany indeks, to od niego bedziemy dawali wlasciwym wyswietleniom.
                    if(tabtrud[j] == tabokno){
                        std::cout << "                                                    "; //52 whitespacoy
                        std::cout << top + 1 << ".\n";
                        std::cout << "                                                      "; //54 whitespacy
                        std::cout << "gracz: " << tabgracz[j] << "\n";
                        std::cout << "                                                      ";
                        std::cout << "ilość prob: " << tabproby[j] << "\n";
                        
                        top++;
                    }
                }

                //wyswietla sie jesli nie ma wyniku dla danego poziomu trudnosci. napisane w ten (dosyc glupi) sposob, zeby rameczka sie zgadzala.
                if (top == 0 && tabokno == "latwy"){
                    std::cout << "                                            brak wynikow dla poziomu latwego                                              " << "\n";
                }else if (top == 0 && tabokno == "sredni"){
                    std::cout << "                                            brak wynikow dla poziomu sredniego                                            " << "\n";
                }else if (top == 0 && tabokno == "trudny"){
                    std::cout << "                                            brak wynikow dla poziomu trudnego                                             " << "\n";
                }
                
                std::cout << "\n"; // estetyka
                
                belka();
                scianka();
                std::cout << "|                                 wybierz poziom trudnosci dla jakiego chcesz zobaczyc tabele:                                 |" << "\n";
                std::cout << "|                                                    latwy | sredni | trudny                                                   |" << "\n";
                scianka();
                std::cout << "|                              zapisz - ZAPISZ WYNIKI DO PLIKU   wczytaj - WCZYTAJ WYNIKI Z PLIKU                              |\n";
                std::cout << "|                                               wyjdz - POWROT DO MENU GLOWNEGO                                                |" << "\n";
                belka();
                
                //sluchanie wyjscia, jezeli wpisane bedzie exit to wrocimy do menu, inaczej powinno wyswietlic dobra tabele
                std::cin >> tabokno;

                //zapisywanie wynikow do pliku po wpisaniu zapisz
                if(tabokno == "zapisz"){
                    zapiszwynik(tabgracz, tabproby, tabtrud);
                
                    std::cin >> tabokno;
                }
                //wczytywanie wynikow z pliku po wpisaniu wczytaj
                if(tabokno == "wczytaj"){
                    wczytajwynik(tabgracz,tabproby,tabtrud);

                    std::cin >> tabokno;
                }
            }

        }

        //wyjscie z gry
        if(wybortryb == "wyjdz"){
            return 0;
        }
    } 
    
}