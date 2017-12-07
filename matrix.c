#include<stdio.h>
#include<stdlib.h>
#include<p18f4520.h>
#include<delays.h>

void confg_pic(){
	TRISC= 0b00000000;
	PORTC= 0b00000000;
	TRISD= 0b00000000;
	PORTD= 0b00000000;
}

void desenhar(){
	PORTC= 0b11111111;
	Delay10KTCYx(50);
	PORTD= 0b00000000;
	Delay10KTCYx(50);
	PORTC= 0b10000001;
	Delay10KTCYx(50);
	PORTD= 0b01000000;
	Delay10KTCYx(50);
	PORTC= 0b10000001;
	Delay10KTCYx(50);
	PORTD= 0b00100000;
	Delay10KTCYx(50);
	PORTC= 0b10011001;
	Delay10KTCYx(50);
	PORTD= 0b00010000;
	Delay10KTCYx(50);
	PORTC= 0b10011001;
	Delay10KTCYx(50);
	PORTD= 0b00001000;
	Delay10KTCYx(50);
	PORTC= 0b10011001;
	Delay10KTCYx(50);
	PORTD= 0b00000100;
	Delay10KTCYx(50);
}

void main(){
	confg_pic();
	while(1){
		desenhar();
	}
}