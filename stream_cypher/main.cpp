#include <iostream>
#include "stream_cyp.h"



int main(){


    std::string input_file, output_file;
    char choice;
    unsigned int seed;


    std::cout<<"Chcete siftovat nebo desifrovat? S/D ";
    std::cin>>choice;

    if(choice == 'S' || choice == 's'){
        std::cout<<"Zadejte nazev souboru k sifrovani: ";
        std::cin>>input_file;
        std::cout<<"Zadejte seed: ";
        std::cin>>seed;
        output_file = input_file;
        int length = output_file.length();
        int tecka = output_file.find('.', 0);
        output_file.erase(tecka);
        std::cout<<output_file<<std::endl;
        output_file.append(".bin");
        std::cout<<output_file<<std::endl;


        xor_cypher(input_file, output_file, seed);


    }else if(choice == 'D' || choice == 'd'){
        std::cout<<"Zadejte nazev souboru k desifrovani: ";
        std::cin>>input_file;
        std::cout<<"Zadejte seed: ";
        std::cin>>seed;
        std::string pripona;
        std::cout<<"Zadejte typ souboru (napr.: jpg): ";
        std::cin>>pripona;
        output_file = input_file;
        int length = output_file.length();
        int tecka = output_file.find('.', 0);
        output_file.erase(tecka);
        std::cout<<output_file<<std::endl;
        output_file.append("_desifrovano.");

        output_file.append(pripona);
        std::cout<<output_file<<std::endl;

        
        
        xor_cypher(input_file, output_file, seed);

    }else std::cout<<"Nebyla zvolena volba :("<<std::endl;



    

    return 0;
}