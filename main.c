#include <stdio.h>

#include "langton.h"
#include "visualiser.h"

int main(int argc, char *argv[]) {
    struct rule rules;

    // Check Command Line Input
    if (argc == 1) {
        rules.rules = "LR"; // Default Rule Set
    } else if (argc == 2) {
        rules.rules = argv[1];
    } else {
        printf("Usage: ./ant [RULES] (Default Rule Set Is 'LR'\n");
        return 0;
    }

    // Create Ant & Start Visualisation
    struct ant a;
    start_visualisation(&a);

    // Visualisation Loop
    while (not_quit())
        visualise_and_advance_general(&a, &rules);

    // End Visualisation
    end_visualisation();
    return 0;
}
