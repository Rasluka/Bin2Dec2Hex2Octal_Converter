#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

/*PROTOTIPO DE FUNCIONES*/
int menu();
void random_a_dec(int op);
void dec_a_binario();

void dec_a_hexa();
void dec_a_octal();

int * transferir_datos(int tam, int op, char dat[]);
int lenght_dec(int dec);
int lenght_bin(char bin[]);

int main(){//INICIO DEL MAIN

	int opc;

	do{
		opc=menu();

		switch(opc){
			case 1:{random_a_dec(opc);break;}
			case 2:{dec_a_binario();break;}
			case 3:{random_a_dec(opc);break;}
			case 4:{dec_a_octal();break;}
			case 5:{random_a_dec(opc);break;}
			case 6:{dec_a_hexa();break;}
			default:{printf("Cerrando App..."); getch(); break;}
   		}
	}
	while(opc!=7);

	return 0;
}//FINDEL MAIN

/******************************************************************/
/*                   DEFINICION DE FUNCIONES                      */
/******************************************************************/

/************************** FUNCION MENU **************************/
int menu(){ //Inicio funcion menu

	int op;

	do{

		fflush(stdin);
		system("cls");
		system("color 0A");
		puts("----------------------------------------------");
		puts("-------               MENU             -------");
		puts("----------------------------------------------");
		puts("--- 1 - Convertir de binario a decimal     ---");
		puts("--- 2 - Convertir de decimal a binario     ---");
		puts("--- 3 - Convertir de octal a decimal       ---");
		puts("--- 4 - Convertir de decimal a octal       ---");
		puts("--- 5 - Convertir de hexadec a decimal     ---");
		puts("--- 6 - Convertir de decimal a hexadec     ---");
		puts("--- 7 - Salir                              ---");
		printf("---> Su opcion: ");
		scanf("%d", &op);

		if(op>7 || op<1){
			printf("Opcion no valida..."); getch();
		}

	}
	while(op>7 || op<1);

	return op;
}//Fin funcion menu

/************** FUNCION CONVERTIR DE BINARIO A DECIMAL ******************/
void random_a_dec(int op){//Inicio funcion que convertir de binario a decimal
	char dato[20];
	int base, opc, i, tam, decimal=0, pot;
	int *arreglo;

	system("cls");
	puts("----------------------------------------------");
	if(op==1){
		puts("---    Convertir de binario a decimal      ---");
		puts("----------------------------------------------");
		printf("Ingrese el dato en binario: "); //<- Pedimos el dato
		base=2;
	}
	else if (op==3){
		puts("---      Convertir de octal a decimal      ---");
		puts("----------------------------------------------");
		printf("Ingrese el dato en octal: "); //<- Pedimos el dato
		base=8;
	}
	else if(op==5){
		puts("---      Convertir de hexad a decimal      ---");
		puts("----------------------------------------------");
		printf("Ingrese el dato en hexadec: "); //<- Pedimos el dato
		base=16;
	}


	scanf("%s", &dato);

	tam=lenght_bin(dato);

    arreglo=transferir_datos(tam, op, dato);

	pot=tam-1;//<-Le asignamos un valor a la potencia segun el tamaño de la cadena (va de tam hasta 0. tam...0)

	puts("----------------------------------------------");
	puts("***               Operacion                ***");
	puts("----------------------------------------------");
	for(i=0; i<tam; i++){ //<-Este ciclo realiza y muestra la operacion de potenciar y sumar cada elemento del arreglo
		printf("%d*%d^%d",arreglo[i], base, pot);
		if(i<tam-1)
			printf(" + ");
		if(i==4 || i==8)
			puts(" ");
		decimal=decimal+(arreglo[i]*(pow(base,pot)));
		pot--;
	}
	printf(" = %d", decimal);
	puts("\n----------------------------------------------");

	printf("Esto en decimal es: %d x10\n", decimal);
	puts("----------------------------------------------");
	getch();
	free(arreglo);

}//Fin funcion binario_a_dec

/************** FUNCION CONVERTIR DE DECIMAL A BINARIO  ******************/
void dec_a_binario(){
	int decimal=0,j,i=0, tam;
	char *binario;

	puts("----------------------------------------------");
	puts("---    Convertir de binario a decimal      ---");
	puts("----------------------------------------------");
	printf("Ingrese el dato en decimal: ");
	scanf("%d", &decimal);

	tam=lenght_dec(decimal);

	binario=(char*) malloc(sizeof(char)*tam);

	while((decimal/2)>=1){
		if(decimal%2==1){
			decimal=(decimal-1)/2;
			binario[i]='1';
		}
		else if(decimal%2==0){
			decimal=decimal/2;
			binario[i]='0';
		}
		i++;
	};
	
	

	if(decimal/2<1){
		if(decimal%2==1){
			binario[i]='1';
		}
		else if(decimal%2==0){
			binario[i]='0';
		}
	}

	tam++;
	puts("----------------------------------------------");
	printf("Esto en binario es: ");
	for(j=tam; j>=0; j--)
	{
		printf("%c", binario[j]);
	}
	puts("\n----------------------------------------------");
	getch();
	free(binario);
}//Fin de dec_a_binario

/************** FUNCION CONVERTIR DE DECIMAL A OCTAL  ******************/
void dec_a_octal(){
	int decimal=0,j,i=0, tam=0, residuo, ndec;
	char *octal, chr;

	system("cls");
	puts("----------------------------------------------");
	puts("---      Convertir de decimal a octal      ---");
	puts("----------------------------------------------");
	printf("Ingrese el dato en decimal: ");
	scanf("%d", &decimal);

	ndec=decimal;

	while(ndec/8>=1){
		residuo=ndec%8;
		ndec=ndec-residuo;
		ndec=ndec/8;
		tam++;
	}

	tam++;

	octal=(char*) malloc(sizeof(char)*tam);

	while(decimal/8>=1){
		residuo=decimal%8;
		decimal=decimal-residuo;
		decimal=decimal/8;

		chr=residuo;
		octal[i]=chr+'0';
		i++;

	}
	chr=decimal%8;
	octal[i]=chr+'0';

	puts("----------------------------------------------");
	printf("Esto en octal es: ");
	for(j=tam-1; j>=0; j--)
	{
		printf("%c", octal[j]);
	}
	puts("\n----------------------------------------------");
	getch();
	free(octal);
}//Fin de dec_a_binario

void dec_a_hexa(){
	int decimal=0,j,i=0, tam=0, residuo, ndec, *arr;
	char *hexa, chr;

	system("cls");
	puts("----------------------------------------------");
	puts("---      Convertir de decimal a hexa       ---");
	puts("----------------------------------------------");
	printf("Ingrese el dato en decimal: ");
	scanf("%d", &decimal);

	ndec=decimal;

	while(ndec/16>=1){
		residuo=ndec%16;
		ndec=ndec-residuo;
		ndec=ndec/16;
		tam++;
	}

	tam++;

	arr=(int*) malloc(sizeof(int)*tam);
	hexa=(char*) malloc(sizeof(char)*tam);

	while(decimal/16>=1){
		residuo=decimal%16;
		decimal=decimal-residuo;
		decimal=decimal/16;

		arr[i]=residuo;
		i++;
	}

	arr[i]=decimal%16;

	for(i=0; i<tam;i++){

		if(arr[i]==0)
			hexa[i]='0';
		else if(arr[i]==1)
			hexa[i]='1';
		else if(arr[i]==2)
			hexa[i]='2';
		else if(arr[i]==3)
			hexa[i]='3';
		else if(arr[i]==4)
			hexa[i]='4';
		else if(arr[i]==5)
			hexa[i]='5';
		else if(arr[i]==6)
			hexa[i]='6';
		else if(arr[i]==7)
			hexa[i]='7';
		else if(arr[i]==8)
			hexa[i]='8';
		else if(arr[i]==9)
			hexa[i]='9';
		else if(arr[i]==10)
			hexa[i]='A';
		else if(arr[i]==11)
			hexa[i]='B';
		else if(arr[i]==12)
			hexa[i]='C';
		else if(arr[i]==13)
			hexa[i]='D';
		else if(arr[i]==14)
			hexa[i]='E';
		else if(arr[i]==15)
			hexa[i]='F';
	}

	puts("----------------------------------------------");
	printf("Esto en hexa es: ");
	for(j=tam; j>=0; j--)
	{
		printf("%c", hexa[j]);
	}
	puts("\n----------------------------------------------");
	getch();

}


/************** Funciones Auxiliares  ******************/

//Funcion que determina el tamaño de un decimal
int lenght_dec(int dec){
	int tam=0;

	while(dec/2>1){
		if(dec%2==1){
			dec=(dec-1)/2;
		}
		else if(dec%2==0){
			dec=dec/2;
		}
		tam++;
	}



	return tam;
}//Fin funcion lenght_dec

//Funcion que determina el tamaño de una cadena
int lenght_bin(char bin[]){
	int i=0, tam=0;

	while(bin[i]!='\0') //<-Determinamos el tamaño de la cadena
	{
		tam++;
		i++;
	}

	return tam;
}//Fin funcion lenght_bin


int * transferir_datos(int tam, int op, char dat[]){

	int i;
	int *arr;

	arr=(int *) malloc(sizeof(int)*tam);


	if(op==1){
		for(i=0; i<tam; i++){ //<-Este ciclo examina cada elemento de la cadena y lo transfiere al arreglo en forma de entero
			if(dat[i]=='1'){
				arr[i]=1;
			}
			else if(dat[i]=='0'){
				arr[i]=0;
			}
		}
	}
	else if(op==3){
		for(i=0; i<tam; i++){ //<-Este ciclo examina cada elemento de la cadena y lo transfiere al arreglo en forma de entero
			if(dat[i]=='0')
				arr[i]=0;
			else if(dat[i]=='1')
				arr[i]=1;
			else if(dat[i]=='2')
				arr[i]=2;
			else if(dat[i]=='3')
				arr[i]=3;
			else if(dat[i]=='4')
				arr[i]=4;
			else if(dat[i]=='5')
				arr[i]=5;
			else if(dat[i]=='6')
				arr[i]=6;
			else if(dat[i]=='7')
				arr[i]=7;
		}
	}
	else if(op==5){
		for(i=0; i<tam; i++){
			if(dat[i]=='0')
				arr[i]=0;
			else if(dat[i]=='1')
				arr[i]=1;
			else if(dat[i]=='2')
				arr[i]=2;
			else if(dat[i]=='3')
				arr[i]=3;
			else if(dat[i]=='4')
				arr[i]=4;
			else if(dat[i]=='5')
				arr[i]=5;
			else if(dat[i]=='6')
				arr[i]=6;
			else if(dat[i]=='7')
				arr[i]=7;
			else if(dat[i]=='8')
				arr[i]=8;
			else if(dat[i]=='9')
				arr[i]=9;
			else if(dat[i]=='A' || dat[i]=='a' )
				arr[i]=10;
			else if(dat[i]=='B' || dat[i]=='b' )
				arr[i]=11;
			else if(dat[i]=='C' || dat[i]=='c' )
				arr[i]=12;
			else if(dat[i]=='D' || dat[i]=='d' )
				arr[i]=13;
			else if(dat[i]=='E' || dat[i]=='e' )
				arr[i]=14;
			else if(dat[i]=='F' || dat[i]=='f' )
				arr[i]=15;
		}
	}

	return arr;
}
