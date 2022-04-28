#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
};
typedef struct Tarea tarea;

typedef struct Nodo{
    tarea T;
    struct Nodo *Siguiente;
}Nodo;



Nodo *crearNodo();
Nodo *cargarNodo(int);
void cargarTareas(Nodo **, int);
void mostrTareasYMober(Nodo **listaTareas,Nodo **tareasRealizadas, int cantidadTareas);
void mostrTareas(Nodo *listaTareas,int elemento);
void realizadasYPorRealizar(Nodo **listaTareas,Nodo **tareasRealizadas, int cantidadTareas);
Nodo BuscarTareaPorID(Nodo *listaTareas, int cantidadTareas);
Nodo BuscarTareaPorPalabra(Nodo *listaTareas, int cantidadTareas);
void reasignarNodo(Nodo **,Nodo **, int);
void main(){
    int cantidadTareas = 0;
    Nodo *listaTareas;
    Nodo *tareasRealizadas;

    printf("\nIngrese la cvantidad de tarea a realizar: ");
    scanf("%d",&cantidadTareas);
    
    
    
    listaTareas = crearNodo();
    tareasRealizadas = crearNodo();
    cargarTareas(&listaTareas, cantidadTareas);


    mostrTareasYMober(&listaTareas,&tareasRealizadas, cantidadTareas);

    realizadasYPorRealizar(listaTareas,tareasRealizadas, cantidadTareas);

    BuscarTareaPorID(listaTareas, cantidadTareas);
    BuscarTareaPorPalabra(listaTareas,cantidadTareas);
    

//liveracion de los punteros
    for (int i = 0; i < cantidadTareas; i++)
    {
        
        free(listaTareas[i].T.Descripcion);
        
        
        free(tareasRealizadas[i].T.Descripcion);
        
    }

    free(listaTareas);
    free(tareasRealizadas);
}

Nodo *crearNodo(){
    return NULL;
    
}

void cargarTareas(Nodo **lista, int cantidad){
   
    for (int i = 0; i < cantidad; i++)
    {
       Nodo *NuevoNodo = (Nodo *)malloc(sizeof(Nodo));
       NuevoNodo = cargarNodo(i);
       NuevoNodo->Siguiente = *lista;
       *lista = NuevoNodo;
    }
    
}

void mostrTareasYMober(Nodo **listaTareas,Nodo **tareasRealizadas, int cantidadTareas){
    
    int eleccion = 0;
    
    for (int i = 0; i <  cantidadTareas; i++)
    {
        mostrTareas(*listaTareas,i);
        print("\n Esta tarea fue realisada ? \n 1_SI      2_NO");
        scanf("%d", &eleccion);
        if (eleccion == 1)
        {
            reasignarNodo(listaTareas, tareasRealizadas, i);
        }  
    }
    
}

void mostrTareas(Nodo *listaTareas,int elemento){
    Nodo *lista = listaTareas;
    while (lista != NULL)
    {
        if (lista->T.TareaID == elemento)
        {
            printf("\nTarea %d", elemento+1);
            printf("\nID: %d",listaTareas->T.TareaID);
            printf("\nDescripcion: ");
            puts(listaTareas->T.Descripcion);
            printf("\nDuracion: %d",listaTareas->T.Duracion);
        }
    lista = lista->Siguiente;
    }
    
   
    
        
    
    
}

void realizadasYPorRealizar(Nodo **listaTareas,Nodo **tareasRealizadas, int cantidadTareas){

    for (int i = 0; i < cantidadTareas; i++)
    {
        if(*(listaTareas + i) != NULL){
            mostrTareas(*listaTareas,i);
        }else
        {
            mostrTareas(*tareasRealizadas,i);
        }
        

    }
        
}

Nodo BuscarTareaPorID(Nodo *listaTareas, int cantidadTareas){
    int idBuscado = 0;
    printf("\nIngrese el ID de la tarea buscada: ");
    scanf("%d",&idBuscado);
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (listaTareas->T.TareaID == idBuscado )
        {
            mostrTareas(listaTareas,i);
            
        }
         
    }

    
}

Nodo BuscarTareaPorPalabra(Nodo *listaTareas, int cantidadTareas){
    char palabra[30];
    printf("\nIngrese la palabra a buscar: ");
    fflush(stdin);
    gets(palabra);

    for (int i = 0; i < cantidadTareas; i++)
    {
        if (strstr(listaTareas->T.Descripcion,palabra))
        {
            mostrTareas(listaTareas,i);
            return listaTareas[i];
        }
        
        
    }
    }


void reasignarNodo(Nodo **listaPendiente, Nodo **listaHecha, int i){
    Nodo *aux;
    while (*listaPendiente != NULL)
    {
        
        if ((*listaPendiente)->T.TareaID = i)
        {
            aux = (*listaPendiente);
            (*listaPendiente)->Siguiente = aux->Siguiente;
            (*listaHecha) = aux;
            free(aux);
        }
        
    }
    
}

Nodo *cargarNodo(int i){
    Nodo * NNodo = (Nodo *) malloc (sizeof(Nodo));
    NNodo->Siguiente = NULL;
    
    int aux;
    char *Buff = (char *)malloc(sizeof(char)*100);
    NNodo->T;
    
    NNodo->T.TareaID = i+1;
        
    printf("\nIngrese la descripcion de la tarea %d \n", i +1);
    fflush(stdin);
    gets(Buff);
    NNodo->T.Descripcion = (char *)malloc((strlen(Buff)+1)*sizeof(char));
    strcpy(NNodo->T.Descripcion,Buff);
    free(Buff);
    printf("\n Ingrese la Duracion de la tarea (entre 10 y 100): ");
    scanf("%d",&aux);
    NNodo->T.Duracion = aux;
    return NNodo;
}