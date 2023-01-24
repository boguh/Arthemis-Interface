/*
 * affichage.h
 *
 *  Created on: 15 d�c. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioth�ques :
 */
#include "pageScore/pageScore.h"
#include "pageAccueil/pageAccueil.h"
#include "pageConfig/pageConfig.h"
#include "pageFautes/pageFautes.h"
#include "pageTM/pageTM.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonn�e appuy�e en abscisse
 * @param y : coordonn�e appuy�e en ordonn�e
 *
 * Permet de r�aliser une action correspondante aux coordonn�es appuy�es (en fonction de la page courante)
 */
void affichage_ActionOnTouch(int16_t x, int16_t y);

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de savoir si l'utilisateur a ppuy� sur la dalle tactile
 */
void affichage_Listen(void);
