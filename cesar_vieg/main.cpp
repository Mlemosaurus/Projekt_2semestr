#include <iostream>
#include <string>
#include <fstream>
#include "sifrovani.h"




int main(){

    char choice;
    std::string soubor;
    

    std::cout<<"Chcete pouzit Caesarovu nebo Vigenerovu sifru: C/V"<<std::endl;
    std::cin>>choice;

    if(choice == 'C' || choice == 'c'){
         std::cout<<"Chcete sifrovat, desifrovat nebo prolomit: S/D/P"<<std::endl;
        std::cin>>choice;
        int klic;
        switch (choice)
        {
        case 'S':
            std::cout<<"Zadejte nazev souboru a klic: "<<std::endl;
            std::cin>>soubor>>klic;
            caesar_encrypt(soubor, klic);
            break;
        case 'D':
            std::cout<<"Zadejte nazev souboru a klic: "<<std::endl;
            std::cin>>soubor>>klic;
            caesar_decrypt(soubor, klic);
            break;
        case 'P':
            std::cout<<"Zadejte nazev souboru: "<<std::endl;
            std::cin>>soubor;
            caesar_decrypt(soubor, crack_caesar(soubor));
            break;
        
        default:
            std::cout<<"Nevybrali jste moznost"<<std::endl;
            break;
        }

    }else if(choice == 'V' || choice == 'v'){
        std::cout<<"Chcete sifrovat, desifrovat nebo prolomit: S/D/P"<<std::endl;
        std::cin>>choice;
        std::string klic;

        switch (choice)
        {
        case 'S':
            std::cout<<"Zadejte nazev souboru a klic: "<<std::endl;
            std::cin>>soubor>>klic;
            vigener_encrypt(soubor, klic);
            break;
        case 'D':
            std::cout<<"Zadejte nazev souboru a klic: "<<std::endl;
            std::cin>>soubor>>klic;
            vigener_decrypt(soubor, klic);
            break;
        case 'P':
            std::cout<<"Zadejte nazev souboru: "<<std::endl;
            std::cin>>soubor;
             crack_veigner(soubor);
            break;
        
        default:
            std::cout<<"Nevybrali jste moznost"<<std::endl;
            break;
        }


    }else std::cout<<"Nevybrali jste moznost"<<std::endl;
    
  
    std::cout<<"Hotovson"<<std::endl;


    return 0;
}


    
