#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zipData.h"
/**
 * “As a Hokie, I will conduct myself with honor and integrity at all times. I will not lie, cheat, or steal, nor will I accept the actions of those who do.”
 * */

/*
the moain method of the program
*/
int main(int argc, char *argv[])
{
    //displays message if not ran with enough inputs
    if ( argc != 3 )
	{
		fprintf(stderr, "Usage: vectors <input-file> <output-file>\n");
		exit(1);
	}

    FILE* in;
	in = fopen(argv[1], "r");//makes the input file
	FILE* out;
	out = fopen(argv[2], "w");// makes the output file

    char command[20];
    char command2[20];
    char command3[20];
    char current[10];


    fscanf(in, "%s ", command);// scanes the first word on the first line
    
    while (!feof(in))// loops until end of file
    {
        if (strcmp(command, "filename") == 0)// determines if command is set as filename
        {
            fscanf(in, "%s\n", current);// scans the filename
            fprintf(out, "filename %s\n", current);// prints "filename" and the name of it

        }
        else if (strcmp(command, "postal") == 0)// determines if command is set as postal
        {
            fscanf(in, "%s", command2);// scans the postal
            fprintf(out, "postal %s\n", command2);// prints "postal" and the name of it
            find_postal(current, command2, out);// calls appropriate method


        }
        else if (strcmp( command, "county") == 0)// determines if command is set as county
        {
            fscanf(in, "%[^\n]", command2);// scans the county
            fprintf(out, "county %s\n", command2);// prints "county" and the name of it
            find_county(current, command2, out);// calls appropriate method


        }
        else if (strcmp( command, "place") == 0)// determines if command is set as place
        {
            fscanf(in, "%[^\n]", command2);// scans the place
            fprintf(out, "place %s\n", command2);// prints "place" and the name of it
            find_place(current, command2, out);// calls appropriate method


        }
        else if (strcmp( command, "distance") == 0)// determines if command is set as distance
        {
            fscanf(in, "%s", command2);// scans the first postal
            fgetc(in);
            fscanf(in, "%s", command3);// scans the second postal
            fprintf(out, "distance %s %s\n", command2, command3);// prints "distance" and the name of them
            distance(current, command2, command3, out);// calls appropriate method


        }
        fscanf(in, "%s ", command);// sets command as the first word of the next line
    }
      

   

    fclose(in);
    
    return 0;
}
