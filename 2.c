#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
};
typedef struct Nodo{
    tarea T;
    Nodo *Siguiente;
}Nodo;

 typedef struct Tarea tarea;

Nodo *crearNodo();
void cargarTareas(Nodo **, int);
void mostrTareasYMober(tarea **listaTareas,tarea **tareasRealizadas, int cantidadTareas);
void mostrTareas(tarea **listaTareas, int cantidadTareas,int elemento);
void realizadasYPorRealizar(tarea **listaTareas,tarea **tareasRealizadas, int cantidadTareas);
tarea *BuscarTareaPorID(tarea **listaTareas, int cantidadTareas);
tarea *BuscarTareaPorPalabra(tarea **listaTareas, int cantidadTareas);
void main(){
    int cantidadTareas = 0;
    Nodo *listaTareas;
    tarea *tareasRealizadas;

    printf("\nIngrese la cvantidad de tarea a realizar: ");
    scanf("%d",&cantidadTareas);
    
    
    
    listaTareas = crearNodo();
    tareasRealizadas = crearNodo();
    cargarTareas(&listaTareas, cantidadTareas);


    mostrTareasYMober(listaTareas,tareasRealizadas, cantidadTareas);

    realizadasYPorRealizar(listaTareas,tareasRealizadas, cantidadTareas);

    tarea *buscadaID = BuscarTareaPorID(listaTareas, cantidadTareas);
    tarea *buscadaPalabra = BuscarTareaPorPalabra(listaTareas,cantidadTareas);
    

//liveracion de los punteros
    for (int i = 0; i < cantidadTareas; i++)
    {
        ((*(listaTareas + i))->Descripcion);
        free(listaTareas[i]);
        ((*(tareasRealizadas + i))->Descripcion);
        free(tareasRealizadas[i]);
    }

    free(listaTareas);
    free(tareasRealizadas);
}

Nodo *crearNodo(){
    return NULL;
    
}

void cargarTareas(Nodo **lista, int cantidad){
    lista = (tarea **)malloc(sizeof(tarea *)*cantidad);
    for (int i = 0; i < cantidad; i++)
    {
        lista[i]->T.TareaID
    }
    
}

void mostrTareasYMober(tarea **listaTareas,tarea **tareasRealizadas, int cantidadTareas){
    
    int eleccion = 0;
    
    for (int i = 0; i <  cantidadTareas; i++)
    {
        mostrTareas(listaTareas,cantidadTareas, i);
        print("\n Esta tarea fue realisada ? \n 1_SI      2_NO");
        scanf("%d", &eleccion);
        if (eleccion == 1)
        {
            *(tareasRealizadas + i) = *(listaTareas + i);
            *(listaTareas + i) = NULL;
        }else
        {
            *(tareasRealizadas + i) = NULL;
        }
        
        
    }
    
}

void mostrTareas(tarea **listaTareas, int cantidadTareas,int elemento){
    
        printf("\nTarea %d", elemento+1);
        printf("\nID: %d",(*(listaTareas + elemento))->TareaID);
        printf("\nDescripcion: ");
        puts((*(listaTareas + elemento))->Descripcion);
        printf("\nDuracion: %d",(*(listaTareas + elemento))->Duracion);
    
    
}

void realizadasYPorRealizar(tarea **listaTareas,tarea **tareasRealizadas, int cantidadTareas){

    for (int i = 0; i < cantidadTareas; i++)
    {
        if(*(listaTareas + i) != NULL){
            mostrTareas(listaTareas, cantidadTareas,i);
        }else
        {
            mostrTareas(tareasRealizadas, cantidadTareas,i);
        }
        

    }
        
}

tarea *BuscarTareaPorID(tarea **listaTareas, int cantidadTareas){
    int idBuscado = 0;
    printf("\nIngrese el ID de la tarea buscada: ");
    scanf("%d",&idBuscado);
    for (int i = 0; i < cantidadTareas; i++)
    {
        if ((*(listaTareas + i))->TareaID == idBuscado )
        {
            mostrTareas(listaTareas,cantidadTareas,i);
            return(listaTareas[i]);
        }
         
    }

    
}

tarea *BuscarTareaPorPalabra(tarea **listaTareas, int cantidadTareas){
    char palabra[30];
    printf("\nIngrese la palabra a buscar: ");
    fflush(stdin);
    gets(palabra);

    for (int i = 0; i < cantidadTareas; i++)
    {
        if (strstr(listaTareas[i]->Descripcion,palabra))
        {
            mostrTareas(listaTareas,cantidadTareas,i);
            return listaTareas[i];
        }
        
        
    }
    
}