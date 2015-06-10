#include "Taffer.h"
#include "TaffEngine.h"

    extern char map[MAX_MAP_X][MAX_MAP_Y];

void TaffGetUserControl() {

    int control = _getch();
    //printf("%d\n", control );
    //system("pause");

        switch ( control ){
            case 72:
                TaffClearMapNode( p_tplayer->player_x, p_tplayer->player_y );

                p_tplayer->player_y -= 1;

                if ( TaffIsNodeAvailable() == true )
                   { TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y ); }
                else
                   { p_tplayer->player_y += 1;
                     TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y ); }

                break;

            case 80:
                TaffClearMapNode( p_tplayer->player_x, p_tplayer->player_y );

                p_tplayer->player_y += 1;

                 if ( TaffIsNodeAvailable() == true )
                    { TaffSetMapNode('H', p_tplayer->player_x, p_tplayer->player_y); }
                else
                    { p_tplayer->player_y -= 1;
                      TaffSetMapNode('H', p_tplayer->player_x, p_tplayer->player_y); }

                break;

            case 75:
                TaffClearMapNode( p_tplayer->player_x, p_tplayer->player_y );

                p_tplayer->player_x -= 1;

                if ( TaffIsNodeAvailable() == true )
                    { TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y ); }
                else
                    { p_tplayer->player_x += 1;
                    TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y ); }

                break;

            case 77:
                TaffClearMapNode( p_tplayer->player_x, p_tplayer->player_y );

                p_tplayer->player_x += 1;

                 if ( TaffIsNodeAvailable() == true )
                    { TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y ); }
                else
                    { p_tplayer->player_x -= 1;
                      TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y ); }

                break;

            case 112:
                TaffPlayerMenu();
                break;

            case 97:
                if ( p_tarmy == NULL )
                {
                    printf( "No armies on this map!\n" );
                    system( "pause" );
                    break;
                }
                TaffArmyListMenu();
                break;

            case 27:
                exit( 0 );
                break;

        }

}

bool TaffIsNodeAvailable(){

        if( map[p_tplayer->player_x][p_tplayer->player_y] == ' '
           && (p_tplayer->player_x != MAX_MAP_X+1 && p_tplayer->player_x != -1)
           && (p_tplayer->player_y != MAX_MAP_Y+1 && p_tplayer->player_y != -1) )
        { return true; }

        else { return false; }
}

player_t *TaffPlayerInit(int x, int y, int level, char* name)  {
    player_t *p_player;

    p_player = malloc(sizeof(player_t));

    p_player->player_x = x;
    p_player->player_y = y;
    p_player->pl_level  = level;
    p_player->pl_name = name;
    p_player->army_count = 1;

    return p_player;
}

army_t *TaffArmyInit(int x, int y, int slot_num, armyslot* as) {
    army_t * var;

    var = malloc( sizeof(army_t) );

    var->x_pos                 = x;
    var->y_pos                 = y;
    var->p_as[slot_num]		   = as;
    //var->next_army           = NULL;

    return var;
}

armyslot *TaffASInit( ) {
    armyslot *var;

    FILE * p_file = NULL;
    long l_size;
    size_t result;

    fopen_s( &p_file, "units.tfm", "rb" );

    if ( p_file == NULL) { printf( "File cannot be opened!\n" ); }

    var = malloc ( sizeof ( armyslot ) );


    result = fread( var, sizeof ( armyslot ), 1, p_file );

    //var->number         = slot_num;
    //var->u_id              = u_id;
    //var->u_movscore = u_movscore;

    return var;
}

void TaffPlayerMenu ( void )  {
    system("cls");
    printf("%s menu!\n", p_tplayer->pl_name);
    printf("Your hero level is: %d\nYour hero coorinates are: %d, %d\n", p_tplayer->pl_level, p_tplayer->player_x, p_tplayer->player_y);
    printf("Press \"Esc\" to go back to game map!\n");

    int control = _getch( );

    switch ( control )  {
    case 27:
        break;
    }
}

void TaffArmyListMenu( void )  {

    system("cls");
    printf( "You have %d armies!\n", p_tplayer->army_count );
    printf( "Army %d %s\nunit1: %d\nunit1: movescore:%d\n ", 1, p_tarmy->p_as[1]->unit_title, p_tarmy->p_as[1]->u_id, p_tarmy->p_as[1]->u_movscore );
    printf( "Army X and Y coordinates: %d and %d.\n", p_tarmy->x_pos, p_tarmy->y_pos, p_tarmy->p_as[1]->u_movscore );
    printf( "Press \"Esc\" to go back to game map!\n" );

    int control = _getch();

    switch ( control )  {
    case 27:
        break;
    }
}

/*void TaffEdGetControl( void )  {

    int control = _getch( );

    switch ( control )  {
        case 97:

            TaffArmyInit( player_t->player_x, player_t->player_y, p_tAS->number, p_tAS );
            break;
    }
}*/
