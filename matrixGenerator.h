//
// Created by Amura Luigi on 15/04/2021.
//


#ifndef PLAYFAIR_MATRIXGENERATOR_H
#define PLAYFAIR_MATRIXGENERATOR_H

/*
 * Funzione utilizzata per rimuovere i caratteri doppi dalla chiave
 */
char *manipulateKey (char *key);

/*
 * Funzione utilizzata per generare la sequenza di 25 caratteri dell'alfabeto rispettando l'ordine di configurazione
 * (prima le lettere della chiave, poi le restanti dell'alfabeto non presenti nella chiave)
 */
char *generateAlphabetWithKey(char *key, char *alphabet);

void deallocateText(char *text);

/*
 * Funzione utilizzata per generare una matrice 5x5 contenente i caratteri dell'alfabeto ORDINATO secondo l'ordine di configurazione
 */
char **matrixGenerate(char *alphabet);

/*
 * Funzione utilizzata per deallocare lo spazio utilizzato dalla matrice
 */
void deallocateMatrix(char **matrix);
#endif //PLAYFAIR_MATRIXGENERATOR_H
