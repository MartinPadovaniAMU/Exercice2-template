#include "Vigenere.h"
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

char* chiffre_Vigenere(
    char* clair,        // Texte en clair qui sera modifié.
    char const* cle)
{
    int i = 0;
    int j = 0;
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
            clair[i] = clair[i] + (cle[j++ % strlen(cle)] - 'a'); // On chiffre (il faut également convertir la clé et en faire un tableau circulaire)
            clair[i] = clair[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            clair[i] = clair[i] + c0; // On reconvertit en lettre
        }
        i++;
    }
    return clair;
}

char* dechiffre_Vigenere(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const* cle)
{
    int i = 0;
    int j = 0;
    char c0 = '\0'; // Pour factoriser le code, on effectue le choix du caractère à soustraire en amont
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
            chiffre[i] = chiffre[i] - (cle[j++ % strlen(cle)] - 'a'); // On chiffre (il faut également convertir la clé et en faire un tableau circulaire)
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] % 26; // Si la lettre est à la fin de l'alphabet, on revient au début
            chiffre[i] = 25 - chiffre[i]; // Inversion de l'ordre des lettres pour faire fonctionner le modulo
            chiffre[i] = chiffre[i] + c0; // On reconvertit en lettre
        }
        i++;
    }
    return chiffre;
}

void chiffre_Vigenere_flux_texte(
    FILE* chiffre,      // Flux de sortie.
    FILE* clair,        // Flux d'entrée.
    char const* cle)
{
    char buffer[1000]; // Taille arbitraire, convient largement pour notre exemple
    char* text = malloc(1*sizeof(char));
    int taille_derniere_ligne = 0;
    while(fgets(buffer, 1000, clair))
    {
        text = realloc(text, (strlen(buffer) + taille_derniere_ligne + 1)*sizeof(char)); // Augmente la taille du texte au fur et à mesure de la lecture
        text[strlen(buffer) + taille_derniere_ligne] = '\0';
        strcpy(text + taille_derniere_ligne, buffer); // On copie la nouvelle ligne après les autres
        taille_derniere_ligne = taille_derniere_ligne + strlen(buffer);
    }
    fputs(chiffre_Vigenere(text, cle), chiffre);
}

void dechiffre_Vigenere_flux_texte(
    FILE* clair,        // Flux de sortie.
    FILE* chiffre,      // Flux d'entrée.
    char const* cle)
{
    char buffer[1000]; // Taille arbitraire, convient largement pour notre exemple
    char* text = malloc(1*sizeof(char));
    int taille_derniere_ligne = 0;
    while(fgets(buffer, 1000, chiffre))
    {
        text = realloc(text, (strlen(buffer) + taille_derniere_ligne + 1)*sizeof(char)); // Augmente la taille du texte au fur et à mesure de la lecture
        text[strlen(buffer) + taille_derniere_ligne] = '\0';
        strcpy(text + taille_derniere_ligne, buffer); // On copie la nouvelle ligne après les autres
        taille_derniere_ligne = taille_derniere_ligne + strlen(buffer);
    }
    fputs(dechiffre_Vigenere(text, cle), clair);
}
