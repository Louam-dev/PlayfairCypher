//
// Created by Amura Luigi on 15/04/2021.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playfair.h"

void printHelp() {
    printf("Different Features: \n");
    printf("Encoding n files:   playfair encode <keyfile> <outputdir> <file1> .. <filen>  \n");
    printf("Decoding n files:   playfair decode <keyfile> <outputdir> <file1> .. <filen> \n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printHelp();
        exit(1);
    }
    if (strcmp(argv[1], "encode") == 0) {
        int i=4;
        while (argv[i]!=NULL) {
            playfairEncode(argv[2], argv[i], argv[3]);
            printf("Encode complete\n");
            i++;
        }
    } else if (strcmp(argv[1], "decode") == 0) {
        int j=4;
        while ((argv[j]!=NULL)) {
            playfairDecode(argv[2], argv[j], argv[3]);
            printf("Decode complete\n");
            j++;
        }
    } else perror("Wrong command, select encode or decode\n");
}
