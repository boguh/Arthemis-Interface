/*
 * pageAccueil.h
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibiloth�ques
 */
#include "ihm/ihm.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * Dessine la page d'accueil
 */
void pageAccueil_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonctiondes coordon�es appuy�es sur la page d'accueil
 */
void pageAccueil_Actions(int16_t x, int16_t y);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param time : nombre d'itération
 *
 * Permet de faire clignoter le texte "Cliquer"
 */
void affichage_Cliquer(void);
