#include <stdio.h>

int main() {
    float a, b, c;
    float volume;
    float pi = 3.14159;

    // Taking input
    printf("Enter the value of a: ");
    scanf("%f", &a);

    printf("Enter the value of b: ");
    scanf("%f", &b);

    printf("Enter the value of c: ");
    scanf("%f", &c);

    // Calculating volume
    volume = (4.0 / 3.0) * pi * a * b * c;

    // Displaying result
    printf("Volume of the Ellipsoid = %.2f\n", volume);

    return 0;
}
