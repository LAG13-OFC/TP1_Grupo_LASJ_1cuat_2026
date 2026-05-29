#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char username[20], correct_username[20] = "vendedor";
    char password[20], correct_password[20] = "12345";

    char  menu1[20], max_cliente[20]="", min_cliente[20]="",  cliente[20];
    float caja_inicial, caja, max_precio=0.0, min_precio=0.0, precioFinalCliente;
    int stock_comb1, stock_comb2, contadorLogin=3, cont1=0, cont2=0, bandera=0, opcion, cantidad;

/******************* login   *************** */
    do{
        printf("> Ingrese su nombre de usuario: ");
        scanf("%s", username);
        printf("> Ingrese su contrase%ca: ", 164); 
        scanf("%s", password);
        if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
            break; // Salir del bucle si el login es exitoso
        }
        else printf("> Nombre de usuario o contrase%ca incorrectos.\n", 164);
        
        contadorLogin--;
    } while (contadorLogin > 0);
/******************* fin login   *************** */

    if (contadorLogin != 0) {//Si el contador no llegó a 0, significa que el login fue exitoso
    
        /****************** Datos Iniciales  *************** */
            system("cls");
            printf("\t\t******** Bienvenido %s ********\n\n", username);
            printf("> Ingrese Dinero en caja inicial: ");
            scanf("%f", &caja_inicial);
            printf("> Ingrese stock de Combo exprimido y tostados: ");
            scanf("%d", &stock_comb1);
            printf("> Ingrese stock de o Combo limonada y tostadas: ");
            scanf("%d", &stock_comb2);
            caja = caja_inicial;
        /******************* fin Datos Iniciales  *************** */


        /******************* Inicio menu principal   *************** */
        do
        {       
                precioFinalCliente=0;
                system("cls"); 
                printf("\t\t******** Sistema de Gesti%cn para Cafeter%ca y Helader%ca ******\n\n", 162, 161, 161);
                printf("[Vender]>   Atenci%cn al cliente\n", 162);
                printf("[Informar]> Cantidad de stock y dinero en caja\n");
                printf("[Cerrar]>   Cerrar caja o jornada\n\n");
                printf("> Ingrese una opci%cn: ", 162);
                scanf("%s", menu1);
                strlwr(menu1); // Convertir a minúsculas para comparación
                if (strcmp(menu1, "vender") == 0) {
                    system("cls");
                    printf("\t\t******** ATENCION AL CLIENTE ******\n");
                    printf("> Ingrese el nombre del cliente: ");
                    scanf("%s", cliente);
                    // Menú de venta para el cliente
                    do {
                        system("cls");
                        if (precioFinalCliente > 0) {
                            printf("> Cliente: %s\n", cliente);
                            printf("> Total acumulado: $%.2f\n\n", precioFinalCliente);// Mostrar el total acumulado solo si es mayor a 0
                        }
                    if(precioFinalCliente == 0) printf(">>>> Cliente: %s\n\n", cliente);
                        printf("[1] Combo limonada y tostados: $4000\n");
                        printf("[2] Combo exprimido y tostadas: $4500\n");
                        printf("[3] Kilo de helado: $9500 \n");
                        printf("[4] Vaso chico de helado: $2500\n");
                        printf("[5] Caf%c con leche y medialunas: $3000\n", 130);
                        printf("[6]> Cerrar venta del cliente: %s \n\n", cliente);
                        printf("\n> Ingrese una opci%cn: ",162);
                        scanf("%d", &opcion);
                        switch (opcion) {
                            case 1:
                                printf("> Ingrese cantidad de Combo limonada y tostados: ");
                                scanf("%d", &cantidad);
                                if(cantidad > 0){
                                    if (cantidad <= stock_comb1) {
                                        stock_comb1 -= cantidad; // Actualizar el stock
                                        precioFinalCliente+=4000 * cantidad;
                                        cont1+=cantidad;
                                        break;
                                    } else {
                                        printf("> No hay stock suficiente. Stock actual: %d\n", stock_comb1);
                                        system("pause");
                                        break; // Salir del switch si no hay suficiente stock
                                    }
                                }
                                break;
                            case 2:
                                printf("> Ingrese cantidad de Combo exprimido y tostadas: ");
                                scanf("%d", &cantidad);
                                if (cantidad <= stock_comb2) {
                                    if(cantidad > 0){
                                    stock_comb2 -= cantidad; // Actualizar el stock
                                    precioFinalCliente+=4500 * cantidad;
                                    cont2+=cantidad;
                                    break;
                                    }
                                } else {
                                    printf("> No hay stock suficiente. Stock actual: %d\n", stock_comb2);
                                    system("pause");
                                    break; // Salir del switch si no hay suficiente stock
                                }
                                break;
                            case 3:
                                printf("> Ingrese cantidad de Kilo de helado: ");
                                scanf("%d", &cantidad);
                                if(cantidad > 0){
                                precioFinalCliente+=9500 * cantidad;
                                }
                                break;
                            case 4:
                                printf("> Ingrese cantidad de Vaso chico de helado: ");
                                scanf("%d", &cantidad);
                                if(cantidad > 0){
                                precioFinalCliente+=2500 * cantidad;
                                }
                                break;
                            case 5:
                                printf("> Ingrese cantidad de Caf%c con leche y medialunas: ", 130);
                                scanf("%d", &cantidad);
                                if(cantidad > 0){
                                precioFinalCliente+=3000 * cantidad;
                                }
                                break;
                            case 6:
                                if(precioFinalCliente == 0){
                                    system("cls");
                                    printf("> Gracias por su visita, %s!\n", cliente);// Agradecer al cliente aunque no haya realizado compras
                                    printf("> NO SE REALIZARON VENTAS\n");
                                    printf("> Regresar al menu principal: ");
                                    system("pause");
                                    break;
                                }
                                system("cls");
                                printf("> Gracias por su compra, %s!\n", cliente);// Agradecer al cliente por su compra
                                printf("> Total a pagar: $%.2f\n", precioFinalCliente);// Mostrar el total a pagar al cerrar la venta
                                caja += precioFinalCliente; // Actualizar la caja con el total de la venta
                            
                                if(bandera == 0){
                                    max_precio=precioFinalCliente;
                                    min_precio=precioFinalCliente;
                                    strcpy(max_cliente, cliente);
                                    strcpy(min_cliente, cliente);
                                    bandera=1;
                                } else {
                                    if (precioFinalCliente > max_precio) {
                                    max_precio = precioFinalCliente;
                                        strcpy(max_cliente, cliente);
                                    }
                                    if (precioFinalCliente < min_precio) {
                                        min_precio = precioFinalCliente;
                                        strcpy(min_cliente, cliente);
                                    }
                                }
                                printf("\n> Regresar al menu principal: ");
                                system("pause");
                                break;
                        }
                    } while (opcion != 6);
                    
                } else if (strcmp(menu1, "informar") == 0) {
                    system("cls");
                    printf("\t\t******** INFORME DE STOCK Y CAJA ******\n\n");
                    printf("> Cantidad dinero en caja: %.2f\n", caja);
                    printf("> Stock de Combo exprimido y tostados: %d\n", stock_comb1);
                    printf("> Stock de Combo limonada y tostadas: %d\n\n", stock_comb2);
                    system("pause");
                } 
        } while (strcmp(menu1, "cerrar") != 0);

        /******************* Fin menu principal   *************** */
        system("cls");
        printf("\t\t******** INFORME FINAL ******\n");
        printf("> Cantidad total vendida de Combo exprimido y tostados: %d\n", cont1);
        printf("> Cantidad total vendida de Combo limonada y tostadas: %d\n", cont2);
        printf("> Total recaudado: %.2f\n", caja-caja_inicial);
        printf("> Cliente que gast%c mas: %s con un total de %.2f\n", 162, max_cliente, max_precio);
        printf("> Cliente que gast%c menos: %s con un total de %.2f\n", 162, min_cliente, min_precio);
        printf("> Stock Restante de Combo exprimido y tostados: %d\n", stock_comb1);
        printf("> Stock Restante de Combo limonada y tostadas: %d\n", stock_comb2);
        printf("> Total en caja: %.2f\n", caja);

    } else {
        printf("\n> Demasiados intentos fallidos. El programa se cerrar%c.\n\n", 160);// Si el contador llegó a 0, significa que el login falló después de varios intentos  
    }
    system("pause");

    return 0;
}//main
