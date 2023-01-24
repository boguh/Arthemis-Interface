/*
 * buzzer.c
 *
 *  Created on: 19 janv. 2023
 *      Author: bourdahu & bourhima
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibliotheques
 */
#include "buzzer.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief On initialise les variables de la machine à etats qui controle le buzzer
 */
bool_e chronoS = FALSE;
int tempbool = 0;

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'actualiser l'etat courant du chrono
 */
void setChrono_state(){
	chronoS = getChrono_state();
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de declencher le buzzer si les conditions sont remplies
 */
void updateBuzzer(){
	setChrono_state();
	if (getTypeCourant()==chrono_state) {
		if (!chronoS && !tempbool) {
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
			HAL_Delay(200);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
			tempbool = 1;
		} else {
			tempbool = 0;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief permet d'initialiser le buzzer
 */
void initBuzzer(){
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_4;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Pull = GPIO_NOPULL;
	gpio_init.Speed =  GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOA, &gpio_init);
}

//------------------------------------------------------------------------------------------------------------------
