# include "stream_cyp.h"


#include <iostream>
#include <string>
#include <fstream>
#include <random>

void xor_cypher(std::string& input_file, std::string& ouptut_file, unsigned int seed){

std::ifstream input (input_file, std::ios::binary);         //otevru soubory binarne
std::ofstream output (ouptut_file, std::ios::binary);

if(!input.is_open() || !output.is_open()){

std::cout<<"Soubory se nepodarilo otevrit"<<std::endl;
return;

}


std::mt19937 key(seed);    // generuje pseudo-náhodný klíč podle seedu
    
std::uniform_int_distribution<int> distribute(0, 255);     // Potřebujeme bajty v rozsahu 0 až 255

char change_byte;

while(input.get(change_byte)){

    unsigned char key_byte = distribute(key); //vygenerování dalšího bytu ze sekvence

    char output_byte = change_byte ^ key_byte; // XOR: (A^B)^B = A    == dvakrat aplikuji stejný bity -> puvodni bity
        
        // Zapíšeme do výstupního souboru
        output.put(output_byte);
}



input.close();
output.close();
std::cout<<"hotovson"<<std::endl;

};


