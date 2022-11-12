#include <stdio.h>

#include "langton.h"
#include "visualiser.h"

int main(int argc, char *argv[])
{
    // Create Ant & Start Visualisation
    struct ant a;
    start_visualisation(&a);

    // Visualisation Loop
    while(not_quit())
        visualise_and_advance(&a);

    // End Visualisation
    end_visualisation();
}
