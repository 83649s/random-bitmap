#include <stdio.h>
#include <stdlib.h>

#define COLORWIDTH 255 

int* getResolution(void);

int main(void) {
    int *screenResolution = getResolution();
    int width = screenResolution[0];
    int height = screenResolution[1];
    int color = screenResolution[2];


    FILE *output = fopen("./output.pgm", "wb");

    char *magicNumber = malloc(sizeof(char) * 2);
    if (color == 1) {
        magicNumber = "P3";
    }
    else {
        magicNumber = "P2";
    }

    fprintf(output, "%s\n", magicNumber);

    char *heightWidthIndicator = malloc(sizeof(char) * 100);
    sprintf(heightWidthIndicator, "%i %i", width, height);

    fprintf(output, "%s\n", heightWidthIndicator);

    fprintf(output, "%i\n", COLORWIDTH);

    if (color == 1) {
        height *= 3;
    } 
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fprintf(output, "%i", rand() % COLORWIDTH);
            if (j != width - 1) {
                fprintf(output, "%c", ' ');
            }
        }
        fprintf(output, "\n");
    }
    free(magicNumber);
    free(heightWidthIndicator);
    
    fclose(output);
    return 0;
}


int* getResolution(void) {
    int vertical, horizontal;
    char color[2];
    int* resolution = malloc(sizeof(int) * 3);
    printf("Horizontal resolution: ");
    scanf("%i", &horizontal);

    printf("Vertical resolution: ");
    scanf("%i", &vertical);

    printf("Color y/n: ");
    scanf("%s", color);

    resolution[0] = horizontal;
    resolution[1] = vertical;

    if (color[0] == 'y' || color[0] == 'Y') {
        resolution[2] = 1;
    }
    else {
        resolution[2] = 0;
    }

    return resolution;
}
