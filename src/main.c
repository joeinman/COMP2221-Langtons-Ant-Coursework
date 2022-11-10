#include "langton.h"
#include "visualiser.h"

int main()
{
    // Create Ant & Start Visualisation
    struct ant a;
    start_visualisation(&a);

    // Visualisation Loop
    while(not_quit())
    {
        visualise_and_advance(&a);
    }

    // End Visualisation
    end_visualisation();
}
