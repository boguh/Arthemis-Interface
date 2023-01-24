/*
 * pageAccueil.c
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibiloth�que
 */
#include "pageAccueil.h"

//------------------------------------------------------------------------------------------------------------------

static volatile uint16_t t_accueil = 0;


/**
 * Dessine la page d'accueil
 */
void pageAccueil_DrawPage(void) {
	//On efface la page puis on l'initialise :
	ihm_CleanPage();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);
	ILI9341_Fill(ILI9341_COLOR_GRIS3_ihm);

	ihm_DrawThickLine(80, 210, 120, 100, 3, ILI9341_COLOR_BLACK);
	ihm_DrawThickLine(120, 100, 160, 210, 3, ILI9341_COLOR_BLACK);
	ihm_DrawThickLine(110, 177,160, 210,  3, ILI9341_COLOR_BLACK);
	ihm_DrawThickLine(200, 100, 200, 210, 2, ILI9341_COLOR_BLACK);
	ihm_DrawThickLine(180, 100, 220, 100, 2, ILI9341_COLOR_BLACK);
	ihm_DrawThickLine(180, 210, 220, 210, 2, ILI9341_COLOR_BLACK);

	ILI9341_DrawFilledRectangle(0,13,320,80,ILI9341_COLOR_WHITE);
	ILI9341_Puts(70,20, "Artemis Interface", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(100,50, "BIENVENUE", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

	//Systick_add_callback_function(&affichage_Cliquer);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonctiondes coordon�es appuy�es sur la page d'accueil
 */
void pageAccueil_Actions(int16_t x, int16_t y) {
	if((x>=10 && x<=310)&&(y>=10 && y<=230)){
		ILI9341_DrawFilledRectangle(230,200,320,240,ILI9341_COLOR_GRIS3_ihm);
		ILI9341_DrawFilledRectangle(0,0,320,13,ILI9341_COLOR_BLACK);
		ILI9341_DrawFilledRectangle(0,227,320,240,ILI9341_COLOR_BLACK);
		//Systick_remove_callback_function(&affichage_Cliquer);
		for (int i=5; i<315; i++){
			ILI9341_DrawFilledCircle(i,85,5,ILI9341_COLOR_BLACK);
			Delay_us(5000);
		}
		ihm_changePage(Page_Config);
		ihm_AffichePageCourante();
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param time : nombre d'itération
 *
 * Permet de faire clignoter le texte "Cliquer"
 */
void affichage_Cliquer(void){
	//TODO : add to the callback function the ability to blink and to interact w/ the screen
	t_accueil++;
	if (t_accueil<1000) {
		if(t_accueil%4 != 0){
			ILI9341_Puts(230,200, "Cliquer", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_GRIS3_ihm);
		}else{
			ILI9341_Puts(230,200, "Cliquer", &Font_11x18, ILI9341_COLOR_GRIS3_ihm, ILI9341_COLOR_GRIS3_ihm);
		}
	} else {
		t_accueil = 0;
	}
}
