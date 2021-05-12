//
// Created by Amura Luigi on 15/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileIO.h"


KeyFile *readKeyFile(char *file) {
    KeyFile *keyFile =(KeyFile *) calloc(1, sizeof(*keyFile));
    keyFile->char_mancante=' ';
    keyFile->char_speciale=' ';
    keyFile->char_sostituto=' ';
    keyFile->alfabeto=calloc(25,sizeof(char ));
    keyFile->chiave=calloc(strlen(file)-25-6,sizeof(char));
    for (int i = 0; i < 25; i++) {
        strncat(keyFile->alfabeto, &file[i], 1);
    }

    keyFile->char_sostituto = file[26];
    keyFile->char_speciale = file[28];

    char *realAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int trovato = 0;

    for (int i = 0; i < 26; i++) {
        trovato = 0;
        for (int x = 0; x < 25; ++x) {
            if (file[x] == realAlphabet[i]) {
                trovato = 1;
                break;
            }
        }
        if (trovato == 0) {
            keyFile->char_mancante= realAlphabet[i];
            break;
        }
    }

    //char *key = calloc(, sizeof(char) * strlen(file) - 30);
    int j = 30;
    unsigned int lenght = strlen(file) - 1;
    while (j != lenght) {
        strncat(keyFile->chiave, &file[j], 1);
        j++;
    }
    return keyFile;
}

char *fileToString(char *fileInput) {
    FILE *fileIn = fopen(fileInput, "r+");
    if (fileIn == NULL) {
        perror("Could not open file");
        exit(1);
    }
    fseek(fileIn, 0, SEEK_END);
    long length = ftell(fileIn);
    rewind(fileIn);
    char *str = (char *) calloc(length +1, sizeof(char));
    if (str != NULL) {
        fread(str, length, 1, fileIn);
    }

    fclose(fileIn);
    return str;
}

void stringToFile(char *fileOutput, char *string) {
    FILE *fileOut = fopen(fileOutput, "w+");
    if (fileOut == NULL) {
        perror("Could not open file");
        exit(1);
    }
    fputs(string, fileOut);
    fclose(fileOut);
}

char *appendNamefileToPath(char *outputDir, char *fileDir) {
    long pos = strlen(fileDir);
    while (fileDir[pos] != '\\') {
        pos--;
    }
    pos++;
    unsigned int length = strlen(fileDir) - pos;
    char *nameFile =calloc(length+1,sizeof(char));

    for (int j = pos; j < pos + length; j++) {
        if (fileDir[j] == '.') {
            break;
        }
        strncat(nameFile, &fileDir[j], 1);
    }
    if (outputDir[strlen(outputDir)] != '\\') {
        strncat(outputDir, "\\", 1);
    }
    strncat(outputDir, nameFile, length);

      free(nameFile);
    return outputDir;
}


void writeEncodedFile(char *fileOutput, char *text) {
    strncat(fileOutput, ".pf", 3);
    stringToFile(fileOutput, text);
}

void writeDecodedFile(char *fileOutput, char *text) {
    strncat(fileOutput, ".dec", 4);
    stringToFile(fileOutput, text);
}