#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#include<time.h>

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};typedef struct Producto Producto;
struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};typedef struct Cliente Cliente;

int TotalProducto(Producto p);

void main(){
    srand(time(NULL));
    float total = 0;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    char *Buff= (char *) malloc(100*sizeof(char));
    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantidadClientes);
    fflush(stdin);

    Cliente *V = (Cliente *) malloc(sizeof(Cliente)*cantidadClientes);

    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("\nCliente %d ",i+1);
        
        V[i].ClienteID = rand()%100;

        printf("\nNombre de cliente: ");
        getchar();
        gets(Buff);
        V[i].NombreCliente= (char *) malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(V[i].NombreCliente,Buff);

        V[i].CantidadProductosAPedir = rand()%11+1;
        V[i].Productos = (Producto *) malloc(sizeof(Producto)*V[i].CantidadProductosAPedir);

        for (int j = 0; j < V[i].CantidadProductosAPedir; j++)
        {
            V[i].Productos[j].Cantidad = rand()%101;
            V[i].Productos[j].PrecioUnitario = rand () % 101 + 10;;
            int productoT = rand()%5;
            Buff = TiposProductos[productoT];
            //asignar con malloc y lonjitud al tipoproducto
            V[i].Productos[j].TipoProducto = (char *) malloc((strlen(Buff)+1)*sizeof(char));
            strcpy(V[i].Productos[j].TipoProducto,Buff);

            V[i].Productos[j].ProductoID = rand()%11+1;
        }
        
        
    }

    for (int i = 0; i < cantidadClientes; i++)
    {
        float total = 0;
        printf("\nCLiente: %d",i+1);
        printf("\nNombre: ");
        puts(V[i].NombreCliente);
        printf("\nID: %d \n Cantidad de productos a pedir: %d ", V[i].ClienteID, V[i].CantidadProductosAPedir);
        for (int j = 0; j < V[i].CantidadProductosAPedir; j++)
        {
            printf("\nTipo: ");
            
            puts(V[i].Productos[j].TipoProducto);
            printf("\n ProductoID: %d \n Cantidad: %d \n Precio: %.2f$",V[i].Productos[j].ProductoID, V[i].Productos[j].Cantidad, V[i].Productos[j].PrecioUnitario);
            total = total + TotalProducto(V[i].Productos[j]);
        }
        printf("\nTotal a pagar: %.2f $",total);
        
       
    }
    
        getchar();



    free(V);
    free(Buff);
}


int TotalProducto(Producto p){
    return(p.Cantidad * p.PrecioUnitario);
}