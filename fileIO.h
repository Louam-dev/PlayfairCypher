//
// Created by Amura Luigi on 15/04/2021.
//

#ifndef PLAYFAIR_FILEIO_H
#define PLAYFAIR_FILEIO_H

typedef struct keyFile{
    char *alfabeto;
    char char_mancante;
    char char_speciale;
    char char_sostituto;
    char *chiave;
}KeyFile;


// Funzione utilizzata per generare una KeyFile con le informazioni contenute nel file della chiave
KeyFile *readKeyFile(char *file);


//Funzione utilizzata per generare il path del file di output concatenando la dir di output, con il nome del file
char *appendNamefileToPath(char *outputDir, char *fileDir);
/*
  Funzione utilizzata per convertire una sequenza di caratteri in  un file.
 */
void stringToFile(char *fileOutput, char *string);

/*
  Funzione per convertire qualsiasi tipo di file in una sequenza di caratteri.
 */
char *fileToString(char *fileInput);


//Funzione utilizzata per generare il file codificato con la sua estensione .pf
void writeEncodedFile(char *fileOutput, char *text);
/*
 * Funzione utilizzata per generare il file decodificato con la sua estensione .dec
 */
void writeDecodedFile(char *fileOutput, char *text);

#endif //PLAYFAIR_FILEIO_H
