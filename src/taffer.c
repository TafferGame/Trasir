#include "Taffer.h"
#include "TaffEngine.h"

int main()
{
    TaffShowMainMenu();

    while(1)
    {
        TaffRenderMap();
        TaffGetUserControl();
    }

}
