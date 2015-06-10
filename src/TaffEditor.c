#include "Taffer.h"
#include "TaffEngine.h"

void TaffUnitsEditor( )  {

    FILE *p_funits = NULL;
    int control;
	armyslot * p_root_as = malloc(sizeof(armyslot));
    armyslot * as_iterator;

	//p_root_as->next_as = NULL;
	//p_root_as->unit_title = malloc(sizeof(p_root_as->unit_title));

	system("cls");

	printf("Welcome to Taffer unit editor!\n");
	printf("Please, enter unit title name: ");
	scanf_s("%s", p_root_as->unit_title, _countof(p_root_as->unit_title));
	printf("\nPlease enter unit id: ");
	scanf_s("%i", &p_root_as->u_id);
	printf("\nPlease enter unit move score: ");
	scanf_s("%i", &p_root_as->u_movscore);
	printf("\nDo you want to create next unit (y\n) ?\n");

	control = _getch();

	switch (control)  {
	case 121:
		p_root_as->next_as = malloc(sizeof(armyslot));
		TaffShowMainMenu();
		break;

	case 110:

		fopen_s(&p_funits, "units.tfm", "wb");

		fwrite(p_root_as, sizeof(armyslot), 1, p_funits);

		fclose(p_funits);

		TaffShowMainMenu();

		break;

	default:
		printf("Wrong control button!\n");
		TaffShowMainMenu();
		break;
		}

}
