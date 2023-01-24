/*
 * pageAccueil.h
 *
 *  Created on: 15 déc. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibilothèques
 */
#include "ihm/ihm.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * Dessine la page de configuration
 */
void pageConfig_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : position appuyée en abscisse
 * @param y : position appuyée en ordonnée
 *
 * Permet d'effectuer une action en fonction des coordonnées appuyées
 */
void pageConfig_Actions(int16_t x, int16_t y);
