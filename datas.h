/*
 * datas.h
 *
 *  Created on: 17 janv. 2023
 *      Author: bourdahu
 */

//------------------------------------------------------------------------------------------------------------------

//Permet de compiler une seule fois
#pragma once

//------------------------------------------------------------------------------------------------------------------

//import des bibiloth�ques :
#include "stm32f1_ili9341.h"
#include "stm32f1_xpt2046.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pour utiliser sleep
#include "systick.h"
#include "stm32f1_uart.h"
#include "ihm/ihm.h"

//------------------------------------------------------------------------------------------------------------------

/**
 * @struct Structure des données d'un match
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

typedef enum {
	score_loc,
	score_visit,
	fautes_loc,
	fautes_visit,
	period,
	chrono_state
}datatype;

//------------------------------------------------------------------------------------------------------------------
void setScoreLoc(uint8_t val);

void addToBuffer(void);

void initBuffer(void);

void setDatatype(void);

void setData(void);

void updateData(void);

void initScreen(void);

void updateScreen(void);
