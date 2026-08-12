#include<stdio.h>
#include<math.h>

int main()
{
    while (1) {
    printf("\n\nSelect the shape to calculate metrics:\n");
    printf("\n1. Cube\n");
    printf("2. Cuboid\n");
    printf("3. Sphere\n");
    printf("4. Cylinder\n");
    printf("5. Cone\n");
    printf("6. Exit \n\n");

    int choice;
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            float side;
            printf("\nEnter the side length of the cube: ");
            scanf("%f", &side);
            printf("Surface Area of Cube: %.2f\n", 6 * side * side);
            printf("Volume of Cube: %.2f\n", side * side * side);
            break;
        }
        case 2: {
            float length, width, height;
            printf("\nEnter the length, width, and height of the cuboid: ");
            scanf("%f %f %f", &length, &width, &height);
            printf("Surface Area of Cuboid: %.2f\n", 2 * (length * width + width * height + height * length));
            printf("Volume of Cuboid: %.2f\n", length * width * height);
            break;
        }
        case 3: {
            float radius;
            printf("\nEnter the radius of the sphere: ");
            scanf("%f", &radius);
            printf("Surface Area of Sphere: %.2f\n", 4 * M_PI * radius * radius);
            printf("Volume of Sphere: %.2f\n", (4.0/3.0) * M_PI * radius * radius * radius);
            break;
        }
        case 4: {
            float radius, height;
            printf("\nEnter the radius and height of the cylinder: ");
            scanf("%f %f", &radius, &height);
            printf("Surface Area of Cylinder: %.2f\n", 2 * M_PI * radius * (radius + height));
            printf("Volume of Cylinder: %.2f\n", M_PI * radius * radius * height);
            break;
        }
        case 5: {
            float radius, height;
            printf("\nEnter the radius and height of the cone: ");
            scanf("%f %f", &radius, &height);
            printf("Surface Area of Cone: %.2f\n", M_PI * radius * (radius + sqrt(height * height + radius * radius)));
            printf("Volume of Cone: %.2f\n", (1.0/3.0) * M_PI * radius * radius * height);
            break;
        }
        case 6:
            printf("\nExiting the program.\n");
            break;
        default:
            printf("\nInvalid choice.\n");
    }
}
    return 0;
}