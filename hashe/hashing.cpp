#include "hashing.h"

uint32_t hashing_algoritmus(std::string& input_file){

    uint32_t hash = 45317;
    unsigned char byte;
    std::ifstream input (input_file, std::ios::binary);

    if(!input.is_open()){
        std::cout<<"Chyba nacteni souboru"<<std::endl;
        return 1;
    }
      // posuny bitu:  hash<<2 == posun o 2 bity doleva || hash>>3 == posun o 3 doprava

    while(input.get((char&)byte)){  //implementovani hashe se souborem, bitove posuny a nasobeni prvocisly = lavinovy efekt
                                    // vzdy stejne operace = determinismus
        hash = hash ^ byte;  //XOR operace

        hash = (hash<<5) + hash;

        hash *= 137;

        hash = (hash>>3);
        hash *= 191;
        hash = (hash <<7) + hash;
        hash *= 73; 


    }



    input.close();
    return hash;
}