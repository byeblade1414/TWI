#include "TWI.h"
//#include <avr/io.h>


void enableTWI()
{
	TWBR = 0xff;
	TWCR |= (1 << TWEN);
}

void startTWIconnection()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	while(!(TWCR & (1 << TWINT))); // wait until start condition has sent & ack received.
	//TWCR &= ~(1 << TWSTA); // clear start bit.
}

void sendTWIdata(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT))); // wait until TWINT flag is set so that byte has been transmitted
}

void TWISend(unsigned char adress,unsigned char data)
{
	startTWIconnection();
	sendTWIdata(adress);
	sendTWIdata(data);
	haltTWI();
}

void haltTWI()
{
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

unsigned char readTWI(unsigned char adress)
{
	TWCR = (1 << TWEN) | (1 << TWSTA) | (1 << TWINT);
	while(!(TWCR & (1 << TWINT)));
	
	TWDR = adress;
	TWCR = (1 << TWEN) | (1 << TWINT);
	while(!(TWCR & (1 << TWINT)));
	
	TWCR = (1 << TWEN) | (1 << TWSTA) | (1 << TWINT);
	while(!(TWCR & (1 << TWINT)));
	
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	
	return TWDR;
}
