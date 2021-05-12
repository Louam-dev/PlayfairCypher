//
// Created by Amura Luigi on 16/04/2021.
//

#ifndef PLAYFAIR_PLAYFAIR_H
#define PLAYFAIR_PLAYFAIR_H


void playfairEncode(char *keyDir, char *fileDir, char *outputDir);
void playfairDecode(char *keyDir, char *fileDir, char *outputDir);

/*
 * Funzione utilizzata per manipolare il testo da codificare, secondo quanto descritto nella chiave
 */
void textManipulate(char *text, char specialChar,char missingChar, char substitute);

/*
 * Funzione utilizzata per generare il testo codificato a partire da un testo manipolato e la matrice
 */
char *encode(char *preparedText, char **matrix);

/*
 * Funzione utilizzata per generare il testo decodificato a partire da un testo e la matrice
 */
char *decode(char *cryptedText, char **matrix);



#endif //PLAYFAIR_PLAYFAIR_H
