#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv) {

    FILE *filePointer;
    int word_count = 0;
    int word_started = 0;
    char characters_read;

    filePointer = fopen(argv[1], "r");

    if (filePointer) {
        while ((characters_read = getc(filePointer)) != EOF) {
            if (isspace(characters_read)) {
                if (word_started) {
                    word_count++;
                }
                word_started = 0;
            }
            else {
                word_started = 1;
            }
        }
    }
    else {
        printf("Can't open the file.\n");
        return 0;
    }

    printf("There are %d word(s).\n", word_count);

    return 0;
}
