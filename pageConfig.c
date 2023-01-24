/*
 * pageAccueil.c
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibiloth�ques
 */
#include "pageConfig.h"

//------------------------------------------------------------------------------------------------------------------

//Variable static permettant de retenir qu'elle est la cat�gorie courante
static uint8_t indiceCategorie = 0;

//------------------------------------------------------------------------------------------------------------------

/**
 * Dessine la page de configuration
 */
void pageConfig_DrawPage(void) {
	//On efface la page puis on l'initialise :
	ILI9341_Fill(ILI9341_COLOR_GRIS3_ihm);

	//On dessine la fl�che de gauche :
	ILI9341_DrawFilledCircle(50,120,30,ILI9341_COLOR_BLEU_GRIS_ihm);
	ihm_DrawThickLine(40, 120, 60, 100, 2, ILI9341_COLOR_GRIS2_ihm);
	ihm_DrawThickLine(40, 120, 60, 140, 2, ILI9341_COLOR_GRIS2_ihm);

	//On dessine la fl�che de droite :
	ILI9341_DrawFilledCircle(270,120,30,ILI9341_COLOR_BLEU_GRIS_ihm);
	ihm_DrawThickLine(260, 100, 280, 120, 2, ILI9341_COLOR_GRIS2_ihm);
	ihm_DrawThickLine(260, 140, 280, 120, 2, ILI9341_COLOR_GRIS2_ihm);

	//On dessine la cat�gorie
	ihm_DrawFilledRoundedRectangle(100,80,220,140,20,ILI9341_COLOR_BLEU_GRIS_ihm);
	ILI9341_Puts(149,101, "U9", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);

	//On dessine le bouton "Lancer"
	ihm_DrawFilledRoundedRectangle(72,200,248,230,20,ILI9341_COLOR_NOIR_ihm);
	ILI9341_Puts(78,206, "Lancer le match", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_NOIR_ihm);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : position appuy�e en abscisse
 * @param y : position appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonction des coordonn�es appuy�es
 */
void pageConfig_Actions(int16_t x, int16_t y) {

	//Collision pour fl�che droite
	if ((x>=240 && x<=300)&&(y>=90 && y<=150)) {
		if (indiceCategorie==8) {
			indiceCategorie = 0;
		} else {
			indiceCategorie++;
		}
	}

	//Collision pour fleche gauche
	if ((x>=20 && x<=80)&&(y>=90 && y<=150)) {
		if (indiceCategorie==0) {
			indiceCategorie = 8;
		} else {
			indiceCategorie--;
		}
	}

	//Affichage de la cat�gorie courante
	switch (indiceCategorie) {
		case 1 :
			ihm_DrawFilledRoundedRectangle(100,80,220,140,20,ILI9341_COLOR_BLEU_GRIS_ihm);
			ILI9341_Puts(149,101, "U9", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 2 :
			ILI9341_Puts(143,101, "U11", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 3 :
			ILI9341_Puts(143,101, "U13", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 4 :
			ILI9341_Puts(143,101, "U15", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 5 :
			ILI9341_Puts(143,101, "U17", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 6 :
			ILI9341_Puts(143,101, "U18", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 7 :
			ihm_DrawFilledRoundedRectangle(100,80,220,140,20,ILI9341_COLOR_BLEU_GRIS_ihm);
			ILI9341_Puts(143,101, "U20", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		case 8 :
			ILI9341_Puts(127,101, "Senior", &Font_11x18, ILI9341_COLOR_GRIS2_ihm, ILI9341_COLOR_BLEU_GRIS_ihm);
			break;
		default :
			break;
	}

	if ((x>=55 && x<=265)&&(y>=180 && y<=250)) {
		ihm_changePage(Page_Score);
		ihm_AffichePageCourante();
	}
}
