Figure 5.2  Program Fragment with a Loop

count_emp = 0;   /* no employees processed yet	*/
while (count_emp < 7) {   /* test value of count_emp	*/
    printf("Hours> ");
    scanf("%d", &hours);
    printf("Rate> ");
    scanf("%lf", &rate);
    pay = hours * rate;
    printf("Pay is $%6.2f\n", pay);
    count_emp = count_emp + 1; /* increment count_emp	*/
}
printf("\nAll employees processed\n");