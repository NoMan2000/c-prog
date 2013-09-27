Figure 8.19  Function to Check Whether Tic-tac-toe Board is Filled
/*   Checks whether a tic-tac-toe board is completely filled.  */
int
filled(char ttt_brd[3][3])  /*  input - tic-tac-toe board 	*/
{
      int r, c,  /* row and column subscripts   */
	  ans;   /* whether or not board filled */

      /*  Assumes board is filled until blank is found	*/
      ans = 1;

      /*  Resets ans to zero if a blank is found 	*/
      for  (r = 0;  r < 3;  ++r)
	  for  (c = 0;  c < 3;  ++c)
	      if (ttt_brd[r][c] == ' ')
		    ans = 0;

      return (ans);
}
