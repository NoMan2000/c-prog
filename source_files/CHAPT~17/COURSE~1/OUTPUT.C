/*
 *      output.c
 *
 *      Data printing functions for the CD database project
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include "database.h"

/*
 *  print_cd()
 *
 *  Display (using printf) the details of one CD
 */
void print_cd(cd_t *cd)
{
    puts("========================");
    printf("Title: %s\n", cd->title);
#ifndef NOARTIST
	printf("Artist: %s\n", cd->artist);
#endif
	printf("Number of tracks: %d\n", cd->tracks);
	puts(is_on(cd->flags, CD_ALBUM) ? "Album" : "Single");
	puts(is_on(cd->flags, CD_COMEDY) ? "Comedy" : "Music");
	printf("Price: %.2f\n", cd->price);
    puts("========================");
}

