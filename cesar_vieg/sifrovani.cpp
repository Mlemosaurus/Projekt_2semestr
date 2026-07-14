#include "sifrovani.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>



void caesar_encrypt(std::string soubor, int klic){

    char znak;
    std::ifstream input(soubor);
    std::ofstream output("encrypted.txt");

     if(!(input.is_open()) || !(output.is_open())){
        std::cout<<"chyba pri otevirani souboru"<<std::endl;
    }else {

       while(input.get(znak)){

        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            znak = (znak + klic);
            znak = (znak >= 0) ? znak%26 : (znak+26)%26;
            znak +=65;

        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            znak = (znak + klic);
             znak = (znak >= 0) ? znak%26 : (znak+26)%26;
            znak +=97;

        }

            output<<znak;
        }        

       }
       
       input.close();
       output.close();

    }

void caesar_decrypt(std::string soubor, int klic){

    char znak;
    std::ifstream input(soubor);
    std::ofstream output("decrypted.txt");

     if(!(input.is_open()) || !(output.is_open())){
        std::cout<<"chyba pri otevirani souboru"<<std::endl;
    }else {

       while(input.get(znak)){

        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            znak = (znak - klic);
            znak = (znak < 0) ? (znak+26)%26 : znak%26;
            znak +=65;

        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            znak = (znak - klic);
            znak = (znak < 0) ? (znak+26)%26 : znak%26;
            znak +=97;

        }

            output<<znak;
        }        

       }
       
       input.close();
       output.close();

    }           

int crack_caesar(std::string soubor){

    char znak;
    int key;
    unsigned int cetnost[26] = {0};   //unsigned char málo <3
    std::ifstream input(soubor);

     if(!(input.is_open())){
        std::cout<<"chyba pri otevirani souboru"<<std::endl;
        return -1;
    }else {

       while(input.get(znak)){

        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            cetnost[znak] ++;

        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            cetnost[znak] ++;

        }

        }    
        
        int max_cetnost = cetnost[0];
        int max_index = 0;

        
        for(int i =1; i<26; i++){     //najdu nejcetnejsi prvek
            
            if(cetnost[i] > max_cetnost){
                max_cetnost = cetnost[i];
                max_index = i;
            } 
        }

        key = (max_index - 4); // 4 jako e, coz je nejcastejsi pismeno
        key = (key < 0) ? (key+26)%26 : key%26;

       }
       
       input.close();

       return key;

    }

void vigener_encrypt(std::string soubor, std::string slovo){

    char znak;
    int pozice =0;
    int delka = slovo.length();
    int klic = 0;

    std::ifstream input(soubor);
    std::ofstream output("encrypted.txt");

     if(!(input.is_open()) || !(output.is_open())){
        std::cout<<"chyba pri otevirani souboru"<<std::endl;
    }else {

        for(int i =0; i <delka; i++){   //prevod hesla na male pismena
            if(slovo[i]>= 65 && slovo[i] <=90) {
                slovo[i] = slovo[i] + 32;}
        }

       while(input.get(znak)){

        
        klic = slovo[pozice] -97;


        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            znak = (znak + klic);
            znak = (znak >= 0) ? znak%26 : (znak+26)%26;
            znak +=65;

            pozice = (pozice + 1)%delka;

        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            znak = (znak + klic);
             znak = (znak >= 0) ? znak%26 : (znak+26)%26;
            znak +=97;

            pozice = (pozice + 1)%delka;

        }

            output<<znak;
        }        

       }
       
       input.close();
       output.close();

}

void vigener_decrypt(std::string soubor, std::string slovo){

char znak;
int pozice =0;
int delka = slovo.length();
int klic = 0;

    std::ifstream input(soubor);
    std::ofstream output("decrypted.txt");

     if(!(input.is_open()) || !(output.is_open())){
        std::cout<<"chyba pri otevirani souboru"<<std::endl;
    }else {

        for(int i =0; i <delka; i++){   //prevod hesla na male pismena
            if(slovo[i]>= 65 && slovo[i] <=90) {
                slovo[i] = slovo[i] + 32;}
        }

       while(input.get(znak)){
            

        klic = slovo[pozice] -97;


        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            znak = (znak - klic);
            znak = (znak < 0) ? (znak+26)%26 : znak%26;
            znak +=65;

            pozice = (pozice + 1)%delka;

        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            znak = (znak - klic);
            znak = (znak < 0) ? (znak+26)%26 : znak%26;
            znak +=97;

            pozice = (pozice + 1)%delka;


        }

            output<<znak;


        }        

       }
       
       input.close();
       output.close();


}

int crack_caesar_string(std::string text, int &vystupni_klic, char pismeno){

    char znak;
    int key;
    unsigned int cetnost[26] = {0};   //unsigned char málo <3
    int pozice = 0;

    
       while((pozice < text.length())){

        znak = text.at(pozice);
        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            cetnost[znak] ++;
        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            cetnost[znak] ++;

        }
            pozice++;

        }    
        
        int max_cetnost = cetnost[0];
        int max_index = 0;

        
        for(int i =1; i<26; i++){     //najdu nejcetnejsi prvek
            
            if(cetnost[i] > max_cetnost){
                max_cetnost = cetnost[i];
                max_index = i;
            } 
        }

       int pismeno_index = pismeno - 'a';
       key = (max_index - pismeno_index); // zalezi na vstupnim pismenu, nejcasteji e a t
        vystupni_klic = (key < 0) ? (key+26)%26 : key%26;

       return max_cetnost;
}

std::string substring(const std::string text, int odhad_klic, int index){

    std::string vysledek = "";
    int pozice = 0;

    for(char znak : text){
        if((znak >='A' && znak <= 'Z') ||(znak >='a' && znak <= 'z') ){
            if(pozice % odhad_klic == index){
                vysledek += znak;
            }
            pozice++;
        }
    }
    return vysledek;
}

void crack_veigner(std::string soubor){

    std::ifstream input(soubor);
    std::ofstream output("decrypted.txt");
    int delka = 0;
    double max_skore = 0.0;
    int odhad_klic;
    std::string slovo;
    int pozice = 0;
    std::string radek;
    std::string cely_text;
    std::string podstring;
    double max_avg_skore = 0.0;

    
     if(!(input.is_open()) || !(output.is_open())){
        std::cout<<"chyba pri otevirani souboru"<<std::endl;
    }else {
        
        while(std::getline(input,radek)){  //cely text ve stringu
        cely_text += radek + "\n";
        }
            input.close();


        for(int i =1; i<=15;i++){
            double suma_skore = 0.0;
            int valid_podstring = 0;

            for(int j = 0; j<i;j++){
            podstring = substring(cely_text, i,j);
            if(podstring.length() < 10) continue;
            int cetnost = crack_caesar_string(podstring,odhad_klic, 'e');

            double skore = (double)cetnost / podstring.length();
            suma_skore += skore;
            valid_podstring++;
            }

            if(valid_podstring > 0){
                double avg_skore = suma_skore / valid_podstring;

                if (avg_skore > max_avg_skore * 1.05) {   //násobky dékly hesla mrdaj s frekvencí
                max_avg_skore = avg_skore;
            delka = i;
            }
         
           }

        }

        std::cout<<"Odhad delky slova: "<<delka<<std::endl;

        std::string top1 = "", top2 = "", top3 = "";
        


        for(int i = 0; i<delka; i++){

            podstring = substring(cely_text, delka,i);

            crack_caesar_string(podstring, odhad_klic, 'e');
            top1 += (odhad_klic + 'a');
            
            crack_caesar_string(podstring, odhad_klic, 't');
            top2 += (odhad_klic + 'a');

            crack_caesar_string(podstring, odhad_klic, 'a');
            top3 += (odhad_klic + 'a');

            
                }
                
            
      std::cout << "1. nejlepsi odhad: " << top1 << std::endl;
        std::cout << "2. nejlepsi odhad: " << top2 << std::endl;
        std::cout << "3. nejlepsi odhad: " << top3 << std::endl;

        std::cout << "Zadej rucne opravene heslo: ";
        std::cin >> slovo;
        }



    

 

       for(char znak : cely_text){
            

        int klic = slovo[pozice] -97;


        if( znak >=65 && znak <= 90){   //uppercase
            znak -= 65;
            znak = (znak - klic);
            znak = (znak < 0) ? (znak+26)%26 : znak%26;
            znak +=65;

            pozice = (pozice + 1)%delka;

        }else if(znak >=97 && znak <= 122){  //lowercase

            znak -= 97;
            znak = (znak - klic);
            znak = (znak < 0) ? (znak+26)%26 : znak%26;
            znak +=97;

            pozice = (pozice + 1)%delka;


        }

            output<<znak;


        }

    output.close();
}


