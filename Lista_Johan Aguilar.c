#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Johan Ricardo Aguilar Perez
//Estructuras de datos
typedef struct Alumno {
	char *NombreCompleto;
	int CreditosAprobados;
	int SemestreEquivalente;
} Alumno;

typedef Alumno *AlumnoPtr;

typedef struct Nodo {
	Alumno *alumno;
	struct Nodo *enlace;
} Nodo;

typedef Nodo *NodoPtr;

//Declaracion de firmas de las funciones a utilizar
AlumnoPtr crearAlumno(char* NombreCompleto, int CreditosAprobados, int SemestreEquivalente); 
void imprimirAlumno(AlumnoPtr actual);
NodoPtr crearNodo(AlumnoPtr alumno);
void insertarNodoOrdenadoCreditos(NodoPtr *cabecera, NodoPtr nuevo);
void imprimirLista(NodoPtr cabecera);
void imprimirDirecciones(NodoPtr cabecera);

int main(){
	NodoPtr cabecera = NULL;
	AlumnoPtr alumno1, alumno2, alumno3, alumno4, alumno5;
	
	alumno1 = crearAlumno("Johan Aguilar", 55, 7);
	alumno2 = crearAlumno("Josueh Cabrera", 63, 8);
	alumno3 = crearAlumno("Ricardo Cordova", 49, 3);
	alumno4 = crearAlumno("Julio Alcocer", 90, 3);
	alumno5 = crearAlumno("Mauro Kuh", 25, 4);
	
	printf("Se ha creado una estructura Alumno en la direccion %p\n", (void *)alumno1);
	printf("Se ha creado una estructura Alumno en la direccion %p\n", (void *)alumno2);
	printf("Se ha creado una estructura Alumno en la direccion %p\n", (void *)alumno3);
	printf("Se ha creado una estructura Alumno en la direccion %p\n", (void *)alumno4);
	printf("Se ha creado una estructura Alumno en la direccion %p\n\n", (void *)alumno5); 
	
	insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno1));
	insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno2));
	insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno3));
	insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno4));
	insertarNodoOrdenadoCreditos(&cabecera, crearNodo(alumno5)); 
	
	imprimirDirecciones(cabecera);
	
	imprimirLista(cabecera);
	
	return 0;
}

void imprimirDirecciones(NodoPtr cabecera) { //Funcion para imprimir las direcciones de memoria del nodo
	NodoPtr actual = cabecera;
	while (actual != NULL) {
		printf("Se ha creado un nodo en la lista de alumnos en %p\n", (void *)actual);
		actual = actual->enlace;
	}
}

AlumnoPtr crearAlumno(char* NombreCompleto, int CreditosAprobados, int SemestreEquivalente){  //Funcion para crear alumno
	AlumnoPtr nuevo = (Alumno*)malloc(sizeof(Alumno));
		
	nuevo->NombreCompleto = strdup(NombreCompleto);
	nuevo->CreditosAprobados = CreditosAprobados;
	nuevo->SemestreEquivalente = SemestreEquivalente;
		
	return nuevo;
}
		
void imprimirAlumno(AlumnoPtr actual){ //Funcion para imprimir el alumno
	printf("Nombre del Alumno: %s \n", actual->NombreCompleto);
	printf("Creditos Aprobados: %d \n", actual->CreditosAprobados);
	printf("Semestre Equivalente: %d \n\n", actual->SemestreEquivalente);
}
			
NodoPtr crearNodo(AlumnoPtr alumno){  //Funcion para crear un Nodo
	NodoPtr nuevo = (Nodo*)malloc(sizeof(Nodo));
				
	nuevo->alumno = alumno;
	nuevo->enlace = NULL;
				
	return nuevo;
}
				
void insertarNodoOrdenadoCreditos(NodoPtr *cabecera, NodoPtr nuevo) { //Funcion para insertar los nodos
	NodoPtr anterior = NULL, actual = *cabecera;
					
	while (actual != NULL && nuevo->alumno->CreditosAprobados < actual->alumno->CreditosAprobados) {
		anterior = actual;
		actual = actual->enlace;
	}
					
	if (anterior == NULL) { // Si es el primer elemento de la lista
		nuevo->enlace = *cabecera;
		*cabecera = nuevo;
	} else { // Si es en medio o al final
		anterior->enlace = nuevo; // Se actualiza el enlace del anterior
		nuevo->enlace = actual; // El nuevo dato apunta al actual
	}
}

void imprimirLista(NodoPtr cabecera){ //Funcion para imprimir lista
	NodoPtr actual = cabecera;
					
	if (actual == NULL){                           //Revisa si la lista esta vacia
		printf("Lista vacia \n\n");
	}
	else{
		printf("\nImpresion de la lista de alumnos (Creditos Descendentes):\n\n");
		while(actual != NULL){                   //Imprime la lista
			imprimirAlumno(actual->alumno);
			actual = actual->enlace;
		}
		printf("FINAL\n\n");
		}
}

