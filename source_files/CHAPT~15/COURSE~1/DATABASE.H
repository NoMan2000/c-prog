/*
 *      database.h
 *
 *      General header file for the database project
 *
 *      by Mark Virtue, 2001.
 */
#define TITLE_SIZE  60
#define ARTIST_SIZE 60

struct cd_type
{
    char    title[TITLE_SIZE+1];
#ifndef NOARTIST
    char    artist[ARTIST_SIZE+1];
#endif
    int     tracks;      /* number of tracks on the CD */
    int     album;       /* boolean - is the CD an ALBUM? */
    float   price;
};

typedef struct cd_type   cd_t;

/*
 *  prototypes for all public functions
 */
void  trim_newline(char string[]);
cd_t *increase_array(cd_t *oldarr, int oldcount, int increase);
void  enter(char prompt[]);
int   yesno(char prompt[]);    /* prompt should NOT include a question mark */
int   read_int(char prompt[]);
float read_float(char prompt[]);
void  read_string(char prompt[], char answer[], int MAX);
char *read_dyn_string(char prompt[]);
void  read_cd(cd_t *cd);
void  print_cd(cd_t *cd);
int   file_exists(char *fname);
int   save_file(char *fname, cd_t *cds, int count, int append);
cd_t *open_file(char *fname, int *num);

