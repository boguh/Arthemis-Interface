/*
 * datas.c
 *
 *  Created on: 17 janv. 2023
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

/**
 * Biblioth�ques
 */
#include "datas.h"

//------------------------------------------------------------------------------------------------------------------

/*
 * Déclaration des variables
 */

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];
int buffer_index=0;

//Initialisation du constructeur
Match match = {.score_loc=0, .score_visit=0, .fautes_loc=0, .fautes_visit=0, .period=1, .chrono_state=0};

datatype typeCourant = fautes_visit;
int dataCourant = 0;

//------------------------------------------------------------------------------------------------------------------

void setScoreLoc(uint8_t val){
	match.score_loc = val;
}

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

void initBuffer() {
	for (int i = 0; i<BUFFER_SIZE; i++) {
	    buffer[i] = '\0';
	}
	buffer_index = 0;
}

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

void initScreen(){
	//On efface la page puis on l'initialise :
	ILI9341_Fill(ILI9341_COLOR_WHITE);
	ILI9341_Rotate(ILI9341_Orientation_Landscape_2);

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

