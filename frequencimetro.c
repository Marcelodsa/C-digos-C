#include<p18f4550.h>
#include<delays.h>

#define entrada PORTAbits.RA0
#define u0 LATDbits.LATD0
#define u1 LATDbits.LATD1
#define u2 LATDbits.LATD2
#define u3 LATDbits.LATD3
#define d0 LATDbits.LATD4
#define d1 LATDbits.LATD5
#define d2 LATDbits.LATD6
#define d3 LATDbits.LATD7

void Configurar_PIC(void){
	ADCON1 = 0x0F;
	TRISAbits.TRISA0 = 1;
	TRISD = 0b00000000;
	TRISCbits.TRISC0 = 0;
}

int* RepresentarValor(int valor){
    int palavras[10][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}};
    int saida[4];
	saida[3] = palavras[valor][0];
    saida[2] = palavras[valor][1];
    saida[1] = palavras[valor][2];
    saida[0] = palavras[valor][3];
	return saida;
}

void MostrarFrequencia(int frequencia){
	int* temp;
	temp = RepresentarValor(frequencia % 10);
	u0 = temp[0];
	u1 = temp[1];
	u2 = temp[2];
	u3 = temp[3];
	temp = RepresentarValor(frequencia / 10);
	d0 = temp[0];
	d1 = temp[1];
	d2 = temp[2];
	d3 = temp[3];
}

void Atrasar(void){
	int i;
	for(i = 0; i < 7; i++){}
	Delay1TCY();
}

void main(void){
	long contagem;
	long i;
	Configurar_PIC();
	MostrarFrequencia(0);
	while(1){
		if(entrada == 1){
			contagem = 0;
			while(entrada != 0){
				Atrasar();
				contagem++;
			}
			while(entrada != 1){
				Atrasar();
				contagem++;
			}
			contagem = 10000 / contagem;
			if(contagem > 99){
				LATD = 0b11101110;
			}
			else{
				MostrarFrequencia((int)contagem);
			}
		}
	}
}