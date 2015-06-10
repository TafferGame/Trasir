#ifndef TAFFENGINE_H_INCLUDED
#define TAFFENGINE_H_INCLUDED



#endif // TAFFENGINE_H_INCLUDED
#define MAX_ARMY_UNITS 8

#include "Taffer.h"

//Player main structure
int left_scr_border_x,   upper_scr_border_y,
     right_scr_border_x, lower_scr_border_y;

typedef struct {
    int player_x, player_y, pl_level, army_count;
    char *pl_name;
} player_t;

typedef struct {
    int number, u_id, u_movscore;
    char unit_title[50];
    struct armyslot *next_as;
} armyslot;

typedef struct {
    int x_pos, y_pos;
    armyslot *p_as[MAX_ARMY_UNITS];
    struct army_t *next_army;
} army_t;


player_t *p_tplayer;
armyslot *p_root_as;
armyslot *p_tAS;
army_t *p_tarmy;
army_t *root_army;

player_t *TaffPlayerInit(int x, int y, int level, char* name);
army_t   *TaffArmyInit(int x, int y, int slot_num, armyslot* as);
armyslot *TaffASInit( void );

void TaffPlayerMenu( void );
void TaffArmyListMenu( void );
void TaffEdGetControl ( void );

//Editor functions
void TaffUnitsEditor( void );
