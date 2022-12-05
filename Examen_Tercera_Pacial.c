#include <stdio.h>
#include <stdlib.h>

struct nodo{
        struct nodo* hijo_izq;
        struct nodo* hijo_der;
        int dato;
}

;struct nodo* nuevoNodo(int dato){
        size_t tam_nodo = sizeof(struct nodo);
        struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
        nuevo_nodo->dato = dato;
        nuevo_nodo->hijo_izq = NULL;
        nuevo_nodo->hijo_der = NULL;

        return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
        if(dato>nd->dato) {
                if (nd->hijo_der == NULL) {
                        nd->hijo_der = nuevoNodo(dato);
                 }else {
                        insertarNodo(nd->hijo_der,dato);
                 }
         }else {
                 if (nd->hijo_izq == NULL) {
                         nd->hijo_izq = nuevoNodo(dato);
                 }else
                 {
                         insertarNodo(nd->hijo_izq, dato);
                 }
         }
}


int nivel = 0;

int buscar(struct nodo* nd, int num){
        nivel++;
        if(num == nd->dato){
                printf("El numero %d se encuentra en el nivel %d\n", num, nivel);
        }else if(num < nd->dato && nd->hijo_izq != NULL){
                buscar(nd->hijo_izq, num);
        }else if(num > nd->dato && nd->hijo_der != NULL){
                buscar(nd->hijo_der, num);
        }else{
                printf("El numero no se encontró\n");
        }
        return 0;
}

int main (){
int num = 0;
         struct nodo* raiz = NULL;
         raiz = nuevoNodo(8);
         insertarNodo(raiz,3);
         insertarNodo(raiz,20);
         insertarNodo(raiz,5);
         insertarNodo(raiz,6);
         insertarNodo(raiz,9);
         insertarNodo(raiz,11);
         insertarNodo(raiz,16);

        printf("Ingresa un numero a encontrar: ");
        scanf("%d", &num);
        buscar(raiz, num);

 return 0;
}

