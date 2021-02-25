#include "ROT13.h"
#include <ctype.h>
#include <stddef.h>

char* chiffre_ROT13(
    char* clair)    // Texte en clair qui sera modifié.
{
    int i = 0;
    while(clair[i] != '\0') // Pour chaque caractère
    {
        if(islower(clair[i]))
        {
            clair[i] = (clair[i] - 'a'); // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            clair[i] = clair[i] + 13; // On chiffre (+ 13)
            clair[i] = clair[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            clair[i] = clair[i] + 'a'; // On reconvertit en lettre
        }
        else if(isupper(clair[i]))
        {
            clair[i] = (clair[i] - 'A'); // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            clair[i] = clair[i] + 13; // On chiffre (+ 13)
            clair[i] = clair[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            clair[i] = clair[i] + 'A'; // On reconvertit en lettre
        }
        i++;
    }
    return clair;
}

char* dechiffre_ROT13(
    char* chiffre)  // Texte chiffré qui sera modifié.
{
    int i = 0;
    while(chiffre[i] != '\0') // Pour chaque caractère
    {
        if(islower(chiffre[i]))
        {
            chiffre[i] = (chiffre[i] - 'a'); // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            chiffre[i] = chiffre[i] - 13; // On déchiffre (- 13)
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] + 'a'; // On reconvertit en lettre
        }
        else if(isupper(chiffre[i]))
        {
            chiffre[i] = (chiffre[i] - 'A'); // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            chiffre[i] = chiffre[i] - 13; // On déchiffre (- 13)
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] + 'A'; // On reconvertit en lettre
        }
        i++;
    }
    return chiffre;
}
