#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Alumno{
    int id;
    char nombre[64];
    Alumno *next;
};

void lanzarMenu();
Alumno* crearAlumno(char nombre[]);
Alumno* obtenerUltimo(Alumno* raiz);
void imprimirLista(Alumno* raiz);
int obtenerhash();

int id = 1;

int main(){
    Alumno* alumnos[10];
    Alumno *actual;
    Alumno *ultimo = NULL;
    char nombre[64];
    int opcion, indice;

    for(int i = 0; i < 10; i++){
        alumnos[i] = NULL;
    }

    lanzarMenu();
    cin>>opcion;
    while(opcion >= 1 && opcion < 3){
        switch(opcion){
            case 1:
            cout<<"Introduce el nombre del alumno: "<<endl;
            cin>>nombre;
            indice = obtenerhash();
            actual = crearAlumno(nombre);
            
            if(alumnos[indice] == NULL){
                alumnos[indice] = actual;
            }else{
                ultimo = obtenerUltimo(alumnos[indice]);
                ultimo->next = actual;
            }
            ultimo = actual;
            id++;
            break;
            case 2:
            cout<<"\t\tImpresion de Hash Table"<<endl;
            for(int i = 0; i < 10; i++){
                cout<<"Id de arreglo: "<<to_string(i)<<endl;
                imprimirLista(alumnos[i]);
            }
            break;
        }

        lanzarMenu();
        cin>>opcion;
    }


    return 0;
}

void lanzarMenu(){
    cout<<"\t\t\tHash tables mediante encadenamiento"<<endl;
    cout<<"1.-Agregar alumno"<<endl;
    cout<<"2.-Imprimir hash table"<<endl;
    cout<<"3.-Salir"<<endl;
    cout<<"Introduce una opcion:"<<endl;
}

Alumno* obtenerUltimo(Alumno* raiz){
    Alumno* temp = raiz;
    while(temp->next != NULL){
        temp = temp->next;
    }

    return temp;
}

Alumno* crearAlumno(char nombre[]){
    Alumno *temp = (Alumno*) malloc(sizeof(Alumno));
    temp->id = id;
    strcpy(temp->nombre, nombre);
    temp->next = NULL;

    return temp;
}

void imprimirLista(Alumno* raiz){
    while(raiz != NULL){
        cout<<"Id: "<<to_string(raiz->id)<<endl;
        cout<<"Nombre: "<<raiz->nombre<<endl;
        raiz = raiz->next;
    }
}

int obtenerhash(){
    return id%10;
}