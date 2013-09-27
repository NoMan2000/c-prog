Figure 13.14  Macro Expansion of Second Macro Call of Program in Fig. 13.13
LABEL_PRINT_INT("tiger", t + 2)

LABEL_PRINT_INT(label, num)
 
      parameter matching     
 
                                          "tiger"  t + 2

                  printf("%s = %d", (label), (num))
 
                         parameter replacement in body     
 
                                      printf("%s = %d", ("tiger"), (t + 2))
 
                                                       result of macro expansion