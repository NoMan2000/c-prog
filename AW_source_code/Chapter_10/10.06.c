Figure 10.6  Function reverse_input_words
/*
 *  Take n words as input and print them in reverse order on separate lines.
 *  Pre: n > 0
 */
void
reverse_input_words(int n)
{
      char word[WORDSIZ];  /*  local variable for storing one word	*/

      if (n <= 1) {   /* simple case: just one word to get and print	*/

            scanf("%s", word);
            printf("%s\n", word);

      } else {  /* get this word; get and print the rest of the words in
                   reverse order; then print this word 	*/

            scanf("%s", word);
            reverse_input_words(n - 1);
            printf("%s\n", word);
      }
}