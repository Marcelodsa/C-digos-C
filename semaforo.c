#include<p18f4520.h>
#include<stdio.h>
#include<stdlib.h>
#include<delays.h>

#define vermelho LATCbits.LATC0
#define amarelo LATCbits.LATC1
#define verde LATCbits.LATC2
#define vermelho1 LATCbits.LATC3
#define amarelo1 LATCbits.LATC4
#define verde1 LATCbits.LATC5
#define botao PORTDbits.RD0

void confg_pic(){
	ADCON1= 0x0F;
	TRISC= 0b00000000;
	TRISDbits.TRISD0= 0xFF;
}

void semaforoUm(){
	PORTC= 0b00000000;
	vermelho= 1;
	vermelho1= 1;
	Delay10KTCYx(200);
	vermelho1= 0;
	verde1= 1;
	Delay10KTCYx(1000);
	amarelo1= 1;
	verde1= 0;
	Delay10KTCYx(200);
	vermelho1= 1;
	amarelo1= 0;
	Delay10KTCYx(200);
	vermelho= 0;
	verde= 1;
	Delay10KTCYx(1000);
	verde= 0;
	amarelo= 1;
	Delay10KTCYx(200);
}

void semaforoDois(){
	PORTC= 0b00000000;
	vermelho= 1;
	vermelho1= 1;
	Delay10KTCYx(100);
	vermelho1= 0;
	verde1= 1;
	Delay10KTCYx(400);
	amarelo1= 1;
	verde1= 0;
	Delay10KTCYx(100);
	vermelho1= 1;
	amarelo1= 0;
	Delay10KTCYx(200);
	vermelho= 0;
	verde= 1;
	Delay10KTCYx(400);
	verde= 0;
	amarelo= 1;
	Delay10KTCYx(100);
}

void main(){
	confg_pic();
	while(1){
		if(botao==0){
			semaforoUm();
		}
		else{
			semaforoDois();
		}
	}
}