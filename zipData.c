#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zipData.h"
#include <math.h>
// sets the size of the varables 
#define COUNTRY 3
#define POSTAL 21
#define PLACE 181
#define ADMIN1 101
#define ADMIN2 21
#define ADMIN3 101
#define ADMIN4 21
#define ADMIN5 101
#define ADMIN6 21
#define ACCU 2


/*
recieves three parameters: the name of the country file, the filter word, and the output file.
this function will sort through the given country file and find and print all instances of the filter word in the postal place.
*/
void find_postal(char file[], char filter[], FILE *out)
{
	FILE* in = fopen(file, "r");// sets file in as the correct country file

    char country[COUNTRY];
    char postal[POSTAL];
    char place[PLACE];
    char adm1[ADMIN1];
    char adm2[ADMIN2];
    char adm3[ADMIN3];
    char adm4[ADMIN4];
    char adm5[ADMIN5];
    char adm6[ADMIN6];
    double latitude;
    double longitude;
    char accuracy[ACCU];

    int counter = 0;// keeps track of if the filter word was ever found
    read_data(in, country, postal, place, adm1, adm2, adm3, 
            adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets the variables as the corresponding values in the first line
    while (!feof(in))// loops until end of file
    {
        if (strcmp(postal, filter) == 0)//determines if the filter word was found
            {
                print(out, country, postal, place, adm1, adm2, adm3, 
                    adm4, adm5, adm6, latitude, longitude, accuracy);// prints that line of the file
                
                counter = 1;// so function knows filter word was found
            }
            read_data(in, country, postal, place, adm1, adm2, adm3, 
                adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets variables as the ones on the next line
    }
    if (counter == 0)
    {
        fprintf(out, "Sorry, postal code %s was not found.\n", filter);// if filter was never found prints message
    }
    fclose(in);


    

}

/*
recieves three parameters: the name of the country file, the filter word, and the output file.
this function will sort through the given country file and find and print all instances of the filter word in the county place.
*/
void find_county(char file[], char filter[], FILE *out)
{
    FILE* in;
	in = fopen(file, "r");// sets file in as the correct country file

    char country[COUNTRY];
    char postal[POSTAL];
    char place[PLACE];
    char adm1[ADMIN1];
    char adm2[ADMIN2];
    char adm3[ADMIN3];
    char adm4[ADMIN4];
    char adm5[ADMIN5];
    char adm6[ADMIN6];
    double latitude;
    double longitude;
    char accuracy[ACCU];

    int counter = 0;// keeps track of if the filter word was ever found
    read_data(in, country, postal, place, adm1, adm2, adm3, 
            adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets the variables as the corresponding values in the first line
    while (!feof(in))// loops until end of file
    {
        if (strstr( adm3, filter) != 0)//determines if the filter word was found
            {
                print(out, country, postal, place, adm1, adm2, adm3, 
                    adm4, adm5, adm6, latitude, longitude, accuracy);// prints that line of the file
                counter = 1;// so function knows filter word was found
            }
        read_data(in, country, postal, place, adm1, adm2, adm3, 
            adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets variables as the ones on the next line
    }
    
    if (counter == 0)
    {
        fprintf(out, "Sorry, county %s was not found.\n", filter);// if filter was never found prints message
    }
    fclose(in);

}

/*
recieves three parameters: the name of the country file, the filter word, and the output file.
this function will sort through the given country file and find and print all instances of the filter word in the place place.
*/
void find_place(char file[], char filter[], FILE *out)
{
    FILE* in;
	in = fopen(file, "r");// sets file in as the correct country file

    char country[COUNTRY];
    char postal[POSTAL];
    char place[PLACE];
    char adm1[ADMIN1];
    char adm2[ADMIN2];
    char adm3[ADMIN3];
    char adm4[ADMIN4];
    char adm5[ADMIN5];
    char adm6[ADMIN6];
    double latitude;
    double longitude;
    char accuracy[ACCU];

    int counter = 0;// keeps track of if the filter word was ever found
    read_data(in, country, postal, place, adm1, adm2, adm3, 
        adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets the variables as the corresponding values in the first line
    while (!feof(in))// loops until end of file
    {
        if (strstr( place, filter) != 0)//determines if the filter word was found
            {
                print(out, country, postal, place, adm1, adm2, adm3, 
                    adm4, adm5, adm6, latitude, longitude, accuracy);// prints that line of the file
                counter = 1;// so function knows filter word was found
            }
        read_data(in, country, postal, place, adm1, adm2, adm3, 
            adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets variables as the ones on the next line
    }
    if (counter == 0)
    {
        fprintf(out, "Sorry, place name %s was not found.\n", filter);// if filter was never found prints message
    }
    fclose(in);

}

/*
recieves four parameters: the name of the country file, the first postal code, the second postal code, and the output file.
this function will sort through the given country file and find and print the first instance of both postal codes in the postal place.
calculates the distance between the two postal codes and prints it
*/
void distance(char file[], char post1[], char post2[], FILE *out)
{
    FILE* in;
	in = fopen(file, "r");// makes the country file the in file

    char country[COUNTRY];
    char postal[POSTAL];
    char place[PLACE];
    char adm1[ADMIN1];
    char adm2[ADMIN2];
    char adm3[ADMIN3];
    char adm4[ADMIN4];
    char adm5[ADMIN5];
    char adm6[ADMIN6];
    double latitude;
    double longitude;
    char accuracy[ACCU];

    int counter1 = 0;//tracks in first postal code was found
    int counter2 = 0;// tacks if second postal code was found
    double long1;
    double lat1;
    double long2;
    double lat2;

    read_data(in, country, postal, place, adm1, adm2, adm3, 
        adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets the variables as the corresponding values in the first line
    while (!feof(in))//loops through until end of file
    {
        if (strcmp( postal, post1) == 0 && counter1 == 0)//determines if the filter word was found
            {
                print(out, country, postal, place, adm1, adm2, adm3, 
                    adm4, adm5, adm6, latitude, longitude, accuracy);// prints that line of the file
                lat1 = latitude;// saves the value of the latitude for future use
                long1 = longitude;// saves the value of the latitude for future use
                counter1 = 1;// so function knows filter word was found
            }
        if (strcmp( postal, post2) == 0 && counter2 == 0)//determines if the filter word was found
            {
                print(out, country, postal, place, adm1, adm2, adm3, 
                    adm4, adm5, adm6, latitude, longitude, accuracy);// prints that line of the file
                lat2 = latitude;// saves the value of the latitude for future use
                long2 = longitude;// saves the value of the latitude for future use
                counter2 = 1;// so function knows filter word was found
            }
        read_data(in, country, postal, place, adm1, adm2, adm3, 
            adm4, adm5, adm6, &latitude, &longitude, accuracy);// sets variables as the ones on the next line
    }
    if (counter1 == 0)
    {
        fprintf(out, "Sorry, postal code %s was not found.\n", post1);// prints message if first postal code wasn't found
    }
    if (counter2 == 0)
    {
        fprintf(out, "Sorry, postal code %s was not found.\n", post2);// prints message if second postal code wasn't found
    }
    //haversine formula
    double rad_lat1 = lat1 * M_PI / 180.0;
    double rad_lat2 = lat2 * M_PI / 180.0;
    double rad_long1 = long1 * M_PI / 180.0;
    double rad_long2 = long2 * M_PI / 180.0;

    double lat_diff = (rad_lat2 - rad_lat1);
    double long_diff = (rad_long2 - rad_long1);

    double a = sin(lat_diff / 2) * sin(lat_diff / 2) + cos(rad_lat1)
        * cos(rad_lat2) * sin(long_diff / 2) * sin(long_diff / 2);
    double b = 2 * atan2(sqrt(a), sqrt(1 - a));
    double c = b * 6371.0;
    if ( counter1 != 0 && counter2 != 0)
    {
        fprintf(out, "      Distance: %f km\n", c);
    }
    
}


/*
scans through a line is the given file
*/
void read_data(FILE *in, char country[], char postal[], char place[],
    char adm1[], char adm2[], char adm3[], char adm4[], char adm5[],
    char adm6[], double *latitude, double *longitude, char accuracy[])
{
    //sets the null terminators
    country[0] = '\0';
    postal[0] = '\0';
    place[0] = '\0';
    adm1[0] = '\0';
    adm2[0] = '\0';
    adm3[0] = '\0';
    adm4[0] = '\0';
    adm5[0] = '\0';
    adm6[0] = '\0';
    *latitude = 0;
    *longitude = 0;
    accuracy[0] = '\0';

    //scans through all items in a row
    fscanf(in, "%[^\t]", country);
    fgetc(in);
    fscanf(in, "%[^\t]", postal);
    fgetc(in);
    fscanf(in, "%[^\t]", place);
    fgetc(in);
    fscanf(in, "%[^\t]", adm1);
    fgetc(in);
    fscanf(in, "%[^\t]", adm2);
    fgetc(in);
    fscanf(in, "%[^\t]", adm3);
    fgetc(in);
    fscanf(in, "%[^\t]", adm4);
    fgetc(in);
    fscanf(in, "%[^\t]", adm5);
    fgetc(in);
    fscanf(in, "%[^\t]", adm6);
    fgetc(in);
    fscanf(in, "%lf", latitude);
    fscanf(in, "%lf", longitude);
    fscanf(in, "%[^\n]", accuracy);
    fgetc(in);
}

/*
prints a line in the correct order and with the correct spacing
*/
void print(FILE *out, char country[], char postal[], char place[],
    char adm1[], char adm2[], char adm3[], char adm4[], char adm5[],
    char adm6[], double latitude, double longitude, char accuracy[])
{
    fprintf(out, "\t%s\t", country);
    fprintf(out, "%s\t", postal);
    fprintf(out, "%s\t", place);
    fprintf(out, "%s\t", adm1);
    fprintf(out, "%s\t", adm2);
    fprintf(out, "%s\t", adm3);
    fprintf(out, "%s\t", adm4);
    fprintf(out, "%s\t", adm5);
    fprintf(out, "%s\t", adm6);
    fprintf(out, "%lf\t", latitude);
    fprintf(out, "%lf\t", longitude);
    fprintf(out, "%s\n", accuracy);

}