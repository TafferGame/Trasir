#include "Taffer.h"
#include "TaffEngine.h"

char map[MAX_MAP_X][MAX_MAP_Y];

int TaffMapInit() {

        for ( int i = 1; i <= MAX_MAP_X-2; i++ )
        {
            for ( int j = 1; j <= MAX_MAP_Y-2; j++ )
            {
                map[i][j] = ' ';
            }
            map[0][i] = '|';
            map[i][0] = '-';
            map[i][MAX_MAP_X-1] = '-';
            map[MAX_MAP_X-1][i] = '|';
        }

        TaffSetMapNode( 'A', p_tarmy->x_pos, p_tarmy->y_pos );
        TaffSetMapNode( 'T', 98, 98 );
        TaffSetMapNode( 'H', p_tplayer->player_x, p_tplayer->player_y );

        left_scr_border_x   = 79; upper_scr_border_y = 79;
        right_scr_border_x = 99; lower_scr_border_y = 99;


        if (map[9][9] != 0)
        { return 0; }

        return 1;
}

void TaffEdInit( void )  {

        for ( int i = 1; i <= MAX_MAP_X - 2; i++ )
            {
                for ( int j = 1; j <= MAX_MAP_Y - 2; j++ )
                {
                    map[i][j] = ' ';
                }
            map[0][i] = '|';
            map[i][0] = '-';
            map[i][MAX_MAP_X-1] = '-';
            map[MAX_MAP_X-1][i] = '|';
        }

        left_scr_border_x   = 79; upper_scr_border_y = 79;
        right_scr_border_x = 79; lower_scr_border_y = 99;
}

void TaffSetMapNode( char value, int x, int y ) {

        map[x][y] = value;

}

void TaffClearMapNode(int x, int y) {

        map[x][y] =' ';

}

void TaffRenderMap() {

    system( "cls" );
        if ( p_tplayer->player_x == left_scr_border_x && (left_scr_border_x <= 79 || left_scr_border_x >= 0) )  {
            left_scr_border_x  -= 1;
            right_scr_border_x -=1;
        }


        else if ( p_tplayer->player_y == upper_scr_border_y && (upper_scr_border_y <= 79 || upper_scr_border_y >= 0) )  {
             upper_scr_border_y -= 1;
             lower_scr_border_y -= 1;
        }

        else if ( p_tplayer->player_x == right_scr_border_x && right_scr_border_x <=99 )  {
            right_scr_border_x += 1;
            left_scr_border_x   += 1;
        }

        else if ( p_tplayer->player_y == lower_scr_border_y && lower_scr_border_y <= 99)  {
            lower_scr_border_y +=1;
            upper_scr_border_y += 1;
        }

        for ( int i = 0; i <= MAX_NODES_TO_DISP; i++ )
        {
            for ( int j = 0; j <= MAX_NODES_TO_DISP; j++ )
            {
                printf( "%c", map[j + left_scr_border_x][i + upper_scr_border_y] );
            }
            printf("\n");
        }
        printf("Press \"P\" for hero menu or Press \"A\" for armies menu!\n");
        printf("Player x & Player Y: %d, %d\n", p_tplayer->player_x, p_tplayer->player_y);
}
