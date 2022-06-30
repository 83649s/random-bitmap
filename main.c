#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 100
#define WIDTH 100

int main(void) {
    FILE *output = fopen("./output.pbm", "wb");
    char *magicNumber = "P1";
    fprintf(output, "%s\n", magicNumber);
    
    char *heightWidthIndicator = malloc(sizeof(char) * 100);
    sprintf(heightWidthIndicator, "%i %i", HEIGHT, WIDTH);

    fprintf(output, "%s\n", heightWidthIndicator);
    for (int j = 0; j < HEIGHT; ++j) {
        char* row = malloc((sizeof(char) * WIDTH)); 
        for (int i = 0; i < WIDTH; ++i) {
            // Ascii = +48 for integers 
            row[i] = (char) (rand() % 2) + 48;
        }

        fprintf(output, "%s", row);
        free(row);
        fprintf(output, "\n");
    }
    fclose(output);
    return 0;
}