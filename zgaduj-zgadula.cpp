/*siemanko. mozesz dziwic sie czemu czesto tutaj cos dziwnie wyglada, albo mozesz dziwic sie, ze cos daloby sie napisac o wiele lepiej z uzyciem zmiennych. juz tlumacze dlaczego tak jest: wszystko dla stylu! przez to jak ten projekt koniec koncow wyglada, wymiary wszystkiego w terminalu musialy sie zgadzac co do joty zeby
zadna rura nie poszla poza swoje miejsce. dlatego tez przy zwyklym tekscie jest czesto tyle spacji!
no i tyle ze wstepu, peace out ~ TmP*/

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

std::string losowawiadomosc(int los,int &proba){
    std::string wiad;

    std::string strproba = std::to_string(proba);
    
    switch (los){
        //za malo
        case 0:
        wiad = "pudło! podana liczba jest za mała...";
        break;
        case 1:
        wiad = "pff, do celu jeszcze ci sporo brakuje! wszystko jeszcze przed tobą.";
        break;
        case 2:
        wiad = strproba + "? pierwsze slysze. musisz troche urosnac maluchu!";
        break;
        case 3:
        wiad = "zeby wyruszyc w droge nalezy zebrac druzyne. twoja jest za mala.";
        break;
        case 4:
        wiad = "musisz dodac do " + strproba + " zeby dostac to, czego szukasz.";
        break;
        case 5:
        wiad = "szukana liczba jest wieksza od " + strproba;
        break;
        case 6:
        wiad = strproba + " jest mniejsze od celu.";
        break;
        case 7:
        wiad = "za małoooooooo";
        break;
        case 8:
        wiad = "cel tuz przed toba! nie poddawaj sie!";
        break;
        case 9:
        wiad = "nigdy nie zgadniesz. ale podpowiem, ze celujesz za nisko.";
        break;

        //za duzo
        case 10:
        wiad = "pudło! podana liczba jest za duza...";
        break;
        case 11:
        wiad = "zagalopowales sie! " + strproba + "? zeby dojsc do celu musisz sie niezle cofnac";
        break;
        case 12:
        wiad = strproba + "? przerosles swoj cel! nie wiem jak, ale musisz sie skurczyc!";
        break;
        case 13:
        wiad = "chcialbym dolaczyc do druzyny, ale twoja jest juz pelna i i tak za duza.";
        break;
        case 14:
        wiad = "musisz odjac od " + strproba + " zeby dostac to, czego szukasz.";
        break;
        case 15:
        wiad = strproba + " jest wieksze od celu.";
        break;
        case 16:
        wiad = "szukana liczba jest mniejsza od " + strproba;
        break;
        case 17:
        wiad = "za duzooooooooo";
        break;
        case 18:
        wiad = "cel tuz za toba! nie poddawaj sie!";
        break;
        case 19:
        wiad = "nigdy nie zgadniesz. ale podpowiem, ze celujesz za wysoko.";
        break;
        default:
        wiad = "błędna liczba!";
        break;
    }

    return wiad;
}

std::string poziomtrudnosci(){ //funkcja difficulty picker
    std::string trudnosc;
    std::string potwierdztrudnosc = "n";

    while(potwierdztrudnosc != "t" && potwierdztrudnosc != "T" && potwierdztrudnosc != "y" && potwierdztrudnosc != "Y" ){
        czysci();
        
        std::cout << "                                                  wpisz poziom trudności:                                                 " << "\n";
        std::cout << "                                                  latwy | sredni | trudny                                                 " << "\n";

        std::cin >> trudnosc;
        
        //sprawdza czy trudnosci sa w odpowiednim zakresie, wymusza wpisanie odpowiedniego stringa
        while(trudnosc != "latwy" &&  trudnosc != "sredni" && trudnosc != "trudny"){   
            czysci(); 
            std::cout << "                                              wybrano błędny poziom trudności                                             " << "\n";                
            std::cout << "                                            podaj poziom trudności jeszcze raz                                            " << "\n";
            std::cin >> trudnosc;
        }
        
        //potwierdzenie wyboru
        czysci();
        std::cout << "                                             wybrałeś " << trudnosc << " poziom trudności                                             ";
        if(trudnosc == "latwy") std::cout << " "; //zrobione zeby szata graficzna sie zgadzala
        std::cout  << "\n\n";
        std::cout << "                                                      zgadza się? t/n                                                     " << "\n";
        std::cin >> potwierdztrudnosc;

    }
    return trudnosc;
}

// glowna funkcja gry zgadywania
void glownagra(std::string &imie, int &ilprob, std::string &poztrud){// referencje, dzieki nim w mainie beda dostepne zmienne z tej funkcji!
    
    //zbiorowisko zmiennych
    int cel; //cel w ktory bedziemy strzelac
    int proba = 0; // tutaj beda podstawiane proby zgadywania.

    //poczatek kodu
    czysci();

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

    // rozpoczecie zgadywania
    while(proba != cel){
        czysci();// clearowanie terminala

        // podaje ilosc prob
        std::cout << "ilość prób: " << ilprob << "\n\n";

        //prosi o zgadniecie liczby w odpowiednim przedziale
        std::cout << "zgadnij liczbę w przedziale ";
        if(poztrud == "latwy"){
            std::cout << "1-50\n";
        }else if (poztrud == "sredni"){
            std::cout << "1-100\n";
        }else if (poztrud == "trudny"){
            std::cout << "1-250\n";
        }

        // informuje czy cel jest wiekszy czy mniejszy od proby
        int loswiad; // losowa wiadomosc
        if (ilprob > 0){
            if(cel > proba){
                loswiad = rand() % 10;  
            }else if(cel < proba){
                loswiad = rand() % 10 + 10;
            }
            std::cout << losowawiadomosc(loswiad, proba) << "\n";
        }

        std::cin >> proba; // pierwsza proba


        //sprawdzenie czy proba jest w przedziale poziomu trudnosci
        if(poztrud == "latwy"){
            while(proba < 1 || proba > 50){
                std::cout << "\nwpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz\n";
                std::cin >> proba;
            }
        }else if (poztrud == "sredni"){
            while(proba < 1 || proba > 100){
                std::cout << "\nwpisałeś liczbę poza przedziałem, podaj liczbę jeszcze raz\n";
                std::cin >> proba;
            }
        }else if (poztrud == "trudny"){
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
    std::string wybortryb; // potrzebne do wybierania ekranu w menu

    //vectory
    std::vector<std::string> tabgracz;
    std::vector<int> tabproby;
    std::vector<std::string> tabtrud;
    

    //menu wyboru trybu (zapetla sie caly czas)
    while (1){
        czysci();

        

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
        std::cout << "                             wpisz odpowiednia komende zeby wybrac, zatwierdz klawiszem enter                             " << "\n";
        
        //pokazuje opcje tabela wynikow dopiero jesli vector nie jest pusty
        if(tabgracz.size() > 0 && tabproby.size() > 0 && tabtrud.size() > 0){
            std::cout << "                                   start - ROZPOCZNIJ GRĘ   tabela - TABELA WYNIKOW                                   " << "\n"; 
        }else{
            std::cout << "                                               start - ROZPOCZNIJ GRĘ                                                 " << "\n";
        }
        
        //input wybor trybu
        std::cin >> wybortryb;

        if(wybortryb == "start"){
            // zmienne z funkcji glownagra, zmienione po referencji
            int proby;
            std::string gracz;
            std::string trud;

            //odpalanie glownejgry i wyciaganie z niej jej zmiennych przy uzyciu referencji
            glownagra(gracz, proby, trud);

            
            // dodawanie wyniku z gry do vectorow
            tabgracz.push_back(gracz);
            tabproby.push_back(proby);
            tabtrud.push_back(trud);
        }   

        // caly drugi ekran z tabela wynikow mozna odpalic dopiero jesli w vektorze cos jest
        if(wybortryb == "tabela" && tabgracz.size() > 0 && tabproby.size() > 0 && tabtrud.size() > 0){
            czysci();

            std::string tabokno = "latwy"; //ustawia domyslnie, ze pojawia sie ekran latwych wynikow 

            while(tabokno != "wyjdz"){

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

                //info o poziomie
                std::cout << "                                          aktualnie wyswietlam tabele dla: " << tabokno << "                                         ";
                if (tabokno == "latwy") std::cout << " "; //piszemy takie rzeczy zeby szata graficzna sie zgadzala
                std::cout << "\n";
                
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
                        std::cout << "                                                 "; //49 whitespacow
                        std::cout << i+1 << ".\n";
                        std::cout << "                                                    ";
                        std::cout << "gracz: " << tabgracz[j] << "\n";
                        std::cout << "                                                     ";
                        std::cout << "ilość prob: " << tabproby[j] << "\n";
                        std::cout << "                                                      ";
                        std::cout << "poziom trudności: " << tabtrud[j] << "\n";
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
                
                std::cout << "                               wybierz poziom trudnosci dla jakiego chcesz zobaczyc tabele:                               " << "\n";
                std::cout << "                                                  latwy | sredni | trudny                                                 " << "\n";

                std::cout << "\n"; //estetyka

                std::cout << "                                             wyjdz - POWROT DO MENU GLOWNEGO                                              " << "\n";
                
                //sluchanie wyjscia, jezeli wpisane bedzie exit to wrocimy do menu, inaczej powinno wyswietlic dobra tabele
                std::cin >> tabokno;

            }

        }
    } 
    
}