#include "Taffer.h"
#include "TaffEngine.h"

const char * option[] = {"1. New Game", "2. Settings", "3. Editor menu", "4. Exit"};
const char* ed_options[] = { "1.Units editor", "2.Map editor" };
const char* lang_settings[] = { "1. English", "2. Settings" };

void TaffShowMainMenu()  {

        system( "cls" );
        for ( int i = 0; i < 4; i++ )
        { printf( "%s\n", option[i] ); }

        TaffMenuMain();

}

void TaffMenuMain()  {

        int menu_control = _getch();

        switch(menu_control) {

        case 49:
            system("cls");

            p_tplayer = malloc( sizeof ( p_tplayer ) );
            p_tAS      = malloc( sizeof( p_tAS ) );
            p_tarmy   = malloc( sizeof( p_tarmy ) );
            //p_root_as = NULL;

            p_tplayer  = TaffPlayerInit( 82, 82, 1, "Serega" );
            p_root_as = TaffASInit( );
            p_tarmy    = TaffArmyInit( 84, 80, p_root_as->u_id, p_root_as );

            int hr = TaffMapInit();
            break;

        case 50:
            system( "cls" );
            TaffMenuSettings();
            TaffShowMainMenu();
            break;

        case 51:
            system( "cls" );
            TaffMenuEditor( );
            break;

        case 52:
            exit( 0 );
            break;

        default:
            printf( "Wrong control button!" );
            system( "cls" );
            TaffShowMainMenu();
            break; }

}

void TaffMenuSettings()  {

        for (int i = 0; i <= 1; i++)
        { printf( "%s\n", lang_settings[i] ); }

        system( "pause" );
}

void TaffMenuEditor( void )  {

        printf( "%s\n%s\n", ed_options[0], ed_options[1] );

        int control = _getch( );

        switch ( control )  {
            case 49:
                TaffUnitsEditor();
                break;
        }
}
