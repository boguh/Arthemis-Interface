/*
 * pageTM.c
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioth�ques
 */
#include "pageTM.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet d'afficher la page pendant un temps-mort
 */
void pageTM_DrawPage(void) {
	//On efface la page puis on l'initialise :
	ihm_CleanPage();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);
	ihm_DrawFilledRoundedRectangle(40,0,280,60,20,ILI9341_COLOR_NOIR_ihm);

	ihm_DrawFilledRoundedRectangle(10,70,150,140,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(170,70,310,140,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(10,160,150,220,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(170,160,310,220,20,ILI9341_COLOR_NOIR_ihm);

	ILI9341_Puts(145,0, "Time", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_BLACK);
	ILI9341_Puts(50,141, "Locaux", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_GREEN);
	ILI9341_Puts(195,141, "Visiteur", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE);

	ILI9341_Puts(50,115, "Score", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(50,200, "fautes", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(210,115, "Score", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(210,200, "fautes", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	ILI9341_Puts(145,20, "60", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(173,20, "s", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	char score1[3];
	sprintf(score1, "%d", getScoreLoc());
	ILI9341_Puts(75,95, score1 , &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	char score2[3];
	sprintf(score2, "%d", getScoreVisit());
	ILI9341_Puts(240,95, score2, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	char score3[3];
	sprintf(score3, "%d", getFautesLoc());
	ILI9341_Puts(75,180, score3, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	char score4[3];
	sprintf(score4, "%d", getFautesVisit());
	ILI9341_Puts(240,180, score4, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	if(getFautesLoc()>4){
		char score3[3];
		sprintf(score3, "%d", getFautesLoc());
		ILI9341_Puts(75,180, score3, &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_BLACK);
		ILI9341_Puts(50,200, "fautes", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_BLACK);
	}

	if(getFautesVisit()>4){
		char score4[3];
		sprintf(score4, "%d", getFautesVisit());
		ILI9341_Puts(240,180, score4, &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_BLACK);
		ILI9341_Puts(210,200, "fautes", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_BLACK);
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet de r�aliser une action en fonction des coordonn�es appuy�es sur la page des temps-mort
 */
void pageTM_Actions(int16_t x, int16_t y) {
	if ((x>=40 && x<=280)&&(y>=0 && y<=60)) {
		int led = 0;
		for (int i=60; i>-1; i--){
			led++;
			if(led%2==0){                 //permet de faire clignoter un rond rouge pendant le temps mort
				ILI9341_DrawFilledCircle(230,30,10,ILI9341_COLOR_RED);
			}else{
				ILI9341_DrawFilledCircle(230,30,10,ILI9341_COLOR_BLACK);
			}
			char score5[3];
			sprintf(score5, "%d", i);
			ILI9341_Puts(145,20, score5, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
			Delay_us(1000000); //attendre 1s
			if(i<11){
				ihm_DrawFilledRoundedRectangle(155,20,170,40,20,ILI9341_COLOR_BLACK); //On dessine pour caccher le 0 qui nous donne 90 80 70...
			}
			if((x>=0 && x<=320)&&(y>=80 && y<=240)){  // on change de page si on touche n'importe quoi sauf le chrono
				ihm_changePage(Page_Accueil);
				ihm_AffichePageCourante();
			}
		}
	}

	if((x>=0 && x<=320)&&(y>=80 && y<=240)){   // on change de page si on touche n'importe quoi sauf le chrono
		ihm_changePage(Page_Score);
		ihm_AffichePageCourante();
	}
}
