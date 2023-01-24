/*
 * Test.c
 *
 *  Created on: 5 janv. 2023
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibiloteques
 */
#include "Test.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le PIN associé est en etat haut (ici PIN A4)
 * @ret true si test valide, false sinon
 */
bool_e test_Buzzer_1(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	return GPIO_PIN_SET==HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si la commande des servomoteurs fonctionne (vérification visuelle)
 */
void test_Drapeau_1(){
	PWM_run(TIMER1_ID, TIM_CHANNEL_2, FALSE,2000, 80, FALSE);
	PWM_run(TIMER1_ID, TIM_CHANNEL_3, FALSE,2000, 80, FALSE);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le dessin sur l'ecran fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_ihm_1(){
	ILI9341_Fill(ILI9341_COLOR_BLACK);
	return ILI9341_ReadPixel(0, 0);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le tactile fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_ihm_2(){
	return XPT2046_getMedianCoordinates(pX, pY, XPT2046_COORDINATE_SCREEN_RELATIVE);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si la reception par l'UART2 fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_Bluetooth_1(){
	return UART_data_ready(UART2_ID);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si le match est bien initialisé et si l'accesseur fonctionne
 * @ret true si test valide, false sinon
 */
bool_e test_MatchInit_1(){
	return getFautes_loc()==0;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de voir si la taille du buffer est correcte
 * @ret true si test valide, false sinon
 */
bool_e test_BufferInit_1(){
	return BUFFER_SIZE==10;
}

//------------------------------------------------------------------------------------------------------------------
