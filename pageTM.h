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

/**
 * Bibiloth�ques
 */
#include "ihm/ihm.h"
#include "pageScore/pageScore.h"
#include "pageFautes/pageFautes.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet d'afficher la page pendant un temps-mort
 */
void pageTM_DrawPage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet de r�aliser une action en fonction des coordonn�es appuy�es sur la page des temps-mort
 */
void pageTM_Actions(int16_t x, int16_t y);
