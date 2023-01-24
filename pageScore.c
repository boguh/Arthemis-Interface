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

static volatile uint8_t seconds = 60;
static volatile uint16_t t = 0;
static uint16_t chrono_color = 0xF000;
static bool_e chrono_state = TRUE;
static char chrono_String[5];

//------------------------------------------------------------------------------------------------------------------

/*
 * Permet de dessiner la page du score
 */
void pageScore_DrawPage(void) {
	//On efface la page puis on l'initialise :
	ihm_CleanPage();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);

	ihm_DrawFilledRoundedRectangle(10,10,100,60,20,0x8610);
	ILI9341_Puts(30,25, "+1", &Font_11x18, ILI9341_COLOR_BLACK, 0x8610);

	ihm_DrawFilledRoundedRectangle(10,80,100,130,20,0x3DE7);
	ILI9341_Puts(30,95, "+2", &Font_11x18, ILI9341_COLOR_BLACK, 0x3DE7);

	ihm_DrawFilledRoundedRectangle(10,150,100,200,20,0x2384);
	ILI9341_Puts(30,165, "+3", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, 0x2384);

	ihm_DrawFilledRoundedRectangle(60,10,150,200,20,ILI9341_COLOR_NOIR_ihm);
	char scoreS1[3];
	sprintf(scoreS1, "%d", score_loc);
	ILI9341_Puts(100,100, scoreS1, &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(90,120, "LOC", &Font_11x18, 0x8610, ILI9341_COLOR_NOIR_ihm);

	ihm_DrawFilledRoundedRectangle(220,10,310,60,20,0x759B);
	ILI9341_Puts(270,25, "+1", &Font_11x18, ILI9341_COLOR_BLACK, 0x759B);

	ihm_DrawFilledRoundedRectangle(220,80,310,130,20,0x1C3A);
	ILI9341_Puts(270,95, "+2", &Font_11x18, ILI9341_COLOR_BLACK, 0x1C3A);

	ihm_DrawFilledRoundedRectangle(220,150,310,200,20,0x01AB);
	ILI9341_Puts(270,165, "+3", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, 0x01AB);

	ihm_DrawFilledRoundedRectangle(170,10,260,200,20,ILI9341_COLOR_NOIR_ihm);
	char scoreS2[3];
	sprintf(scoreS2, "%d", score_visit);
	ILI9341_Puts(220,100, scoreS2, &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(190,120, "VISIT", &Font_11x18, 0x759B, ILI9341_COLOR_NOIR_ihm);

	ihm_DrawFilledRoundedRectangle(90,210,230,240,20,ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(130,220, "FAUTES", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);

	ILI9341_DrawFilledRectangle(120,0,200,50,0x3165);
	ILI9341_Puts(135,20, " ", &Font_11x18, 0xF000, 0x3165);

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
		ILI9341_Puts(100,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score1 de 3
	if ((x>=10 && x<=60)&&(y>=150 && y<=200)) {
		score_loc = score_loc+3;
		char score[3];
		sprintf(score, "%d", score_loc);
		ILI9341_Puts(100,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score1 de 2
	if ((x>=10 && x<=60)&&(y>=80 && y<=130)) {
		score_loc = score_loc+2;
		char score[3];
		sprintf(score, "%d", score_loc);
		ILI9341_Puts(100,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score2 de 1
	if ((x>=260 && x<=310)&&(y>=10 && y<=60)) {
		score_visit++;
		char score[3];
		sprintf(score, "%d", score_visit);
		ILI9341_Puts(220,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score2 de 3
	if ((x>=260 && x<=310)&&(y>=150 && y<=200)) {
		score_visit = score_visit+3;
		char score[3];
		sprintf(score, "%d", score_visit);
		ILI9341_Puts(220,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	//Incr�mente le score2 de 2
	if ((x>=260 && x<=310)&&(y>=80 && y<=130)) {
		score_visit = score_visit+2;
		char score[3];
		sprintf(score, "%d", score_visit);
		ILI9341_Puts(220,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	}

	// Enleve 1 point � 1 pour corriger si jamais erreur (en clic sur le score1)
	if ((x>=60 && x<=150)&&(y>=10 && y<=200)) {
		if (score_loc != 0){   //eviter les score negatifs
			score_loc--;
			char score[3];
			sprintf(score, "%d", score_loc);
			ILI9341_Puts(100,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}
	}

	// Enleve 1 point � 2 pour corriger si jamais erreur (en clic sur le score2)
	if ((x>=170 && x<=260)&&(y>=10 && y<=200)) {
		if(score_visit != 0){   // eviter les scores negatifs
			score_visit--;
			char score[3];
			sprintf(score, "%d", score_visit);
			ILI9341_Puts(220,100, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}
	}

	// Vers page Fautes
	if ((x>=180 && x<=320)&&(y>=210 && y<=240)) {
		ihm_changePage(Page_Fautes);
		ihm_AffichePageCourante();
	}

	//TODO : quand on clique sur le chrono "00:00" lance celui-ci, si déjà lancer cela le met en pause
	if ((x>=120 && x<=200)&&(y>=0 && y<=50)) {
		if (chrono_state) {
			chrono_color = 0xF000;
			Systick_add_callback_function(&chrono);
			chrono_state = FALSE;
		} else {
			chrono_color = 0xFDE5;
			Systick_remove_callback_function(&chrono);
			chrono_state = TRUE;
		}
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
	//TODO : fix it
	t++;
	if (t==1000) {
		if (seconds) {
			seconds--;
		}
		sprintf(chrono_String, "%d", seconds);
		ILI9341_Puts(130, 20, chrono_String, &Font_11x18, chrono_color, 0x3165);
		t = 0;
	}
}
