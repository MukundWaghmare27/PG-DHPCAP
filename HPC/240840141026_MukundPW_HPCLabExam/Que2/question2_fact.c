#include <stdio.h>

int main() {
    int n = 5; // Number to calculate factorial
    long long factorial = 1;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    //FILE *fp = fopen("job_b_output.txt", "w");
    //if (fp == NULL) {
     //   perror("Error opening file");
     //   return 1;
    //}

    //fprintf(fp, "Factorial of %d is: %lld\n", n, factorial);
    //fclose(fp);

    return 0;
}
