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
 * Dessine la page de configuration
 */
void pageConfig_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : position appuy�e en abscisse
 * @param y : position appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonction des coordonn�es appuy�es
 */
void pageConfig_Actions(int16_t x, int16_t y);
