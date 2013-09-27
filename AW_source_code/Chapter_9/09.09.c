Figure 9.9  Numeric and String Versions of Portions of Selection Sort That Compare and Exchange Elements
Comparison (in function that finds index of smallest remaining element)
Numeric	String	
if (list[i] < list[first])	if (strcmp(list[i], list[first]) < 0)
      first = i;	               first = i;
 
Exchange of elements
temp = list[index_of_min];	strcpy(temp, list[index_of_min]);
list[index_of_min] =	        strcpy(list[index_of_min], list[fill]);
                 list[fill];	strcpy(list[fill], temp);
list[fill] = temp;