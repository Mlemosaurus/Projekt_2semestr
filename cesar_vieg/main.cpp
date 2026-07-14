#include <iostream>
#include <string>
#include <fstream>
#include "sifrovani.h"




int main(){

   //caesar_encrypt("hobbit.txt", 3);
   //caesar_decrypt("encrypted.txt", -2);
    //caesar_decrypt("encrypted.txt", crack_caesar("encrypted.txt"));

    vigener_encrypt("hobbit.txt", "plec");
   // vigener_decrypt("encrypted.txt", "Lopata");
   crack_veigner("encrypted.txt");
    std::cout<<"Hotovson"<<std::endl;


    return 0;
}


    