/*
 * Test.c
 *
 *  Created on: 5 janv. 2023
 *      Author: bourdahu
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
#include "buzzer/buzzer.h"
#include "drapeau/drapeau.h"
#include "ihm/ihm.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le PIN associé est en etat haut (ici PIN A4)
 * @ret true si test valide, false sinon
 */
bool_e test_Buzzer_1(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si la commande des servomoteurs fonctionne (vérification visuelle)
 */
void test_Drapeau_1(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le dessin sur l'ecran fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_ihm_1(void);
//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le tactile fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_ihm_2(void);
//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si la reception par l'UART2 fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_Bluetooth_1(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le match est bien initialisé et si l'accesseur fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_MatchInit_1(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si la taille du buffer est correcte
 * @ret true si test valide, false sinon
 */
bool_e test_BufferInit_1(void);

//------------------------------------------------------------------------------------------------------------------
