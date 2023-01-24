/*
 * datas.c
 *
 *  Created on: 17 janv. 2023
 *      Author: bourdahu & bourhima
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Bibliotheques
 */
#include "datas.h"

//------------------------------------------------------------------------------------------------------------------

/*
 * @def BUFFER_SIZE : la taille du buffer qui recoit les donnees bluetooth
 */
#define BUFFER_SIZE 10
char buffer[BUFFER_SIZE];
int buffer_index=0;

/**
 * @brief On initialise le constructeur d'un match, on y stockera les valeurs des differentse donnees
 */
Match match = {.score_loc=0, .score_visit=0, .fautes_loc=0, .fautes_visit=0, .period=1, .chrono_state=0};

/**
 * @brief le type de donnee courant et sa valeur (recus par bluetooth)
 */
datatype typeCourant = fautes_visit;
int dataCourant = 0;

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture des fautes des locaux
 * @return fautes_loc
 */
uint8_t getFautes_loc(){
	return match.fautes_loc;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture des fautes des visiteurs
 * @return fautes_visit
 */
uint8_t getFautes_visit(){
	return match.fautes_visit;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture de l'etat du chrono
 * @return chrono_state
 */
uint8_t getChrono_state(){
	return match.chrono_state;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en ecriture des fautes des locaux
 * @param val
 */
void setScoreLoc(uint8_t val){
	match.score_loc = val;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Accesseur en lecture du type de donnee courant
 * @return typeCourant
 */
datatype getTypeCourant(){
	return typeCourant;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'ajouter les donnees recues par bluetooth au buffer
 */
void addToBuffer() {
	char c = UART_getc(UART2_ID);
	if (c!='\n') {
		buffer[buffer_index] = c;
		buffer_index++;
	} else {
		buffer[buffer_index] = c;
		buffer_index=0;
		updateData();
		updateScreen();
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'initialiser le buffer avant une nouvelle acquisition
 */
void initBuffer() {
	for (int i = 0; i<BUFFER_SIZE; i++) {
	    buffer[i] = '\0';
	}
	buffer_index = 0;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de recuperer le type de donnee a modifier
 */
void setDatatype(){
	datatype typeTemp;
	char a = buffer[0];
	char b = buffer[1];
	switch(a){
		case 's':
			typeTemp = (b=='l') ? score_loc : score_visit;
			break;
		case 'f':
			typeTemp = (b=='l') ? fautes_loc : fautes_visit;
			break;
		case 'p':
			typeTemp = period;
			break;
		case 'c':
			typeTemp = chrono_state;
			break;
		default:
			break;
	}
	typeCourant = typeTemp;
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet de recuperer la nouvelle valeur de la donnee a modifier
 */
void setData(){
	char temp[3];
	for (int i=0 ; i<3 ; i++) {
		temp[i] = '0';
	}
	int i = 1;
	int j = 0;
	char c = buffer[BUFFER_SIZE-i];
	while(c != '='){
		if ((c!='\n') && (c!='\0')) {
			temp[2-(j++)] = c;
		}
		c = buffer[BUFFER_SIZE - (i++)];
	}
	dataCourant = atoi(temp);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'actualiser les donnees du tableau d'affichage
 */
void updateData(){
	setData();
	setDatatype();
	switch(typeCourant){
		case score_loc:
			match.score_loc = dataCourant;
			break;
		case score_visit:
			match.score_visit = dataCourant;
			break;
		case fautes_loc:
			match.fautes_loc = dataCourant;
			break;
		case fautes_visit:
			match.fautes_visit = dataCourant;
			break;
		case period:
			match.period = dataCourant;
			break;
		case chrono_state:
			match.chrono_state = dataCourant;
			break;
		default:
			break;
	}
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'initialiser l'ecran
 */
void initScreen(){
	//On efface la page puis on l'initialise :
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_Rotate(ILI9341_Orientation_Landscape_1);

	ihm_DrawFilledRoundedRectangle(40,0,280,60,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(10,70,150,140,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(170,70,310,140,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(10,160,150,220,20,ILI9341_COLOR_NOIR_ihm);
	ihm_DrawFilledRoundedRectangle(170,160,310,220,20,ILI9341_COLOR_NOIR_ihm);

	ILI9341_Puts(50,141, "Locaux", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_GREEN);
	ILI9341_Puts(195,141, "Visiteur", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_BLUE);

	ILI9341_Puts(50,115, "Score", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(50,200, "fautes", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(210,115, "Score", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	ILI9341_Puts(210,200, "fautes", &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
}

//------------------------------------------------------------------------------------------------------------------

/**
 * @brief Permet d'actualiser l'ecran
 */
void updateScreen(){
	char temp[3];
	sprintf(temp, "%d", match.score_loc);
	ILI9341_Puts(75,95, temp , &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	sprintf(temp, "%d", match.score_visit);
	ILI9341_Puts(240,95, temp, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	sprintf(temp, "%d", match.fautes_loc);
	ILI9341_Puts(75,180, temp, &Font_11x18, (match.fautes_loc>4)?ILI9341_COLOR_RED:ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	sprintf(temp, "%d", match.fautes_visit);
	ILI9341_Puts(240,180, temp, &Font_11x18, (match.fautes_visit>4)?ILI9341_COLOR_RED:ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);

	/*
	sprintf(temp, "%d", dataCourant);
	ILI9341_Puts(75,20, temp, &Font_11x18, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	*/
}

//------------------------------------------------------------------------------------------------------------------
