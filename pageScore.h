/*
 * pageScore.h
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

/*
 * Bibiloth�ques
 */
#include "ihm/ihm.h"
#

//------------------------------------------------------------------------------------------------------------------

/*
 * Permet de dessiner la page du score
 */
void pageScore_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonction des coordonn�es appuy�es sur la page du score
 */
void pageScore_Actions(int16_t x, int16_t y);

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré la valeur du score des locaux
 */

uint16_t getScoreLoc(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré la valeur du score des visiteurs
 */

uint16_t getScoreVisit(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * Fonction permettant de gérer le chronomètre
 */

void chrono(void);
