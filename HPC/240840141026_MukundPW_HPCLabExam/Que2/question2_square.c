#include <stdio.h>

int main() {
    //FILE *fp = fopen("job_a_output.txt", "w");
    //if (fp == NULL) {
      //  perror("Error opening file");
       // return 1;
    //}

    fprintf("Squares of numbers from 1 to 10:\n");
    for (int i = 1; i <= 10; i++) {
        fprintf("%d^2 = %d\n", i, i * i);
    }

    //fclose(fp);
    return 0;
}

