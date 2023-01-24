/*
 * pageScore.c
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibiloth�ques
 */
#include "pageScore.h"

//------------------------------------------------------------------------------------------------------------------

//Variables static permettant de retenir le score des locaux
static uint16_t score_loc = 0;
//Variables static permettant de retenir le score des visiteurs
static uint16_t score_visit = 0;

//------------------------------------------------------------------------------------------------------------------

/*
 * Permet de dessiner la page du score
 */
void pageScore_DrawPage(void) {
	//On efface la page puis on l'initialise :
	ihm_CleanPage();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);

	ihm_DrawFilledRoundedRectangle(60,10,150,200,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(170,10,260,200,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(0,210,140,240,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(180,210,320,240,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(10,10,100,60,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(10,80,100,130,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(10,150,100,200,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(220,10,310,60,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(220,80,310,130,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(220,150,310,200,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(120,0,200,50,20,ILI9341_COLOR_WHITE);

	ILI9341_Puts(130,20, "", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_WHITE);
	ILI9341_Puts(10,10, "+1", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(10,80, "+2", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(10,150, "+3", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	char scoreS1[3];
	sprintf(scoreS1, "%d", score_loc);
	ILI9341_Puts(105,70, scoreS1, &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);

	ILI9341_Puts(260,10, "+1", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(260,80, "+2", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(260,150, "+3", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	char scoreS2[3];
	sprintf(scoreS2, "%d", score_visit);
	ILI9341_Puts(215,70, scoreS2, &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);

	ILI9341_Puts(30,220, "Chrono", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_GREEN);
	ILI9341_Puts(210,220, "Fautes", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(70,170, "Locaux", &Font_11x18, ILI9341_COLOR_GREEN, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(180,170, "Visiteur", &Font_11x18, ILI9341_COLOR_BLUE, ILI9341_COLOR_NOIR_ihm);

}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonction des coordonn�es appuy�es sur la page du score
 */
void pageScore_Actions(int16_t x, int16_t y) {
	//Incr�mente le score1 de 1
	if ((x>=10 && x<=60)&&(y>=10 && y<=60)) {
		score_loc++;
		char score[3];
		sprintf(score, "%d", score_loc);
		ILI9341_Puts(105,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score1 de 3
	if ((x>=10 && x<=60)&&(y>=150 && y<=200)) {
		score_loc = score_loc+3;
		char score[3];
		sprintf(score, "%d", score_loc);
		ILI9341_Puts(105,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score1 de 2
	if ((x>=10 && x<=60)&&(y>=80 && y<=130)) {
		score_loc = score_loc+2;
		char score[3];
		sprintf(score, "%d", score_loc);
		ILI9341_Puts(105,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score2 de 1
	if ((x>=260 && x<=310)&&(y>=10 && y<=60)) {
		score_visit++;
		char score[3];
		sprintf(score, "%d", score_visit);
		ILI9341_Puts(215,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score2 de 3
	if ((x>=260 && x<=310)&&(y>=150 && y<=200)) {
		score_visit = score_visit+3;
		char score[3];
		sprintf(score, "%d", score_visit);
		ILI9341_Puts(215,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score2 de 2
	if ((x>=260 && x<=310)&&(y>=80 && y<=130)) {
		score_visit = score_visit+2;
		char score[3];
		sprintf(score, "%d", score_visit);
		ILI9341_Puts(215,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	// Enleve 1 point � 1 pour corriger si jamais erreur (en clic sur le score1)
	if ((x>=60 && x<=150)&&(y>=10 && y<=200)) {
		if (score_loc != 0){   //eviter les score negatifs
			score_loc--;
			char score[3];
			sprintf(score, "%d", score_loc);
			ILI9341_Puts(105,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}
	}

	// Enleve 1 point � 2 pour corriger si jamais erreur (en clic sur le score2)
	if ((x>=170 && x<=260)&&(y>=10 && y<=200)) {
		if(score_visit != 0){   // eviter les scores negatifs
			score_visit--;
			char score[3];
			sprintf(score, "%d", score_visit);
			ILI9341_Puts(215,70, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}
	}

	// Vers page Fautes
	if ((x>=180 && x<=320)&&(y>=210 && y<=240)) {
		ihm_changePage(Page_Fautes);
		ihm_AffichePageCourante();
	}

	// Retour en arriere
	if ((x>=0 && x<=140)&&(y>=210 && y<=240)) {
		Systick_add_callback_function(&chrono);
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré la valeur du score des locaux
 */

uint16_t getScoreLoc(void) {
	return score_loc;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré la valeur du score des visiteurs
 */

uint16_t getScoreVisit(void) {
	return score_visit;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * Fonction permettant de gérer le chronomètre
 */

void chrono(void) {
	static uint8_t seconds = 60;
	static uint16_t t = 0;
	t++;
	if (t==1000) {
		if (seconds) {
			seconds--;
		}
		char chrono_String[3];
		sprintf(chrono_String, "%d", seconds);
		ILI9341_Puts(130, 20, chrono_String, &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_NOIR_ihm);
		t = 0;
	}
}
