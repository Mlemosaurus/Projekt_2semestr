#pragma once
#include <string>


void caesar_encrypt(std::string soubor, int klic);
void caesar_decrypt(std::string soubor, int klic);
int crack_caesar(std::string soubor);
void vigener_encrypt(std::string soubor, std::string slovo);
void vigener_decrypt(std::string soubor, std::string slovo);
int crack_caesar_string(std::string text, int &vystupni_klic, char pismeno);
std::string substring(const std::string text, int odhad_klic, int index);
void crack_veigner(std::string soubor);