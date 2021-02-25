#include "Cesar.h"
#include <ctype.h>
#include <stddef.h>

char* chiffre_Cesar(
    char* clair,        // Texte en clair qui sera modifié.
    char const cle)
{
    int i = 0;
    char c0; // Pour factoriser le code, on effectue le choix du caractère à soustraire en amont
    while(clair[i] != '\0') // Pour chaque caractère
    {
        if(islower(clair[i]))
            c0 = 'a';
        else if(isupper(clair[i]))
            c0 = 'A';
        if(c0) // Si l'objet est une lettre
        {
            clair[i] = clair[i] - c0; // On convertit le caractère en nombre ordinal (position dans l'alphabet)
            clair[i] = clair[i] + (cle - 'a'); // On chiffre (il faut également convertir la clé)
            clair[i] = clair[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            clair[i] = clair[i] + c0; // On reconvertit en lettre
        }
        i++;
        c0 = '\0';
    }
    return clair;
}

char* dechiffre_Cesar(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const cle)
{
    return NULL;
}
