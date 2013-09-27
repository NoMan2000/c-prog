Figure 10.17  Sequence of Events for Trace of Call to find_caps 
from printf Statements
Call find_caps with input argument "JoJo" to determine value to print.
         Since 'J' is a capital letter,
         prepare to use sprintf to build a string with 'J'
         and the result of calling find_caps with input argument "oJo".
                 Since 'o' is not a capital letter,
                 call find_caps with input argument "Jo".
                          Since 'J' is a capital letter,
                          prepare to use sprintf to build a string with 'J'
                          and the result of calling find_caps with input argument "o".
                                  Since 'o' is not a capital letter,
                                  call find_caps with input argument "".
                                           Return "" from fifth call.
                                  Return "" from fourth call.
                          Complete execution of sprintf combining 'J' and "".
                          Return "J" from third call.
                 Return "J" from second call.
          Complete execution of sprintf combining 'J' and "J".
          Return "JJ" from original call.
Complete call to printf to print Capital letters in JoJo are JJ.