# Projekt_2semestr
Programy pro sifrovani v C++, seminarni projekt do 2. semestru

Tento repozitář obsahuje 4 šifrovací programy, kreté jsem dělal do semestrálního projektu
Každý soubor má main, hlavičkové soubory a popř. i soubor k otestování programu

1.  Analýza a prolomení klasických šifer
  -  Implementace Caesarovy a Vigenèrovy šifry + prolomení na zálkadě frekvenční analýzy
  -  Možnost šifrování a dešifrování Caesarovou i Vigenèrovou šifrou, možnost prolomení obou šifer.
  -  Program se postupně ptá, jakou si zvolíte šifrovací metodu a co chcete se souborem dělat.    
   

2. Binární transformace a XOR šifrování
  - Nástroj pro šifrování libovolných souborů pomocí bitové operace XOR a generování pseudo-náhodných sekvencí
  - Program binárně šifruje pomocí seedu, vrátí binární soubor(dá se přejmenovat na např .jpg a ujistit se, že nejde otevřít), přiložen obrázek k otestování
  - Následně pomocí stejného seedu dešifrujete vytvořený soubor a zvolíte příponu, vytvoří se dešifrovaný soubor

3.  Algoritmus pro zjištění integrity dat (Hashe)
  - Vlastní hashovací funkce demonstrující lavinový efekt, determinismus. Program je schopen hash zjistit, jestli nebylo něco změněno
  - Program umí zjistit hash souboru a porvnat soubor s původním hashem, je přiložen textový soubor, kde to jde zkusit

4. Asymetrická kryptografie (RSA)
  - Matematické algoritmy (Eratosthenovo síto, rozšířený Eukleidův algoritmus) pro generování párů klíčů a simulace RSA šifrování na úrovni celých čísel
  - Máte možnost si vygenerovat klíče a možnost šifrovat/dešifrovat zprávu v podobě celého čísla
