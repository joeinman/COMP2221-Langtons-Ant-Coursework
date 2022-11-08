#include "langton.h"
#include "visualiser.h"

int main()
{
    // Create Ant & Start Visualisation
    struct ant* a;
    start_visualisation(a);

    while(not_quit())
        visualise_and_advance(a);

    end_visualisation();
}
