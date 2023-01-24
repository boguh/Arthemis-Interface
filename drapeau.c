/*
 * drapeau.c
 *
 *  Created on: 19 janv. 2023
 *      Author: bourdahu & bourhima
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibliotheques
 */
#include "drapeau.h"
#include "stm32f1_pwm.h"
#include "stm32f1_timer.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * Déclaration des variables
 */
bool_e drapeau1 = TRUE;
bool_e drapeau2 = TRUE;

uint8_t fautes_locaux = 0;
uint8_t fautes_vistiteurs = 0;

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture de l'etat du drapeau local
 * ret true si leve, false sinon
 */
bool_e isRaisedDrapeau1(){
	return drapeau1;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture de l'etat du drapeau visiteur
 * ret true si leve, false sinon
 */
bool_e isRaisedDrapeau2(){
	return drapeau2;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour l'etat des drapeaux
 */
void updateDrapeaux(){
	drapeau1 = (fautes_locaux==5);
	drapeau2 = (fautes_vistiteurs==5);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour les fautes
 */
void setFautes(){
	fautes_locaux = getFautes_loc();
	fautes_vistiteurs = getFautes_visit();
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de faire bouger les servomoteurs si le drapeau est leve ou non
 */
void setServos(){
	setFautes();
	updateDrapeaux();
	if (isRaisedDrapeau1()) {
		PWM_run(TIMER1_ID, TIM_CHANNEL_3, FALSE,2000, 80, FALSE);
	} else {
		PWM_run(TIMER1_ID, TIM_CHANNEL_3, FALSE,2000, 30, FALSE);
	}
	if (isRaisedDrapeau2()) {
		PWM_run(TIMER1_ID, TIM_CHANNEL_2, FALSE,2000, 30, FALSE);
	} else {
		PWM_run(TIMER1_ID, TIM_CHANNEL_2, FALSE,2000, 80, FALSE);
		PWM_run(TIMER1_ID, TIM_CHANNEL_3, FALSE,2000, 80, FALSE);
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour les servomoteurs
 */
void updateServos(){
	setServos();
}

//------------------------------------------------------------------------------------------------------------------
