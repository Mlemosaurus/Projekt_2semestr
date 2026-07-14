#include "hashing.h"
#include <iostream>
#include <string>



int main(){

std::string input_file;
uint32_t hash_input;
char choice;

std::cout<<"Chcete zjistit integritu souboru, nebo hash? I/H: ";
std::cin>>choice;

if(choice == 'I' || choice =='i'){

    std::string second_file;
    uint32_t hash_second;



    std::cout<<"Zadejte prvni soubor overeni: ";
    std::cin>>input_file;

    std::cout<<"Zadejte puvodni hash souboru: ";
    std::cin>>std::hex>>hash_second;                //přetypování na hexadecimal

hash_input = hashing_algoritmus(input_file);

if(hash_input == hash_second){
    std::cout<<"Soubor je beze zmeny."<<std::endl;
}else{    
    std::cout<<"Soubor byl zmenen!"<<std::endl;
}

std::cout<<"Puvodni hash: "<<std::hex<<std::setfill('0')<<std::setw(8)<<hash_second<<std::endl;
std::cout<<"Novy hash: "<<std::hex<<std::setfill('0')<<std::setw(8)<<hash_input<<std::endl;



}else if(choice == 'H' || choice =='h'){

    std::cout<<"Zadejte soubor pro zjisteni hashe: ";
    std::cin>>input_file;


hash_input = hashing_algoritmus(input_file);

std::cout<<"hash: "<<std::hex<<std::setfill('0')<<std::setw(8)<<hash_input<<std::endl;     //nastavení velikosti na 8 znaků (32bitů na hex), doplnění nul před kdyby bylo málo


}else std::cout<<"Nevybrali jste moznost"<<std::endl;



    return 0;
}