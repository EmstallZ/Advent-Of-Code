#include <stdio.h>

int main(void) {
    FILE *fp = fopen("input", "r");
    if (!fp)
        printf("something went wrong\n");
    else {
        int inputArray[200];
        int arrLen = (sizeof(inputArray) / sizeof(int));

        for (int i = 0; i < arrLen; i++) {
            fscanf(fp, "%d\n", &inputArray[i]);
        }

        for (int i = 0; i < arrLen; i++) {
            for (int j = i + 1; j < arrLen; j++) {
                if ((inputArray[i] + inputArray[j]) == 2020) {
                    printf("Part 1: %d + %d = %d\n", inputArray[i],
                           inputArray[j], (inputArray[i] * inputArray[j]));
                }
                for (int k = j + 1; k < arrLen; k++) {
                    if ((inputArray[i] + inputArray[j] + inputArray[k]) ==
                        2020) {
                        printf("Part 2: %d + %d + %d = %d\n", inputArray[i],
                               inputArray[j], inputArray[k],
                               (inputArray[i] * inputArray[j] * inputArray[k]));
                    }
                }
            }
        }

        fclose(fp);
    }
}