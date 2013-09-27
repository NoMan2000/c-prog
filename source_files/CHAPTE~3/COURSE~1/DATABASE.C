/*
 *      database.c
 *
 *      Program to maintain a database of CDs for a record store.
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    title[61];
    char    artist[61];
    int     tracks;         /* number of tracks on the CD */
    char    type;           /* used to read in album/single info */
    int     album;          /* boolean - is the CD an ALBUM? */
    float   price;

    printf("Welcome to the CD database.\n\n");

    /*
     *  First, the title
     */
    printf("Please enter the details of the CD...\n");
    printf("Title? ");
    scanf("%[^\n]", title);

    /*
     *  Next, the artist
     */
    printf("Artist? ");
    fflush(stdin);
    scanf("%[^\n]", artist);

    /*
     *  Next, the number of tracks
     */
    printf("Number of tracks? ");
    fflush(stdin);
    scanf("%d", &tracks);

    /*
     *  Next, Album/single
     */
    printf("Album or single (a for album, s for single)? ");
    fflush(stdin);
    scanf("%c", &type);
    album = type == 'a';    /* if they didn't enter 'a' or 's' it assumes 's' */

    /*
     *  Next, the price
     */
    printf("Retail price (e.g. 4.65)? ");
    fflush(stdin);
    scanf("%f", &price);

    /*
     *  Output the CD details
     */
    printf("\nThe CD details you entered are:\n");
    printf("============================\n");
    printf("Title: %s\n", title);
    printf("Artist: %s\n", artist);
    printf("Number of tracks: %d\n", tracks);
    if (album)
        printf("Album\n");
    else
        printf("Single\n");
    printf("Price: %.2f\n", price);
    printf("============================\n");

    /*
     *  A user-friendly exit of the program
     */
    printf("\nPress ENTER to exit the program: ");
    fflush(stdin);
    getchar();
}

