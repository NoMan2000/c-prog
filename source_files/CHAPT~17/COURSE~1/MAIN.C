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
#define MAX_CDS         100         /* how many CDs we can store */

static cd_t    *cds[MAX_CDS];   /* each implicitly initialised to NULL (0) */
static int     count;       /* how many CDs are in "cds" array */
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
    int     i;

    /*
     *  Only free the CDs if there is something to free
     */
    for (i = 0; i < count; i++)
        free(cds[i]);

    count = 0;
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
    cd_t    *new_cds[MAX_CDS];       /* temp array */
    int     new_count;

    /*
     *  read any records from the file into a temp array
     *  Note that we don't pass &new_cds, because the address of an array
     *  is simply the array itself
     */
    if (open_file(new_cds, new_fname, &new_count) == -1)
    {
        perror("Could not read from the file");
        return;
    }

    /*
     *  the temp array is now to become the real array
     *  update the globals accordingly
     */
    reset_everything();     /* frees the existing list (if there is one) */
    count = new_count;
    memcpy(cds, new_cds, count * sizeof *cds);   /* this copies ONLY THE POINTERS */
    strcpy(fname, new_fname);

    printf("Successfully read file - %d new records\n", count);
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
    if (save_file(new_fname, cds, count, append) == -1)
    {
        perror("Could not save the list");
        return;
    }

    /*
     *  Success!
     */
    printf("List saved successfully - %d records\n", count);
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
    printf("\nPlease enter the details of CD %d...\n\n", count+1);
    read_cd(&cd);

    /*
     *  increase the size of the CD array by 1
     */
    cds[count] = allocate_one_cd();
    *(cds[count]) = cd;        /* structure copy */
    count++;                         

    changes = 1;            /* clearly a change has been made */
}

/*
 *  view_display_one()
 *
 *  Menu option 7 - view one record
 */
static void view_display_one()
{
    int     number;

    if (count == 0)
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
        if (number >= 1 && number <= count)
            break;
        printf("Invalid number.  There are %d CDs in the system\n", count);
    }

    printf("\nThe details of CD %d are:\n", number);
    print_cd(cds[number-1]);
}

/*
 *  view_display_all()
 *
 *  Menu option 8 - show all records
 */
static void view_display_all()
{
    int     i;

    if (count == 0)
    {
        puts("There are no CDs in the system");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nThe details of CD %d are:\n", i+1);
        print_cd(cds[i]);

        if (i < count - 1)    /* only do this if there are more CDs to see */
            enter("\nPress ENTER to see the next set of details: ");
	}
}

/*
 *  quit()
 *
 *  Menu option 9
 */
static void quit()
{
    if (are_you_sure())
        exit(0);            /* note: some "atexit" processing will occur */
}

/*
 *  display_menu()
 *
 *  Display the full menu screen ONCE, then prompt for a choice and call
 *  the appropriate function
 */
static void display_menu()
{
    int     choice;

    /*
     *  display the filename and record count
     */
    printf("\nThere are currently %d records in the system.\n", count);
    if (strlen(fname) == 0)
        puts("No current filename\n");
    else
        printf("Current filename: %s\n\n", fname);

    /*
     *  display the menu
     */
    puts("Please choose an option:");
    puts("1.  File: Create a new list");
    puts("2.        Open an existing list");
    puts("3.        Save the list");
    puts("4.        Save the list with a new name");
    puts("5.        Append list to another file");
    puts("6.  Edit: Create a new record");
    puts("7.  View: Display a specific record");
    puts("8.        Display all records");
    puts("9.  Exit");

    choice = read_int("Please enter your choice? ");

    /*
     *  loop until they enter a valid choice
     */
    for (;;)
    {
        switch (choice)
        {
        case 1:
            file_new();
            break;
        case 2:
            file_open();
            break;
        case 3:
            file_save();
            break;
        case 4:
            file_save_as();
            break;
        case 5:
            file_append();
            break;
        case 6:
            edit_add();
            break;
        case 7:
            view_display_one();
            break;
        case 8:
            view_display_all();
            break;
        case 9:
            quit();
            break;
        default:
            choice = read_int("Invalid Selection - Please try again: ");
            continue;
        }

        /*
         *  after each menu option we show the following before we
         *  display the menu again
         */
        enter("\nPress ENTER to continue: ");
        break;
    }
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

