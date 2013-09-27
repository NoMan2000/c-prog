/*
 *      scope.c
 *
 *      Program to illustrate the concept of variable scope
 *
 *      by Mark Virtue, 2001.
 */

int     a = 1;

func()
{
    int     b = 2;

    a = b;

    {   /* begin an arbitrary block */
        int     c = 3;

        a = b + c;
    }

    a = b;

    {   /* begin another arbitrary block */
        int     d = 4;

        a = b + d;
    }

    a = b;
}

main()
{
    int     e = 5;

    a = e;

    {   /* begin an arbitrary block */
        int     f = 6;

        a = e + f;

        {   /* begin an arbitrary sub-block */
            int     g = 7;

            a = e + f + g;
        }

        a = e + f;
    }

    a = e;
}

