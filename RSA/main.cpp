#include <iostream>
#include "rsa.h"



int main(){

    char choice;
    unsigned long long cislo, exponent, modulo, sifra;

    std::cout<<"Chcete siftovat, desifrovat nebo vygenerovat klic: S/D/K"<<std::endl;
    std::cin>>choice;

    switch(choice){

        case 'S':
            std::cout<<"Zadejte kladne cele cislo k sifrovani, verejny klic a modulo: "<<std::endl;
            std::cin>>cislo>>exponent>>modulo;
            sifra = sifrovani(cislo, exponent, modulo);
            std::cout<<"Zasifrovane cislo je: "<<sifra<<std::endl;
            
            break;

        case 'D':
            std::cout<<"Zadejte kladne cele cislo k sifrovani, privatni klic a modulo: "<<std::endl;
            std::cin>>cislo>>exponent>>modulo;
            sifra = sifrovani(cislo, exponent, modulo);
            std::cout<<"Odsifrovane cislo je: "<<sifra<<std::endl;
            break;
        
        case 'K':
            generovani_klice();
            break;

       default:
            std::cout<<"Nevybrana moznost"<<std::endl;
            break;
    }


    return 0;
}