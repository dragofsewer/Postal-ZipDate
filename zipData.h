#include <stdio.h>
// declares functions to be used in zipData.c
void find_postal(char file[], char filter[], FILE *out);
void find_county(char file[], char filter[], FILE *out);
void find_place(char file[], char filter[], FILE *out);
void distance(char file[], char post1[], char post2[], FILE *out);

void read_data(FILE *in, char country[], char postal[], char place[],
    char adm1[], char adm2[], char adm3[], char adm4[], char adm5[],
    char adm6[], double *latitude, double *longitude, char accuracy[]);

void print(FILE *out, char country[], char postal[], char place[],
    char adm1[], char adm2[], char adm3[], char adm4[], char adm5[],
    char adm6[], double latitude, double longitude, char accuracy[]);
