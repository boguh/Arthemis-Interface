/*
 * affichage.c
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioth�ques :
 */
#include "affichage.h"

//------------------------------------------------------------------------------------------------------------------

void affichage_ActionOnTouch(int16_t x, int16_t y) {
	switch (ihm_GetTypePage()) {
		case Page_Accueil :
			pageAccueil_Actions(x,y);
			break;
		case Page_Config :
			pageConfig_Actions(x,y);
			break;
		case Page_Score :
			pageScore_Actions(x,y);
			break;
		case Page_Temp_Mort :
			pageTM_Actions(x,y);
			break;
		case Page_Fautes :
			pageFautes_Actions(x,y);
			break;
		default :
			break;
	}
}

//------------------------------------------------------------------------------------------------------------------

void affichage_Listen(void) {

	//Coordon�es appuy�es
	static int16_t static_x,static_y;
	int16_t x, y;

	static volatile uint8_t t = 0;
	if (t) {
		t--;
	}

	//V�rification de l'appui
	if(XPT2046_getMedianCoordinates(&x, &y, XPT2046_COORDINATE_SCREEN_RELATIVE) && !t) {
		static_x = x;
		static_y = y;

		t = 50;

		//On effectue une action apr�s l'appui :
		affichage_ActionOnTouch(static_x, static_y);
	}
}
