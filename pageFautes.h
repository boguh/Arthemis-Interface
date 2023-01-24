/*
 * pageFautes.h
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
 * Dessine la page des fautes
 */
void pageFautes_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet d'effectuer une action en fonction des coordonn�es appuy�es sur la page des fautes
 */
void pageFautes_Actions(int16_t x, int16_t y);

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré les fautes locaux
 */

uint8_t getFautesLoc(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de récupéré les fautes visiteurs
 */

uint8_t getFautesVisit(void);
