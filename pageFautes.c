/*
 * pageFautes.c
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioth�ques
 */
#include "pageFautes.h"

//------------------------------------------------------------------------------------------------------------------

//Variable static permettant de retenir le nombre de faute des locaux
static uint8_t fautes_loc = 0;
//Variable static permettant de retenir le nombre de fautes des visiteurs
static uint8_t fautes_visit = 0;

//------------------------------------------------------------------------------------------------------------------

/**
 * Dessine la page des fautes
 */
void pageFautes_DrawPage(void) {
	//On efface la page puis on l'initialise :
	ihm_CleanPage();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);

	ihm_DrawFilledRoundedRectangle(80,50,150,190,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(170,50,240,190,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(0,210,140,240,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(180,210,320,240,20,ILI9341_COLOR_NOIR_ihm);

	ILI9341_DrawFilledCircle(40,120,30,ILI9341_COLOR_BLACK);
	ILI9341_DrawFilledCircle(280,120,30,ILI9341_COLOR_BLACK);
	ILI9341_Puts(80,190, "Locaux", &Font_11x18, ILI9341_COLOR_NOIR_ihm, ILI9341_COLOR_WHITE);
	ILI9341_Puts(160,190, "Visiteur", &Font_11x18, ILI9341_COLOR_NOIR_ihm, ILI9341_COLOR_WHITE);

	ILI9341_Puts(130,10, "FAUTE", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(30,110, "+1", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(270,110, "+1", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	char scoref1[3];
	sprintf(scoref1, "%d", fautes_loc);
	ILI9341_Puts(110,110, scoref1, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	char scoref2[3];
	sprintf(scoref2, "%d", fautes_visit);
	ILI9341_Puts(200,110, scoref2, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	ILI9341_Puts(30,220, "Retour", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(200,220, "Temps Mort", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonction des coordonn�es appuy�es sur la page des fautes
 */
void pageFautes_Actions(int16_t x, int16_t y) {
//Incr�mente les fautes de 1 de 1
	if ((x>=10 && x<=60)&&(y>=100 && y<=140)) {
		fautes_loc++;
		if(fautes_loc<5){
			char score[3];
			sprintf(score, "%d", fautes_loc);
			ILI9341_Puts(110,110, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}else{
			ILI9341_DrawFilledCircle(40,120,30,ILI9341_COLOR_RED);
			ILI9341_Puts(35,110, "5", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED);
			ILI9341_Puts(110,110, "5" , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
			ILI9341_Puts(80,190, "Locaux", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_WHITE);
		}
	}

	//Incr�mente les fautes de 2 de 1
	if ((x>=260 && x<=300)&&(y>=100 && y<=140)) {
		fautes_visit++;
		if(fautes_visit<5){
			char score[3];
			sprintf(score, "%d", fautes_visit);
			ILI9341_Puts(200,110, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}else{
			ILI9341_DrawFilledCircle(280,120,30,ILI9341_COLOR_RED);
			ILI9341_Puts(275,110, "5", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_RED);
			ILI9341_Puts(200,110, "5" , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
			ILI9341_Puts(160,190, "Visiteur", &Font_11x18, ILI9341_COLOR_RED, ILI9341_COLOR_WHITE);
		}
	}

// Enleve 1 faute � 1 pour corriger si jamais erreur (en clic sur le faute1)
// !!! Ici si la faute de clic intervient � la 5em fautes alors l'equipe a fait 4 fautes mais les +1 est encore en ROUGE !!! (le changer c facile)
	if ((x>=80 && x<=150)&&(y>=50 && y<=190)) {
		if(fautes_loc != 0){      //pour pas avoir de fautes n�gatives
			fautes_loc--;
			char score[3];
			sprintf(score, "%d", fautes_loc);
			ILI9341_Puts(110,110, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}
		if(fautes_loc==4){      // pour repeindre en noir si on c'est tromp� et qu'on est pas � 5 fautes
			ILI9341_DrawFilledCircle(40,120,30,ILI9341_COLOR_BLACK);
			ILI9341_Puts(35,110, "+1", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
			ILI9341_Puts(110,110, "4" , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
			ILI9341_Puts(80,190, "Locaux", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
		}
	}

	// Enleve 1 faute � 2 pour corriger si jamais erreur (en clic sur le faute2)
	if ((x>=170 && x<=240)&&(y>=50 && y<=190)) {
		if(fautes_visit != 0){    //pour pas avoir de fautes n�gatives
			fautes_visit--;
			char score[3];
			sprintf(score, "%d", fautes_visit);
			ILI9341_Puts(200,110, score , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
		}
		if(fautes_visit == 4){   // pour repeindre en noir si on c'est tromp� et qu'on est pas � 5 fautes
			ILI9341_DrawFilledCircle(280,120,30,ILI9341_COLOR_BLACK);
			ILI9341_Puts(275,110, "+1", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
			ILI9341_Puts(200,110, "4" , &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
			ILI9341_Puts(160,190, "Visiteur", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
		}
	}

	// Vers page Temps mort
	if ((x>=180 && x<=320)&&(y>=210 && y<=240)) {
		ihm_changePage(Page_Temp_Mort);
		ihm_AffichePageCourante();
	}

	// Retour en arriere
	if ((x>=0 && x<=140)&&(y>=210 && y<=240)) {
		ihm_changePage(Page_Score);
		ihm_AffichePageCourante();
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré les fautes locaux
 */

uint8_t getFautesLoc(void) {
	return fautes_loc;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré les fautes visiteurs
 */

uint8_t getFautesVisit(void) {
	return fautes_visit;
}
