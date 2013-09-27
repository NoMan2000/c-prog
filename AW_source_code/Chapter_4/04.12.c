Figure 4.12  Example of a switch Statement with Type char Case Labels
switch (class) {
case 'B':
case 'b':
        printf("Battleship\n");
        break;

case 'C':
case 'c':
        printf("Cruiser\n");
        break;

case 'D':
case 'd':
        printf("Destroyer\n");
        break;

case 'F':
case 'f':
        printf("Frigate\n");
        break;

default:
       printf("Unknown ship class %c\n", class);
}
