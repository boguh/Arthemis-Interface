/*
 * ihm.h
 *
 *  Created on: 29 nov. 2022
 *      Author: bourdahu & bourhima
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de ne compiler qu'une seule fois
 */
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibliotheques
 */
#include "stm32f1_ili9341.h"
#include "stm32f1_xpt2046.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @enum Les types de pages possibles
 */
typedef enum {
	Page_Accueil,
	Page_Config,
	Page_Temp_Mort,
	Page_Fautes,
	Page_Score
}ihm_typePage;

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Affiche la page courante
 */
void ihm_AffichePageCourante(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Dessine une ligne d'epaisseur passee en parametre
 * @param x0 : abscisse du point de depart
 * @param y0 : ordonnee du point de depart
 * @param x1 : abscisse du point d'arrivee
 * @param y1 : ordonnee du point d'arrivee
 * @param e : epaisseur du trait
 * @param color : couleur du trait
 */
void ihm_DrawThickLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t e, uint16_t color);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Dessine un rectangle aux bords arrondis
 * @param x0 : abscisse du coin superieur gauche
 * @param y0 : ordonnee du coin superieur gauche
 * @param x1 : abscisse du coin inferieur droit
 * @param y1 : ordonnee du coin inferieur droit
 * @param RADIUS : rayon de l'arrondi du coin
 * @param color : couleur du rectangle
 */
void ihm_DrawFilledRoundedRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t RADIUS, uint16_t color);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Efface la page courante
 */
void ihm_CleanPage();

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de connaitre le type de la page
 * @ret le type de la page courante
 */
ihm_typePage ihm_GetTypePage(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de changer de page si on a plusieurs pages
 * @param page : page a afficher
 */
void ihm_changePage(ihm_typePage page);

//------------------------------------------------------------------------------------------------------------------
