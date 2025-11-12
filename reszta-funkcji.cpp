#include "reszta-funkcji.hpp"

void czysci(){ // funkcja czyszczaca ekran ( portable! )
    for (int i=0;i<100;i++){
        std::cout << "\n";
    }
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