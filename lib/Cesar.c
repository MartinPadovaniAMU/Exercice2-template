#include "Cesar.h"
#include <ctype.h>
#include <stddef.h>

char* chiffre_Cesar(
    char* clair,        // Texte en clair qui sera modifié.
    char const cle)
{
    int i = 0;
    char c0 = '\0'; // Pour factoriser le code, on effectue le choix du caractère à soustraire en amont
    while(clair[i] != '\0') // Pour chaque caractère
    {
        if(islower(clair[i]))
            c0 = 'a';
        else if(isupper(clair[i]))
            c0 = 'A';
        else
            c0 = '\0';
        if(c0) // Si l'objet est une lettre
        {
            clair[i] = clair[i] - c0; // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            clair[i] = clair[i] + (cle - 'a'); // On chiffre (il faut également convertir la clé)
            clair[i] = clair[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            clair[i] = clair[i] + c0; // On reconvertit en lettre
        }
        i++;
    }
    return clair;
}

char* dechiffre_Cesar(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const cle)
{
    int i = 0;
    char c0; // Pour factoriser le code, on effectue le choix du caractère à soustraire en amont
    while(chiffre[i] != '\0') // Pour chaque caractère
    {
        if(islower(chiffre[i]))
            c0 = 'a';
        else if(isupper(chiffre[i]))
            c0 = 'A';
        else
            c0 = '\0';
        if(c0) // Si l'objet est une lettre
        {
            chiffre[i] = chiffre[i] - c0; // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            chiffre[i] = chiffre[i] - (cle - 'a'); // On chiffre (il faut également convertir la clé)
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] + c0; // On reconvertit en lettre
        }
        i++;
    }
    return chiffre;
}
