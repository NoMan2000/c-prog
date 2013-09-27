
Figure 9.10  Sentinel-Controlled Loop for String Input
printf("Enter list of words on as many lines as you like.\n");
printf("Separate words by at least one blank.\n");
printf("When done, enter %s to quit.\n", SENT);

for  (scanf("%s", word);
      strcmp(word, SENT) != 0;
      scanf("%s", word)) {
    /* process word */
    . . .
}
