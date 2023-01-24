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
 * Dessine la page d'accueil
 */
void pageAccueil_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonnée appuyée en abscisse
 * @param y : coordonnée appuyée en ordonnée
 *
 * Permet d'effectuer une action en fonctiondes coordonées appuyées sur la page d'accueil
 */
void pageAccueil_Actions(int16_t x, int16_t y);
