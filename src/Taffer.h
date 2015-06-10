#ifndef TAFFER_H_INCLUDED
#define TAFFER_H_INCLUDED
#define MAX_MAP_X 100
#define MAX_MAP_Y 100
#define MAX_NODES_TO_DISP 20

#endif // TAFFER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <time.h>


//Main menu functions
void TaffShowMainMenu();
void TaffMenuMain();
void TaffMenuSettings();
void TaffMenuEditor( void );

//MapFunctions
int TaffMapInit();
void TaffEdInit ( void );
void TaffSetMapNode( char value, int x, int y );
void TaffClearMapNode( int x, int y );
void TaffRenderMap();

//Control functions
void TaffGetUserControl();
void TaffCheckBorders();
bool TaffIsNodeAvailable();

