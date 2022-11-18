#include <stdio.h>

#include "langton.h"
#include "visualiser.h"

int main(int argc, char *argv[]) {
    struct rule rules;

    // Check Command Line Input
    if (argc == 1) {
        rules.rules = "LR";
    } else if (argc == 2) {
        rules.rules = argv[1];
    } else {
        printf("Too Many Arguments Supplied.\n");
        return 0;
    }

    // Create Ant & Start Visualisation
    struct ant a;
    start_visualisation(&a);

    // Visualisation Loop
    while (not_quit())
        visualise_and_advance(&a, &rules);

    // End Visualisation
    end_visualisation();
    return 0;
}
