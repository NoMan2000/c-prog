/*
 *      database.h
 *
 *      General header file for the database project
 *
 *      by Mark Virtue, 2001.
 */
struct cd_type
{
    char    *title;
#ifndef NOARTIST
    char    *artist;
#endif
    int     tracks;      /* number of tracks on the CD */
    int     album;       /* boolean - is the CD an ALBUM? */
    float   price;
};

typedef struct cd_type   cd_t;

/*
 *  prototypes for all functions
 */
int trim_newline(char string[]);
int enter(char prompt[]);
int yesno(char prompt[]);    /* prompt should NOT include a question mark */
int read_int(char prompt[]);
float read_float(char prompt[]);
int read_string(char prompt[], char answer[], int MAX);
char *read_dyn_string(char prompt[]);
int read_cd(cd_t *cd);
int print_cd(cd_t *cd);

