/*
 *      database.h
 *
 *      General header file for the database project
 *
 *      by Mark Virtue, 2001.
 */
#define NO_CDS      100

#define TITLE_SIZE  60
#define ARTIST_SIZE 60

/*
 *  prototypes for all functions
 */
int trim_newline(char string[]);
int enter(char prompt[]);
int yesno(char prompt[]);    /* prompt should NOT include a question mark */
int read_int(char prompt[]);
float read_float(char prompt[]);
int read_string(char prompt[], char answer[], int MAX);
int output(char title[], char artist[], int tracks, int album, float price);

