/*
 * drapeau.h
 *
 *  Created on: 19 janv. 2023
 *      Author: bourdahu & bourhima
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de compiler une seule fois
 */
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioteques
 */
#include "datas/datas.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture de l'etat du drapeau local
 * ret true si leve, false sinon
 */
bool_e isRaisedDrapeau1(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture de l'etat du drapeau visiteur
 * ret true si leve, false sinon
 */
bool_e isRaisedDrapeau2(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour l'etat des drapeaux
 */
void updateDrapeaux(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour les fautes
 */
void setFautes(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de faire bouger les servomoteurs si le drapeau est leve ou non
 */
void setServos(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour les servomoteurs
 */
void updateServos(void);

//------------------------------------------------------------------------------------------------------------------
