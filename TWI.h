#ifndef _TWI_H
#define _TWI_H

#ifndef _AVR_ATMEGA32A_H_INCLUDED
#include <avr/io.h>
#endif

#ifndef stdin
#include <stdlib.h>
#endif

#ifndef _UTIL_DELAY_H_
#define F_CPU 16000000UL
#include <util/delay.h>
#endif

#ifndef SLA_W
#define SLA_W 0x4e
#define SLA_R 0x4f
#endif

//migrate to lcd.h later
unsigned char cursor_pos;

void enableTWI();
void startTWIconnection();
void sendTWIdata(unsigned char data);
void TWISend(unsigned char adress,unsigned char data);
unsigned char readTWI(unsigned char adress);
unsigned char readTWI(unsigned char adress);
void haltTWI();


#endif
