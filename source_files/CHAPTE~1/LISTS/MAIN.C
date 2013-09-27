/*
 *      main.c
 *
 *      The menu functionality for the CD database
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

#define FNAME_SIZE      200         /* max size of a filename */

static glist_t *cds;   /* each implicitly initialised to NULL (0) */
static int     changes;     /* boolean - have changes been made? */
static char    fname[FNAME_SIZE];  /* current filename */

/*
 *  reset_everything()
 *
 *  Perform any necessary "free"ing and reset all the globals
 *  back to a proper starting point
 */
static void reset_everything()
{
    /*
     *  Only free the CDs if there is something to free
     */
    if (cds != NULL)
    {
        list_destroy(cds);
        cds = NULL;
    }

    changes = 0;
    fname[0] = '\0';    /* clear the current filename */
}

/*
 *  are_you_sure()
 *
 *  If changes have been made, ask the user if they want to discard them
 *  returns 1 if it is okay to proceed, or 0 otherwise
 */
static int are_you_sure()
{
    if (!changes)
        return 1;
    return yesno("Are you sure you want to discard all records");
}

/*
 *  compare_func()
 *
 *  Function for use in conjunction with the sort menu option
 *  Compare two CDs based on ARTIST then TITLE and return:
 *      >0 if e1 > e2
 *       0 if e1 = e2
 *      <0 if e1 < e2
 */
int compare_func(void *e1, void *e2, int size)
{
    /*
     *  Create two temp pointers for convenience,
     *  to ensure that the void pointers are interpreted correctly
     */
    cd_t    *cd1 = e1;
    cd_t    *cd2 = e2;
    int     rv;         /* return value */

    /*
     *  First compare the ARTISTs
     */
    rv = strcmp(cd1->artist, cd2->artist);
    if (rv != 0)        /* artists are different */
        return rv;

    /*
     *  If we get to here, artists are the same - compare the TITLEs
     */
    return strcmp(cd1->title, cd2->title);
}

/*
 *  file_new()
 *
 *  Menu option 1
 */
static void file_new()
{
    if (are_you_sure())
        reset_everything();
}

/*
 *  general_open()
 *
 *  perform all the kinds of opens we do (from the menu, from the command-line)
 */
static void general_open(char *new_fname)
{
    glist_t  *new_cds;       /* temp list */

    /*
     *  initialise the new list
     */
    new_cds = list_create(LIST_FLAG_COPY|LIST_FLAG_SORT, compare_func);
    if (new_cds == NULL)
    {
        fprintf(stderr, "Out of memory - quitting\n");
        exit(1);
    }

    /*
     *  read any records from the file into a temp list
     */
    if (open_file(new_cds, new_fname) == -1)
    {
        perror("Could not read from the file");
        return;
    }

    /*
     *  the temp list is now to become the real list
     *  update the globals accordingly
     */
    reset_everything();     /* frees the existing list (if there is one) */
    cds = new_cds;          /* just point to the new list */
    strcpy(fname, new_fname);

    printf("Successfully read file - %d new records\n", list_count(cds));
}

/*
 *  file_open()
 *
 *  Menu option 2
 */
static void file_open()
{
    char    new_fname[FNAME_SIZE];

    if (!are_you_sure())
        return;

    read_string("Please enter the name of the file to open: ",
                                 new_fname, sizeof new_fname);

    general_open(new_fname);
}

/*
 *  general_save()
 *
 *  perform all the kinds of saves we do (regular save, save as, append)
 *  "save_as" and "append" are booleans, and mutually exclusive
 */
static void general_save(int append, int save_as)
{
    char    new_fname[FNAME_SIZE];  /* the filename we'll use */

    /*
     *  If they are appending or doing a "Save as",
     *  then prompt for a filename
     */
    if (append || save_as)
        read_string("Please enter the name of the file: ",
                                         new_fname, sizeof new_fname);
    else
        strcpy(new_fname, fname);       /* use the existing file */

    /*
     *  If: we're doing a "Save as", and the file exists,
     *  and the user does NOT wish to overwrite the file, then do nothing
     */
    if (
        save_as
        &&
        file_exists(new_fname)
        &&
        !yesno("The file exists.  Are you sure you want to overwrite it")
       )
        return;

    /*
     *  attempt to save the list
     */
    if (save_file(new_fname, cds, append) == -1)
    {
        perror("Could not save the list");
        return;
    }

    /*
     *  Success!
     */
    printf("List saved successfully - %d records\n", list_count(cds));
    changes = 0;            /* changes have been saved */

    /*
     *  If they were doing a "Save as",
     *  then use the new filename as the current filename
     */
    if (save_as)
        strcpy(fname, new_fname);
}

/*
 *  file_save()
 *
 *  Menu option 3
 */
static void file_save()
{
    /*
     *  if the current filename is empty, we are really doing a "Save as"
     */
    general_save(0, strlen(fname) == 0);
}

/*
 *  file_save_as()
 *
 *  Menu option 4
 */
static void file_save_as()
{
    general_save(0, 1);
}

/*
 *  file_append()
 *
 *  Menu option 5
 */
static void file_append()
{
    general_save(1, 0);
}

/*
 *  edit_add()
 *
 *  Menu option 6 - add a new record to the system
 */
static void edit_add()
{
    cd_t    cd;

    /*
     *  Read in the next CD
     */
    printf("\nPlease enter the details of CD %d...\n\n", list_count(cds)+1);
    read_cd(&cd);
    list_add(cds, &cd, sizeof cd);
    changes = 1;            /* clearly a change has been made */
}

/*
 *  do_print_one()
 *
 *  Function used in conjuction with list library to print one CD
 */
static int do_print_one(void *data)
{
    cd_t    *cd = data;
    int     index = list_curr_index(cds);

    printf("\nThe details of CD %d are:\n", index+1);
    print_cd(cd);

    if (index < list_count(cds) - 1)    /* only do this if there are more CDs to see */
        enter("\nPress ENTER to see the next set of details: ");
    return GLIST_OK;
}

/*
 *  view_display_one()
 *
 *  Menu option 7 - view one record
 */
static void view_display_one()
{
    int     number;
    cd_t    *cd;

    if (list_count(cds) == 0)
    {
        puts("There are no CDs in the system");
        return;
    }

    /*
     *  ask for the CD number until a valid one is supplied
     */
    for (;;)
    {
        number = read_int("Please enter the number of the CD that you wish to see: ");
        if (number >= 1 && number <= list_count(cds))
            break;
        printf("Invalid number.  There are %d CDs in the system\n", list_count(cds));
    }

    cd = list_index_get(cds, number-1);
    printf("\nThe details of CD %d are:\n", number);
    print_cd(cd);
}

/*
 *  view_display_all()
 *
 *  Menu option 8 - show all records
 */
static void view_display_all()
{
    if (list_count(cds) == 0)
        puts("There are no CDs in the system");
    else
        list_do(cds, do_print_one);
}

/*
 *  quit()
 *
 *  Menu option 10
 */
static void quit()
{
    if (are_you_sure())
        exit(0);            /* note: some "atexit" processing will occur */
}

/*
 *  Structure (and array) to hold the name and function pointer of
 *  the menu options
 */
static struct
{
    char *string;
    void (*func)(void);
}
    menu_opts[] =
{
    {"File: Create a new list",             file_new},
    {"      Open an existing list",         file_open},
    {"      Save the list",                 file_save},
    {"      Save the list with a new name", file_save_as},
    {"      Append list to another file",   file_append},
    {"Edit: Create a new record",           edit_add},
    {"View: Display a specific record",     view_display_one},
    {"      Display all records",           view_display_all},
    {"Exit",                                quit}
};

/*
 *  display_menu()
 *
 *  Display the full menu screen ONCE, then prompt for a choice and call
 *  the appropriate function
 */
static void display_menu()
{
    int     choice;
    int     i;

    /*
     *  display the filename and record count
     */
    printf("\nThere are currently %d records in the system.\n", list_count(cds));
    if (strlen(fname) == 0)
        puts("No current filename\n");
    else
        printf("Current filename: %s\n\n", fname);

    /*
     *  display the menu
     */
    puts("Please choose an option:");
    for (i = 0; i < Nelts(menu_opts); i++)
        printf("%2d.  %s\n", i+1, menu_opts[i].string);

    /*
     *  loop until they enter a valid choice
     */
    for (;;)
    {
        choice = read_int("Please enter your choice: ");
        if (choice > 0 && choice <= Nelts(menu_opts))
            break;
        puts("Invalid Selection");
    }

    /*
     *  call the function (via the function pointer
     */
    menu_opts[choice-1].func();
    enter("\nPress ENTER to continue: ");
}

/*
 *  goodbye()
 *
 *  Exit the program gracefully (used with atexit())
 */
static void goodbye()
{
    reset_everything();     /* not strictly necessary, but good practice */
    enter("\nPress ENTER to exit the program: ");
}

main(int argc, char *argv[])
{
    atexit(goodbye);        /* ensure we say goodbye nicely */

    /*
     *  initialise the list
     */
    cds = list_create(LIST_FLAG_COPY|LIST_FLAG_SORT, compare_func);
    if (cds == NULL)
    {
        fprintf(stderr, "Out of memory - quitting\n");
        exit(1);
    }

    /*
     *  If there are command-line arguments, interpret the first one
     *  as a filename to read CDs from
     */
    if (argc > 1)
        general_open(argv[1]);

    puts("Welcome to the CD database.");

    /*
     *  just keep displaying the menu - the QUIT option will break the loop
     */
    for (;;)
        display_menu();
}

