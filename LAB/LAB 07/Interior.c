#include <stdio.h>

int main() {
    float x, y, h, k, r;
    float distance;

    // Input values
    printf("Enter center of circle (h k): ");
    scanf("%f %f", &h, &k);

    printf("Enter radius of circle: ");
    scanf("%f", &r);

    printf("Enter point (x y): ");
    scanf("%f %f", &x, &y);

    // Distance formula
    distance = (x - h)*(x - h) + (y - k)*(y - k);

    if (distance < r*r)
        printf("The point lies inside the interior of the circle\n");
    else if (distance == r*r)
        printf("The point lies on the circle\n");
    else
        printf("The point lies outside the circle\n");

    return 0;
}
