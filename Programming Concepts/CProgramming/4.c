#include <stdio.h>

    int main(){
    float temp, fahrenheit;

    printf("Enter the temperature in Celsius: ");
    scanf("%f" , &temp);

    fahrenheit = (temp * 9/5) + 32;

    printf("The temperature in Fahrenheit is: %.2f \n", fahrenheit);



}