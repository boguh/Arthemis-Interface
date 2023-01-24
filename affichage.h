/*
 * affichage.h
 *
 *  Created on: 15 déc. 2022
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibliothèques :
 */
#include "pageScore/pageScore.h"
#include "pageAccueil/pageAccueil.h"
#include "pageConfig/pageConfig.h"
#include "pageFautes/pageFautes.h"
#include "pageTM/pageTM.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @param x : coordonnée appuyée en abscisse
 * @param y : coordonnée appuyée en ordonnée
 *
 * Permet de réaliser une action correspondante aux coordonnées appuyées (en fonction de la page courante)
 */
void affichage_ActionOnTouch(int16_t x, int16_t y);

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de savoir si l'utilisateur a ppuyé sur la dalle tactile
 */
void affichage_Listen(void);
