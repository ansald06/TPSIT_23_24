/*
author: Ansaldi Francesco
date:
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20000
#define LUNG_RIGA 200

typedef struct {
    int n;
    char* titolo;
    char* genere;
    int anno_uscita;
    char* disponibilita;
} Film;


void cercaAnno(int anno_scelta, Film array_film[], int cont){
    for(int k=0;k<cont;k++){
        if(anno_scelta==array_film[k].anno_uscita){
            printf("%d %s %s %d %s\n",array_film[k].n,array_film[k].titolo,array_film[k].genere,array_film[k].anno_uscita,array_film[k].disponibilita);
        }
    }
}

int main() {
    Film array_film[DIM];
    char fileName[]="./listafilm.csv";
    char riga[LUNG_RIGA];
    FILE* fp;
    char* campo;
    int cont=0;
    int scelta;
    fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("Il file non esiste! \n");
        exit(1);
    }
    while(fgets(riga,LUNG_RIGA,fp)){
        campo=strtok(riga,",");
        array_film[cont].n=atoi(campo);
        campo=strtok(NULL,",");
        array_film[cont].titolo=strdup(campo);
        campo=strtok(NULL,",");
        array_film[cont].genere=strdup(campo);
        campo=strtok(NULL,",");
        array_film[cont].anno_uscita=atoi(campo);
        campo=strtok(NULL,",");
        array_film[cont].disponibilita=strdup(campo);
        cont++;
    }
    
    printf("Inserisci un anno: \n");
    scanf("%d",&scelta);
    cercaAnno(scelta,array_film,cont);
    return 0;
}
