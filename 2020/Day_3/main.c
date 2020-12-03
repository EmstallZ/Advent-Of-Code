#include <stdio.h>
#include <string.h>

#define LENGTH (323)

int main(void) {
    FILE *fp = fopen("input", "r");
    if (!fp)
        printf("something went wrong\n");
    else {
        char inputArray[LENGTH][128];
        int pattern[5][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
        int position = 0;
        int buffer = 0;
        int result1 = 0;
        unsigned long long result2 = 1;

        for (int i = 0; i < LENGTH; i++) {
            fscanf(fp, "%s\n", inputArray[i]);
        }

        // part 1
        for (int i = 0; i < LENGTH; i++) {
            if (position >= strlen(inputArray[i])) {
                position -= strlen(inputArray[i]);
            }

            if (inputArray[i][position] == '#') {
                result1++;
            }
            position += 3;
        }

        // part 2
        for (int k = 0; k < 5; k++) {
            position = 0;
            for (int i = 0; i < LENGTH; i += pattern[k][1]) {
                if (position >= strlen(inputArray[i])) {
                    position -= strlen(inputArray[i]);
                }

                if (inputArray[i][position] == '#') {
                    buffer++;
                }
                position += pattern[k][0];
            }
            result2 *= buffer;
            buffer = 0;
        }

        printf("Part 1: %d\n", result1);
        printf("Part 2: %llu\n", result2);

        fclose(fp);
    }
}