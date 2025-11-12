#include "reszta-funkcji.hpp"
#include "ascii.hpp"

void czysci(){ // funkcja czyszczaca ekran ( portable! )
    for (int i=0;i<100;i++){
        std::cout << "\n";
    }
}

void zapiszwynik(const std::vector<std::string> &gracz, const std::vector<int> &proby, const std::vector<std::string> &trudnosc){
    std::ofstream plik("wyniki.txt"); // tworzy obiekt plik typu output file stream, otwiera (lub tworzy jezeli brak) plik wyniki.txt

    //sprawdzanie czy plik jest poprawnie otwarty
    if(plik.is_open() == false){
        belka();
        scianka();
        std::cout << "|                                            ! blad nie udalo sie zapisac wynikow !                                            |\n";
        scianka();
        belka();
        return; // konczy funkcje
    }
    
    //petla wypisujaca wyniki do pliku
    for (int i = 0; i < gracz.size(); i++){
        plik << gracz[i] << ";" << proby[i] << ";" << trudnosc[i] << "\n";
    }

    plik.close(); // zamkniecie pliku

    belka();
    scianka();
    std::cout << "|                                                  wyniki zapisano pomyslnie                                                   |\n";
    scianka();
    std::cout << "|                                           wybierz jakakolwiek opcje aby kontynuowac                                          |\n";
    scianka();
    belka();
    
}

void wczytajwynik(std::vector<std::string> &gracz, std::vector<int> &proby, std::vector<std::string> &trudnosc){
    //zmienne pozniej podpisujace odpowiednie dane do vectorow
    std::string wyngracz;
    int wynproby;
    std::string wyntrudnosc; 

    std::ifstream plik("wyniki.txt"); //otwiera plik z naczymi wynikami

    if(plik.is_open() == false){
        belka();
        scianka();
        std::cout << "|                                               ! nie udalo sie otworzyc pliku !                                               |\n";
        scianka();
        belka();
        return;
    }

    //czyszczenie wektorow dla pewnosci czystosci przed zaladowaniem
    gracz.clear();
    proby.clear();
    trudnosc.clear();

    

    std::string wiersz; //zmienna czytajaca kazdy wiersz z pliku ( a kazdy wiersz to jeden zapisany wynik )
    while(std::getline(plik,wiersz)){//wczytuje jedna linie (wiersz) z pliku
        //szukanie separatorow w linii (naszych ;)
        size_t pozycja1 = wiersz.find(";"); //nowy typ zmiennej! unsigned int, czyli moze pomiescic teoretycznie kazda liczbe (tak to rozumiem XD)
        size_t pozycja2 = wiersz.find(";", pozycja1 + 1) ;

        //wycinanie odpowiedniego fragmentu z pliku uzywajac substr od 0 (pierwszej pozycji) do wczenisje okreslonej pozycji
        wyngracz = wiersz.substr(0 , pozycja1);
        wynproby = std::stoi(wiersz.substr(pozycja1+1, pozycja2 - pozycja1 -1)); // stoi - konwersja tekstu na liczbe
        wyntrudnosc = wiersz.substr(pozycja2+1);
        
        //wrzucanie pobranych danych do vectorow
        gracz.push_back(wyngracz);
        proby.push_back(wynproby);
        trudnosc.push_back(wyntrudnosc);
    }

    //zamykanie pliku po odczycie
    plik.close();

    //info o udanym wczytaniu
    belka();
    scianka();
    std::cout << "|                                                  wyniki wczytano pomyslnie!                                                  |\n";
    scianka();
    std::cout << "|                                            podaj poziom trudnosci aby kontynuowac                                            |\n";
    scianka();
    belka();
}

std::string losowawiadomosc(int los,int &proba){
    std::string wiad;

    std::string strproba = std::to_string(proba);
    
    switch (los){ //ify istnieja po to, zeby rameczka sie zgadzala tylko i wylacznie xd(troche zaczynam siebie nienawidzic za te ramki)
        //za malo
        case 0:
        wiad = "|                                             pudło! podana liczba jest za mała...                                             |";
        break;
        case 1:
        wiad = "|                              pff, do celu jeszcze ci sporo brakuje! wszystko jeszcze przed tobą.                             |";
        break;
        case 2:
        if(proba > 99){
            wiad ="|                                     " + strproba + "? pierwsze slysze. musisz troche urosnac maluchu!                                     |";
        }else if(proba > 9){
            wiad ="|                                      " + strproba + "? pierwsze slysze. musisz troche urosnac maluchu!                                     |";
        }else{
            wiad ="|                                       " + strproba + "? pierwsze slysze. musisz troche urosnac maluchu!                                     |";
        }
        break;
        case 3:
        wiad = "|                               zeby wyruszyc w droge nalezy zebrac druzyne. twoja jest za mala.                               |";
        break;
        case 4:
        if(proba > 99){
            wiad = "|                                      musisz dodac do " + strproba + " zeby dostac to, czego szukasz.                                      |";
        }else if(proba > 9){
            wiad = "|                                      musisz dodac do " + strproba + " zeby dostac to, czego szukasz.                                       |";
        }else{
            wiad = "|                                       musisz dodac do " + strproba + " zeby dostac to, czego szukasz.                                       |";
        }
        break;
        case 5:
        if(proba > 99){
            wiad = "|                                              szukana liczba jest wieksza od " + strproba + "                                              |";
        }else if(proba > 9){
            wiad = "|                                               szukana liczba jest wieksza od " + strproba + "                                              |";
        }else{
            wiad = "|                                               szukana liczba jest wieksza od " + strproba + "                                               |";
        }
        break;
        case 6:
        
        if(proba > 99){
            wiad = "|                                                  " + strproba + " jest mniejsze od celu.                                                  |";
        }else if(proba > 9){
            wiad = "|                                                   " + strproba + " jest mniejsze od celu.                                                  |";
        }else{
            wiad = "|                                                   " + strproba + " jest mniejsze od celu.                                                   |";
        }
        break;
        case 7:
        wiad = "|                                                        za małoooooooo                                                        |";
        break;
        case 8:
        wiad = "|                                             cel tuz przed toba! nie poddawaj sie!                                            |";
        break;
        case 9:
        wiad = "|                                   nigdy nie zgadniesz. ale podpowiem, ze celujesz za nisko.                                  |";
        break;

        //za duzo
        case 10:
        wiad = "|                                             pudło! podana liczba jest za duza...                                             |";
        break;
        case 11:
        if(proba > 99){
            wiad = "|                             zagalopowales sie! " + strproba + "? zeby dojsc do celu musisz sie niezle cofnac                              |";
        }else if(proba > 9){
            wiad = "|                              zagalopowales sie! " + strproba + "? zeby dojsc do celu musisz sie niezle cofnac                              |";
        }else{
            wiad = "|                              zagalopowales sie! " + strproba + "? zeby dojsc do celu musisz sie niezle cofnac                               |";
        }
        break;
        case 12:
        if(proba > 99){
            wiad = "|                               " + strproba + "? przerosles swoj cel! nie wiem jak, ale musisz sie skurczyc!                               |";
        }else if(proba > 9){
            wiad = "|                               " + strproba + "? przerosles swoj cel! nie wiem jak, ale musisz sie skurczyc!                                |";
        }else{
            wiad = "|                                " + strproba + "? przerosles swoj cel! nie wiem jak, ale musisz sie skurczyc!                                |";
        }
        break;
        case 13:
        wiad = "|                           chcialbym dolaczyc do druzyny, ale twoja jest juz pelna i i tak za duza.                           |";
        break;
        case 14:
        if(proba > 99){
            wiad = "|                                      musisz odjac od " + strproba + " zeby dostac to, czego szukasz.                                      |";
        }else if(proba > 9){
            wiad = "|                                      musisz odjac od " + strproba + " zeby dostac to, czego szukasz.                                       |";

        }else{
            wiad = "|                                       musisz odjac od " + strproba + " zeby dostac to, czego szukasz.                                       |";
        }
        break;
        case 15:
        wiad = strproba + " jest wieksze od celu.";
        if(proba > 99){
            wiad = "|                                                  " + strproba + " jest wieksze od celu.                                                   |";
        }else if(proba > 9){
            wiad = "|                                                  " + strproba + " jest wieksze od celu.                                                    |";
        }else{
            wiad = "|                                                  " + strproba + " jest wieksze od celu.                                                    |";
        }
        break;
        case 16:
        if(proba > 99){
            wiad = "|                                             szukana liczba jest mniejsza od " + strproba + "                                              |";
        }else if(proba > 9){
            wiad = "|                                              szukana liczba jest mniejsza od " + strproba + "                                              |";
        }else{
            wiad = "|                                              szukana liczba jest mniejsza od " + strproba + "                                               |";
        }
        break;
        case 17:
        wiad = "|                                                       za duzoooooooooo                                                       |";
        break;
        case 18:
        wiad = "|                                              cel tuz za toba! nie poddawaj sie!                                              |";
        break;
        case 19:
        wiad = "|                                  nigdy nie zgadniesz. ale podpowiem, ze celujesz za wysoko.                                  |";
        break;
        default:
        wiad = "|                                                        błędna liczba!                                                        |";
        break;
    }

    return wiad;
}