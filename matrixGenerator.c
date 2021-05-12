//
// Created by Amura Luigi on 20/11/2020.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrixGenerator.h"

/*
 * Funzione utilizzata per rimuovere i caratteri doppi dalla chiave
 */
char *manipulateKey (char *key){
    int pos=1;
    int isDelete=0;
    while(pos<=strlen(key)){
        isDelete=0;
        for (int i = 0; i < pos ; i++) {
            if (key[pos] == key[i]) {
                for (int j = pos + 1; j <=strlen(key); j++) {
                    key[j - 1] = key[j];
                }
                isDelete=1;
            }
        }
        if(isDelete==0) pos++;
    }return key;
}


/*
 * Funzione utilizzata per ricomporre l'alfabeto rispettando le posizioni delle lettere della chiave
 * rimuovendo le i caratteri gia presenti nella chiave dai rimanenti nell'alfabeto
*/
char *generateAlphabetWithKey(char *key, char *alphabet) {
    int i = 0;
    for(int x=0;x<strlen(key);x++) {
        while (i < strlen(alphabet)){
            if (key[x] == alphabet[i]) {
                for (int j = i + 1; j <= strlen(alphabet); j++) {
                    alphabet[j - 1] = alphabet[j];
                }
                break;
            }
            else i++;
        }
        i=0;
    }
    char *text = calloc(strlen(key)+strlen(alphabet)+1,sizeof(char));
    if(text!=NULL){
        strcpy(text, key);
        strcat(text, alphabet);
    }
    return text;
}


/*
 * questa funzione genera una matrice 5x5 popolandola con l'alfabeto manipolato secondo l'ordine di configurazione
 */
char **matrixGenerate(char *alphabet) {
    char **mat = calloc(5,sizeof(char *));
    if (mat != NULL) {
        for (int i = 0; i < 5; i++) {
            mat[i] = malloc( sizeof(char)*5);
        }
        int counter=0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                mat[i][j]=alphabet[counter];

                counter++;
            }
        }
    }
    return mat;
}


/*
 * dealloca la matrice
 */
void deallocateMatrix(char **matrix) {
    for (int i = 0; i < 5; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
