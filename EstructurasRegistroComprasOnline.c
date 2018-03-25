//Simulador de registro en una web de compras online
//Tras el registro, para poder entrar a su usuario se necesita contraseña
//Se pueden registrar todos los usuarios que se quiera

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define NUMUSUARIOS 100

struct TUsuario { 
	char nombre[50];
	char contrasena[50];
	char cuentabancaria[25];
};
void main() {
	struct TUsuario usu[NUMUSUARIOS],aux[NUMUSUARIOS];
	int opcion, comp1,j=0,k,auxx=0;
	printf("Bienvenido a nuestra pagina de ventas online.\n");
	Sleep(2000);
	//Bucle que se repite hasta que se quiera salir del programa
	do  {
			
			system("cls");
			printf("Elija entre estas opciones e introduzca su decision\n");
			printf("1.	Acceder a su cuenta\n2.	Registrarse\n3.	Salir del programa\n"); //menu
			scanf_s("%d", &opcion);

			switch (opcion) {
			case 1: //Acceder a una cuenta
				printf("Introduzca su nombre de usuario\n");
				scanf_s("%s", &aux[j].nombre, 50); 
				
					for (k = 0; k < j; k++) {
						comp1 = strcmp(aux[j].nombre, usu[k].nombre); //compara con todos los usuarios guardados
						if (comp1 == 0) {
							auxx=k;//guarda en auxx el numero de usuario registrado
								break;
						}
					}//Compara entre todos los usuarios
					
					if (comp1 == 0) {
						printf("Bienvenido %s\n", usu[auxx].nombre);
						do {
							printf("Introduzca su contrasena para entrar\n");
							scanf_s("%s", &aux[auxx].contrasena, 50);
							comp1 = strcmp(aux[auxx].contrasena, usu[auxx].contrasena); //Compara  si es la contraseña

							if (comp1 == 0) {
								printf("Contrasena correcta\n");
								Sleep(2000);
							}
							else {
								printf("Contrasena incorrecta vuelva a intentarlo\n");
							}
						} while (comp1 != 0); //Hasta que la contraseña sea correcta se repite
					}
					else {
						printf("Lo sentimos, no se encuentra entre nuestros usuarios, registrese como uno nuevo.\n");
						Sleep(2000);
					}
		
				getchar();
				break;
			case 2: //Registro
				printf("Para registrarse necesitamos varios datos sobre usted\n");
				do {
					printf("Introduzca su nombre de usuario\n");
					scanf_s("%s", &aux[j].nombre, 50);
					for (k = 0; k < j; k++) {
						comp1 = strcmp(aux[j].nombre, usu[k].nombre); //Compara entre todos los usuarios
						if (comp1 == 0) {
							break;
						}
					}

					if (comp1 != 0) {
						strcpy_s(usu[j].nombre, 50, aux[j].nombre); //guarda el nombre nuevo en usuarios
						printf("Introduzca su contrasena\n");
						scanf_s("%s", &usu[j].contrasena, 50);
						printf("Introduzca su numero de cuenta bancaria\n");
						scanf_s("%s", &usu[j].cuentabancaria, 25);
						printf("Usted ha sido registrado como %s con contrasena %s y numero de cuenta %s\n", usu[j].nombre, usu[j].contrasena, usu[j].cuentabancaria);
						Sleep(2000);

					}
					else {
						printf("Ya existe un usuario con ese nombre, intente con otro\n");
					}
				} while (comp1 == 0);
				Sleep(2000);

				getchar();
				break;
			case 3: printf("Hasta la proxima!\n");
				Sleep(2000);
				getchar();
				break;
				
			default: printf("Elija entre alguna de las 3 opciones\n");
				
				Sleep(2000);
				getchar();
				break;
			}
			j = j++;
	} while (j < NUMUSUARIOS &&  opcion !=3); //Se repite hasta que se acabe le numero de usuarios permitidos 
	// o se decida salir del programa
		
	
	system("pause");
}
