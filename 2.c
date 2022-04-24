#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}; typedef struct Tarea tarea;

void cargadoTareas(tarea **listaTareas, int cantidadTareas);
void mostrTareasYMober(tarea **listaTareas,tarea **tareasRealizadas, int cantidadTareas);
void mostrTareas(tarea **listaTareas, int cantidadTareas,int elemento);
void realizadasYPorRealizar(tarea **listaTareas,tarea **tareasRealizadas, int cantidadTareas);
void main(){
    int cantidadTareas = 0;
    tarea **listaTareas;
    tarea **tareasRealizadas;

    printf("\nIngrese la cvantidad de tarea a realizar: ");
    scanf("%d",&cantidadTareas);
    listaTareas = (tarea **)malloc(sizeof(tarea*)*cantidadTareas);
    tareasRealizadas = (tarea **)malloc(sizeof(tarea*)*cantidadTareas);
    
    cargadoTareas(listaTareas, cantidadTareas);

    mostrTareasYMober(listaTareas,tareasRealizadas, cantidadTareas);

    realizadasYPorRealizar(listaTareas,tareasRealizadas, cantidadTareas);


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


void cargadoTareas(tarea **listaTareas, int cantidadTareas){
   
    
    char *Buff= (char *) malloc(100*sizeof(char));
    int aux;

    
    for (int i = 0; i < cantidadTareas; i++)
    {
        *(listaTareas + i) = (tarea *)malloc(sizeof(tarea));
        (*(listaTareas + i))->TareaID = i+1;
        
        printf("\nIngrese la descripcion de la tarea %d \n", i +1);
        fflush(stdin);
        gets(Buff);
        (*(listaTareas + i))->Descripcion = (char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy((*(listaTareas + i))->Descripcion,Buff);
        
        printf("\n Ingrese la Duracion de la tarea (entre 10 y 100): ");
        scanf("%d",&aux);
        (*(listaTareas + i))->Duracion = aux;
    }
    
    free(Buff);
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
