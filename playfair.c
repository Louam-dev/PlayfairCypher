//
// Created by Amura Luigi on 16/04/2021.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include "matrixGenerator.h"
#include "playfair.h"

void removeSpace(char *text) {
    int i = 0;
    while (i < strlen(text)) {
        if (text[i] == ' ') {
            for (int j = i + 1; j <= strlen(text); j++) {
                text[j - 1] = text[j];
            }
        } else i++;
    }
}


//determino quante occorrenze di doppie ci sono nel testo cosi da sapere quanto allocare per la stringa con i caratteri speciali
void insertSpecialChar(char *text, char specialChar) {
    char temp1;
    char temp2;
    for (int i = 0; i < strlen(text); i++) {
        if (i % 2 == 0) {
            if (text[i] == text[i + 1]) {
                text[i + 1] = specialChar;
                temp1 = text[i + 2];
                text[i + 2] = text[i];
                for (int j = i + 3; j < strlen(text) + 1; j++) {
                    temp2 = text[j];
                    text[j] = temp1;
                    temp1 = temp2;

                }
            }
        }
    }
    if (strlen(text) % 2 == 1) {
        int len = strlen(text);
        text[len] = specialChar;
        text[len + 1] = '\0';
    }
}

void substituteMissingChar(char miss, char sub, char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == miss) {
            str[i] = sub;
        }
    }
}

void textManipulate(char *text, char specialChar, char missingChar, char substitute) {
    removeSpace(text);
    substituteMissingChar(missingChar, substitute, text);
    insertSpecialChar(text, specialChar);
}


void firstRuleEncode(char *encodedText, int xFirst, int yFirst, int xSecond, int ySecond, char **matrix) {
    if (ySecond == 4) {
        strncat(encodedText, &matrix[xFirst][yFirst + 1], 1);
        strncat(encodedText, &matrix[xSecond][ySecond - 4], 1);
        strncat(encodedText, " ", 1);
    } else if (yFirst == 4) {
        strncat(encodedText, &matrix[xFirst][yFirst - 4], 1);
        strncat(encodedText, &matrix[xSecond][ySecond + 1], 1);
        strncat(encodedText, " ", 1);
    } else {
        strncat(encodedText, &matrix[xFirst][yFirst + 1], 1);
        strncat(encodedText, &matrix[xSecond][ySecond + 1], 1);
        strncat(encodedText, " ", 1);
    }
}

void secondRuleEncode(char *encodedText, int xFirst, int yFirst, int xSecond, int ySecond, char **matrix) {
    if (xSecond == 4) {
        strncat(encodedText, &matrix[xFirst + 1][yFirst], 1);
        strncat(encodedText, &matrix[xSecond - 4][ySecond], 1);
        strncat(encodedText, " ", 1);
    } else if (xFirst == 4) {
        strncat(encodedText, &matrix[xFirst - 4][yFirst], 1);
        strncat(encodedText, &matrix[xSecond + 1][ySecond], 1);
        strncat(encodedText, " ", 1);
    } else {
        strncat(encodedText, &matrix[xFirst + 1][yFirst], 1);
        strncat(encodedText, &matrix[xSecond + 1][ySecond], 1);
        strncat(encodedText, " ", 1);
    }
}

void thirdRuleEncode(char *encodedText, int xFirst, int yFirst, int xSecond, int ySecond, char **matrix) {
    strncat(encodedText, &matrix[xFirst][ySecond], 1);
    strncat(encodedText, &matrix[xSecond][yFirst], 1);
    strncat(encodedText, " ", 1);
}


char *encode(char *preparedText, char **matrix) {
    unsigned int spaces = strlen(preparedText) / 2;
    char *encodedText = calloc(strlen(preparedText) + spaces, sizeof(char));
    int xFirst = 0;
    int yFirst = 0;
    int xSecond = 0;
    int ySecond = 0;
    int x = 0;
    for (; x < strlen(preparedText); x++) {
        if (x % 2 == 1) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (preparedText[x] == matrix[i][j]) {
                        xSecond = i;
                        ySecond = j;
                    }
                    if (preparedText[x - 1] == matrix[i][j]) {
                        xFirst = i;
                        yFirst = j;
                    }
                }
            }
            if (xFirst == xSecond) {
                firstRuleEncode(encodedText, xFirst, yFirst, xSecond, ySecond, matrix);
            } else if (yFirst == ySecond) {
                secondRuleEncode(encodedText, xFirst, yFirst, xSecond, ySecond, matrix);
            } else if (xFirst != xSecond && yFirst != ySecond) {
                thirdRuleEncode(encodedText, xFirst, yFirst, xSecond, ySecond, matrix);
            }
        }
    }
    return encodedText;
}


void firstRuleDecode(char *decodedText, int xFirst, int yFirst, int xSecond, int ySecond, char **matrix) {
    if (yFirst == 0) {
        strncat(decodedText, &matrix[xFirst][yFirst + 4], 1);
        strncat(decodedText, &matrix[xSecond][ySecond - 1], 1);
        strncat(decodedText, " ", 1);
    } else if (ySecond == 0) {
        strncat(decodedText, &matrix[xFirst][yFirst - 1], 1);
        strncat(decodedText, &matrix[xSecond][ySecond + 4], 1);
        strncat(decodedText, " ", 1);
    } else {
        strncat(decodedText, &matrix[xFirst][yFirst - 1], 1);
        strncat(decodedText, &matrix[xSecond][ySecond - 1], 1);
        strncat(decodedText, " ", 1);
    }
}

void secondRuleDecode(char *decodedText, int xFirst, int yFirst, int xSecond, int ySecond, char **matrix) {
    if (xFirst == 0) {
        strncat(decodedText, &matrix[xFirst + 1][yFirst], 1);
        strncat(decodedText, &matrix[xSecond - 1][ySecond], 1);
        strncat(decodedText, " ", 1);
    } else if (xSecond == 0) {
        strncat(decodedText, &matrix[xFirst - 1][yFirst], 1);
        strncat(decodedText, &matrix[xSecond + 4][ySecond], 1);
        strncat(decodedText, " ", 1);
    } else {
        strncat(decodedText, &matrix[xFirst - 1][yFirst], 1);
        strncat(decodedText, &matrix[xSecond - 1][ySecond], 1);
        strncat(decodedText, " ", 1);
    }
}

void thirdRuleDecode(char *decodedText, int xFirst, int yFirst, int xSecond, int ySecond, char **matrix) {
    strncat(decodedText, &matrix[xFirst][ySecond], 1);
    strncat(decodedText, &matrix[xSecond][yFirst], 1);
    strncat(decodedText, " ", 1);
}

char *decode(char *cryptedText, char **matrix) {
    int xFirst = 0;
    int yFirst = 0;
    int xSecond = 0;
    int ySecond = 0;
    char *decodedText = calloc(strlen(cryptedText)+1, sizeof(char));

    for (int x = 0; x < strlen(cryptedText); x++) {
        if (cryptedText[x] == ' ') {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (cryptedText[x - 1] == matrix[i][j]) {
                        xSecond = i;
                        ySecond = j;
                    }
                    if (cryptedText[x - 2] == matrix[i][j]) {
                        xFirst = i;
                        yFirst = j;
                    }
                }
            }
            if (xFirst == xSecond) {
                firstRuleDecode(decodedText, xFirst, yFirst, xSecond, ySecond, matrix);
            } else if (yFirst == ySecond) {
                secondRuleDecode(decodedText, xFirst, yFirst, xSecond, ySecond, matrix);
            } else if (xFirst != xSecond && yFirst != ySecond) {
                thirdRuleDecode(decodedText, xFirst, yFirst, xSecond, ySecond, matrix);
            }// else {
             //  perror("Malformed encrypted text");
            //}
        }
    }
    return decodedText;
}


void playfairEncode(char *keyDir, char *fileDir, char *outputDir) {
    KeyFile *key = readKeyFile(fileToString(keyDir));
    char *text = fileToString(fileDir);
    char *outputPath = calloc(strlen(fileDir)+3,sizeof(char ));
    strcpy(outputPath,outputDir);
    outputPath = appendNamefileToPath(outputPath, fileDir);
    textManipulate(text, key->char_speciale, key->char_mancante, key->char_sostituto);
    char **matrix = matrixGenerate(generateAlphabetWithKey(manipulateKey(key->chiave), key->alfabeto));
    writeEncodedFile(outputPath, encode(text, matrix));
    deallocateMatrix(matrix);
    free(key);
}

void playfairDecode(char *keyDir, char *fileDir, char *outputDir) {
    KeyFile *key = readKeyFile(fileToString(keyDir));
    char *text = fileToString(fileDir);
    char *outputPath = calloc(strlen(fileDir)+1,sizeof(char ));
    strcpy(outputPath,outputDir);
    outputPath = appendNamefileToPath(outputPath, fileDir);
    char **matrix = matrixGenerate(generateAlphabetWithKey(manipulateKey(key->chiave), key->alfabeto));
    writeDecodedFile(outputPath, decode(text, matrix));
    free(text);
    deallocateMatrix(matrix);
    free(key);
}