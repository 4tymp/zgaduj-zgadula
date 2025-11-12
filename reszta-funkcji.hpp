#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void zapiszwynik(const std::vector<std::string> &gracz, const std::vector<int> &proby, const std::vector<std::string> &trudnosc);

void wczytajwynik(std::vector<std::string> &gracz, std::vector<int> &proby, std::vector<std::string> &trudnosc);

void czysci();

std::string losowawiadomosc(int los,int &proba);