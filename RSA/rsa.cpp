#include "rsa.h"



unsigned int NSD(unsigned int a, unsigned int b) {   //eukliduv algoritmus
    while (b != 0) {
        unsigned int zbytek = a % b;
        a = b;
        b = zbytek;
    }
    return a;
}


bool nesoudelna(unsigned int a, unsigned int b){
    return NSD(a,b) == 1;  // pokud je NSD 1, vrátí true
}


void generovani_prvocisel(int &p, int &q){   //Erathosenovo sito
    srand(time(NULL));
    int max_cislo = 1000;  
    std::vector<int> prvocisla;
    std::vector<bool> sito(max_cislo + 1, true); // nastavím všechny hodnoty 0 - max_cislo na true
    

    for(int i = 2; i<= sqrt(max_cislo); i++){

        if(sito[i] == true){
            for (int j = 2 * i; j <= max_cislo; j += i) {   // nastaví násobky daného čísla na false == nemohou být prvočísla
                sito[j] = false;     
            }  
        }
    }

for(int i = 100; i<=max_cislo; i++){
        if(sito[i] == true) prvocisla.push_back(i);  // do vektoru dá jenom prvocisla > 100
    }


    do{
        p = prvocisla[rand()%prvocisla.size()];    // načtu si prvočísla < 100
        q = prvocisla[rand()%prvocisla.size()];
    }while(p == q);         // kontrola že nejsou stejná
}


void generovani_klice(){  // Rozsireny Eukliduv algoritmus

    
    int p = 0, q = 0;
    generovani_prvocisel(p,q);
   
    unsigned int N = p*q; // verejny klic
    unsigned int FiN = (p-1) * (q-1);   //bude vždy sude
    unsigned int exponent;  // verejny klic
    unsigned int key_priv;  //privatni klic

    for(int i = 3; i<FiN; i = i+2){         // potrebuju nesoudelne liche cislo mezi 1 a FiN, sude by bylo soudelne
        if(nesoudelna(i,FiN) == true){      // male cislo je zadouci, aby to nebylo narocne na procesor, (v praxi se pouziva 65537 = 0x10000000000000001 ; dobre pro mocneni)
            exponent = i;
            break;
        }
    }

    long long zbytek_old, zbytek_new, koeficient_old, koeficient_new, podil, pom;  // eukliduv algoritmus
    
    zbytek_old = FiN;
    zbytek_new = exponent;
    koeficient_old = 0;
    koeficient_new = 1;

    while(zbytek_new > 0){
        podil = zbytek_old /zbytek_new;

        pom = zbytek_new;
        zbytek_new = zbytek_old - (podil * zbytek_new);
        zbytek_old = pom;

        pom = koeficient_new;
        koeficient_new = koeficient_old - (podil * koeficient_new);
        koeficient_old = pom;
    }
    
    if(koeficient_old<0) koeficient_old += FiN;
    key_priv = koeficient_old;
    
    std::cout<<"Verejny klic: "<<exponent<<" Privatni klic: "<<key_priv<<" Modulo: "<<N<<std::endl;

}




unsigned long long sifrovani(unsigned long long cislo, unsigned long long exponent, unsigned long long N){

    unsigned long long vysledek = 1;
    cislo = cislo % N; 

    while (exponent > 0) {                 //vzdy mocnim vysledek predchoziho mocneni, ne opakovane zaklad
        
        if (exponent % 2 == 1) {   // pokud je exponent lichy, vynasobime vysledek zakladem (vysledek = cislo^1)
            vysledek = (vysledek * cislo) % N;
        }
        
        
        exponent = exponent >> 1; // exponent celociselne vydelime 2 (usekneme posledni bit)
        
        
        cislo = (cislo * cislo) % N; // umocnime cislo^2, udelame modulo, aby nedoslo k overflow
    }
    return vysledek;
    


}

