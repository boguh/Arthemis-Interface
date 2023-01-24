/*
 * datas.h
 *
 *  Created on: 17 janv. 2023
 *      Author: bourdahu & bourhima
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Permet de compiler une seule fois
 */
#pragma once

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibilotheques
 */
#include "stm32f1_ili9341.h"
#include "stm32f1_xpt2046.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pour utiliser sleep
#include "systick.h"
#include "stm32f1_uart.h"
#include "ihm/ihm.h"
#include "buzzer/buzzer.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @struct Structure des donnees d'un match
 */
typedef struct {
	uint16_t score_loc;
	uint16_t score_visit;
	uint8_t fautes_loc;
	uint8_t fautes_visit;
	uint8_t period;
	uint8_t chrono_state;
} Match;

//------------------------------------------------------------------------------------------------------------------

/**
 * @enum Types possibles que peuvent prendre les donnees
 */
typedef enum {
	score_loc,
	score_visit,
	fautes_loc,
	fautes_visit,
	period,
	chrono_state
}datatype;

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture des fautes des locaux
 * @return fautes_loc
 */
uint8_t getFautes_loc(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture des fautes des visiteurs
 * @return fautes_visit
 */
uint8_t getFautes_visit(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture de l'etat du chrono
 * @return chrono_state
 */
uint8_t getChrono_state(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture du type de donnee courant
 * @return typeCourant
 */
datatype getTypeCourant();

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en ecriture des fautes des locaux
 * @param val
 */
void setScoreLoc(uint8_t val);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'ajouter les donnees recues par bluetooth au buffer
 */
void addToBuffer(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'initialiser le buffer avant une nouvelle acquisition
 */
void initBuffer(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de recuperer le type de donnee a modifier
 */
void setDatatype(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de recuperer la nouvelle valeur de la donnee a modifier
 */
void setData(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'actualiser les donnees du tableau d'affichage
 */
void updateData(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'initialiser l'ecran
 */
void initScreen(void);

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'actualiser l'ecran
 */
void updateScreen(void);

//------------------------------------------------------------------------------------------------------------------
