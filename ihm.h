/*
 * ihm.h
 *
 *  Created on: 29 nov. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

//import des bibiloth�ques :
#include "stm32f1_ili9341.h"
#include "stm32f1_xpt2046.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pour utiliser sleep

//------------------------------------------------------------------------------------------------------------------

//Les pages possibles :
typedef enum {
	Page_Accueil,
	Page_Config,
	Page_Temp_Mort,
	Page_Fautes,
	Page_Score
}ihm_typePage;

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
void ihm_DrawThickLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t e, uint16_t color);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x0 : abscisse du coin sup�rieur gauche
 * @param y0 : ordonn�e du coin sup�rieur gauche
 * @param x1 : abscisse du coin inf�rieur droit
 * @param y1 : ordonn�e du coin inf�rieur droit
 * @param RADIUS : rayon de l'arrondi du coin
 * @param color : couleur du rectangle
 */
void ihm_DrawFilledRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, int8_t RADIUS, uint16_t color);

//------------------------------------------------------------------------------------------------------------------

/**
 * Efface la page courante
 */
void ihm_CleanPage();

//------------------------------------------------------------------------------------------------------------------

/**
 * @ret le type de la page
 *
 * permet de conna�tre le type de la page
 */
ihm_typePage ihm_GetTypePage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param page : page � afficher
 *
 * Permet de changer de page
 */
void ihm_changePage(ihm_typePage page);

//------------------------------------------------------------------------------------------------------------------

/**
 * Affiche la page courante
 */
void ihm_AffichePageCourante(void);
