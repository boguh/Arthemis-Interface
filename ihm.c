/*
 * ihm.c
 *
 *  Created on: 29 nov. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioth�ques
 */
#include "ihm.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * On d�clare une variable static qui permet de retenir la page courante affich�e
 */
static ihm_typePage type_page_courante = Page_Accueil;

//------------------------------------------------------------------------------------------------------------------

/**
 * Efface la page courante
 */
void ihm_CleanPage() {
	ILI9341_Fill(ILI9341_COLOR_WHITE);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x0 : abscisse du coin sup�rieur gauche
 * @param y0 : ordonn�e du coin sup�rieur gauche
 * @param x1 : abscisse du coin inf�rieur droit
 * @param y1 : ordonn�e du coin inf�rieur droit
 * @param RADIUS : rayon de l'arrondi du coin
 * @param color : couleur du rectangle
 */
void ihm_DrawFilledRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, int8_t RADIUS, uint16_t color) {

	if (x1-x0<2*RADIUS) {
		RADIUS = (x1-x0)/2;
	}
	if (y1-y0<2*RADIUS) {
			RADIUS = (y1-y0)/2;
		}

	//On dessine les cercles qui constituent les angles du rectangles arrondi :
	ILI9341_DrawFilledCircle(x0+RADIUS, y0+RADIUS, RADIUS, color); //Top left
	ILI9341_DrawFilledCircle(x1-RADIUS, y0+RADIUS, RADIUS, color); // Top right
	ILI9341_DrawFilledCircle(x1-RADIUS, y1-RADIUS, RADIUS, color); //Bottom right
	ILI9341_DrawFilledCircle(x0+RADIUS, y1-RADIUS, RADIUS, color); //Bottom left

	//On dessine les rectangles qui constituent le rectangles arrondi :
	ILI9341_DrawFilledRectangle(x0+RADIUS, y0, x1-RADIUS, y1, color); //Top to bottom
	ILI9341_DrawFilledRectangle(x0, y0+RADIUS, x1, y1-RADIUS, color); //Left to right
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x0 : abscisse du point de d�part
 * @param y0 : ordonn�e du point de d�part
 * @param x1 : abscisse du point d'arriv�e
 * @param y1 : ordonn�e du point d'arriv�e
 * @param e : �paisseur du trait
 * @param color : couleur du trait
 *
 * Permet de dessiner un trait d'�paisseur variable
 */
void ihm_DrawThickLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t e, uint16_t color) {

	//On dessine la ligne de base
	ILI9341_DrawLine(x0, y0, x1, y1, color);

	if (y0==y1) {
		for (int i=0 ; i<e+1 ; i++) {
			ILI9341_DrawLine(x0, y0-i, x1, y1-i, color);
			ILI9341_DrawLine(x0, y0+i, x1, y1+i, color);
		}
	}
	if (x0==x1) {
		for (int i=0 ; i<e+1 ; i++) {
			ILI9341_DrawLine(x0+i, y0, x1+i, y1, color);
			ILI9341_DrawLine(x0-i, y0, x1-i, y1, color);
		}
	}
	if (x1>x0 && y1>y0) {
		for (int i=0 ; i<e+1 ; i++) {
			ILI9341_DrawLine(x0+i, y0, x1, y1-i, color);
			ILI9341_DrawLine(x0, y0+i, x1-i, y1, color);
		}
	}
	if (x0<x1 && y1<y0) {
		for (int i=0 ; i<e+1 ; i++) {
			ILI9341_DrawLine(x0+i, y0, x1, y1+i, color);
			ILI9341_DrawLine(x0, y0-i, x1-i, y1, color);
		}
	}

}

//------------------------------------------------------------------------------------------------------------------

/**
 * @ret le type de la page
 *
 * permet de conna�tre le type de la page
 */
ihm_typePage ihm_GetTypePage(void) {
	return type_page_courante;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param page : page � afficher
 *
 * Permet de changer de page
 */
void ihm_changePage(ihm_typePage page) {
	type_page_courante = page;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * Affiche la page courante
 */
void ihm_AffichePageCourante(void) {
	switch (ihm_GetTypePage()) {
		case Page_Accueil :
			pageAccueil_DrawPage();
			break;
		case Page_Config :
			pageConfig_DrawPage();
			break;
		case Page_Score :
			pageScore_DrawPage();
			break;
		case Page_Temp_Mort :
			pageTM_DrawPage();
			break;
		case Page_Fautes :
			pageFautes_DrawPage();
			break;
		default :
			break;
	}
}

//------------------------------------------------------------------------------------------------------------------

