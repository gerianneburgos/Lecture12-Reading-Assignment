#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    // array of planet names (stores "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto" as elements in the array planet)
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    int i, j;

    // iterates over command-line arguments (excluding the program name)
    for (i = 1; i < argc; i++)
    {
        // iterates and increments over the planets array until j is less that NUM_PLANETS
        for (j = 0; j < NUM_PLANETS; j++) 
        {
            // compares the current command-line argument with each planet name
            if (strcmp(argv[i], planets[j]) == 0)
            {
                // when it finds that the names match, it prints the planet name and its position in the array (+1)
                printf("%s is planet %d\n", argv[i], j + 1);

                // exits the inner loop since the planet is found
                break;
            }
        }

        // otherwise, the inner loop completes without finding a match (j == NUM_PLANETS),
        // prints that the argument is not a planet
        if (j == NUM_PLANETS)
        {
            printf("%s is not a planet\n", argv[i]);
        }
    }

    return 0;
}
