#include <stdio.h>
#include <string.h>

#define LENGTH (1000)

int main(void) {
    FILE *fp = fopen("input", "r");
    if (!fp)
        printf("something went wrong\n");
    else {
        int min[LENGTH];
        int max[LENGTH];
        char letter[LENGTH];
        char string[LENGTH][256];

        int counterLetter1 = 0;
        int counterValid1 = 0;
        int counterValid2 = 0;
        int num1 = 0;
        int num2 = 0;

        for (int i = 0; i < LENGTH; i++) {
            fscanf(fp, "%d-%d %c: %s\n", &min[i], &max[i], &letter[i],
                   string[i]);
        }

        for (int i = 0; i < LENGTH; i++) {
            for (int j = 0; j < strlen(string[i]); j++) {
                // part 1
                if (string[i][j] == letter[i]) {
                    counterLetter1++;
                }

                // part 2
                if (j == (min[i] - 1) && string[i][j] == letter[i]) {
                    num1 = 1;
                }
                if (j == (max[i] - 1) && string[i][j] == letter[i]) {
                    num2 = 1;
                }
            }

            // part 1
            if (counterLetter1 >= min[i] && counterLetter1 <= max[i]) {
                counterValid1++;
            }

            // part 2
            if (num1 ^ num2) {
                counterValid2++;
            }

            num1 = 0;
            num2 = 0;
            counterLetter1 = 0;
        }

        printf("Part 1: %d\n", counterValid1);
        printf("Part 2: %d\n", counterValid2);

        fclose(fp);
    }
}