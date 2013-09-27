Figure 4.5  if Statement to Order x and y
if (x > y) {                     /* Switch x and y */
      temp = x;                  /* Store old x in temp */
      x = y;                     /* Store old y in x */
      y = temp;                  /* Store old x in y */
}