/**
  ******************************************************************************
  * @file    main.c
  * @author  bourdahu & bourhima
  * @date    10 nov. 2022
  * @brief   Default main function.
  ******************************************************************************
*/

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioteques
 */
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "macro_types.h"
#include "systick.h"
#include "tft_ili9341/stm32f1_ili9341.h"
#include "tft_ili9341/stm32f1_xpt2046.h"
#include "datas/datas.h"
#include "buzzer/buzzer.h"
#include "drapeau/drapeau.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de mettre a jour l'etat d'une led
 * @param b : l'etat de la led
 */
void writeLED(bool_e b)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de connaitre l'etat du bouton
 * @ret true si bas, false sinon
 */
bool_e readButton(void)
{
	return !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief fonction principale : main
 * @ret int
 */
int main(void)
{
	//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	//Cette ligne doit rester la premi�re �tape de la fonction main().
	HAL_Init();

	//Initialisation de l'UART2 � la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
		//Attention, les pins PA2 et PA3 ne sont pas reli�es jusqu'au connecteur de la Nucleo.
		//Ces broches sont redirig�es vers la sonde de d�bogage, la liaison UART �tant ensuite encapsul�e sur l'USB vers le PC de d�veloppement.
	UART_init(UART2_ID,115200);

	//"Indique que les printf sortent vers le p�riph�rique UART2."
	SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	//Initialisation du port de la led Verte (carte Nucleo)
	BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du bouton bleu (carte Nucleo)
	BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	//On ajoute la fonction process_ms � la liste des fonctions appel�es automatiquement chaque ms par la routine d'interruption du p�riph�rique SYSTICK
	//Systick_add_callback_function(&process_ms);


	//On initialise l'ecran
	ILI9341_Init();
	XPT2046_init();
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);

	//On initialise le buffer, le buzzer, l'ecran, et les servomoteurs
	initBuffer();
	initBuzzer();
	updateServos();
	initScreen();

	//Tache de fond
	while(1)
	{
		//On regarde si des donnees sont recues par bluetooth
		if(UART_data_ready(UART2_ID)) {
			//Si oui, on les ajoute au buffer
			addToBuffer();
			//S'il s'agit des fautes, on met a jour l'etat des servomoteurs
			if (getTypeCourant()==fautes_loc || getTypeCourant()==fautes_visit) {
				updateServos();
			}
			//S'il s'agit du chrono, on met a jour l'etat du chrono et du buzzer
			if (getTypeCourant()==chrono_state) {
				updateBuzzer();
			}
		}
	}
}
