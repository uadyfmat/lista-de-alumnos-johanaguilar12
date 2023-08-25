#include <stdio.h>
#include <string.h>

//Johan Ricardo Aguilar Perez
//Estructuras de datos
typedef struct {
    char * NombreCompleto;
    int CreditosAprobados;
    int SemestreEquivalente;
} Alumno;

typedef Alumno *AlumnoPtr;

typedef struct {
    Alumno *alumno;
    struct Nodo *enlace;
} Nodo;

typedef Nodo *NodoPtr;

//Declaracion de firmas de las funciones a utilizar
AlumnoPtr crearAlumno(char*, int, int); 
void imprimirAlumno(AlumnoPtr actual);
NodoPtr crearNodo(AlumnoPtr alumno);
void insertarNodoOrdenadoCreditos(NodoPtr *cabecera, NodoPtr nuevo);
void imprimirLista(NodoPtr *cabecera);

int main(){
    NodoPtr cabecera = NULL;

    Alumno alumno1 = {"Johan Aguilar Perez", 5, 7};
    Alumno alumno2 = {"Josueh Cabrera Alcocer", 6, 8};
    Alumno alumno3 = {"Ricardo Cordova Martinez", 9, 3};
    Alumno alumno4 = {"Julio Alcocer Herrera", 8, 4};
    Alumno alumno5 = {"Mauro Ku Esquivel", 5, 4};

    


    return 0;
}

AlumnoPtr crearAlumno(char*, int, int){  //Funcion para crear alumno
    AlumnoPtr nuevo = (Alumno*)malloc(sizeof(Alumno));

	nuevo->NombreCompleto = strdup(NombreCompleto);
    nuevo->CreditosAprobados = CreditosAprobados;
    nuevo->SemestreEquivalente = SemestreEquivalente;
	nuevo->enlace = NULL;
	
	return nuevo;
}

void imprimirAlumno(AlumnoPtr actual){ //Funcion para imprimir el alumno
    printf("ALUMNO\n");
    printf("Nombre: %s \n", actual->NombreCompleto);
    printf("Creditos Aprobados: %d \n", actual->CreditosAprobados);
    printf("Semestre Equivalente: %d \n\n", actual->SemestreEquivalente);
}

NodoPtr crearNodo(AlumnoPtr alumno){  //Funcion para crear un Nodo
    NodoPtr nuevo = (Nodo*)malloc(sizeof(Nodo));
	
    nuevo->alumno = alumno;
	nuevo->enlace = NULL;

    return nuevo;
}

void insertarNodoOrdenadoCreditos(NodoPtr *cabecera, NodoPtr nuevo){ //Funcion para insertar de manera ordenada
    NodoPtr anterior = NULL, actual = *cabecera;

    while (actual != NULL && nuevo->CreditosAprobados < actual->CreditosAprobados){  //Se busca la posicion adecuada
        anterior = actual;
		actual = actual->enlace;
    }

    if(anterior == NULL){ //Si es el primer elemento de la lista
		nuevo->enlace = *cabecera;
		*cabecera = nuevo;
	}
	else{ //Si es en medio o al final
		anterior->enlace = nuevo;  //Se actualiza el enlace del anterior
		nuevo->enlace = actual; //El nuevo dato apunta al actual
	};

}

void imprimirLista(NodoPtr *cabecera){ //Funcion para imprimir lista
    NodoPtr anterior = NULL, actual = *cabecera;

    if (actual == NULL){                           //Revisa si la lista esta vacia
		printf("Lista vacia \n\n");
	}
	else{
		printf("Contenido de la lista:\n");
		while(actual != NULL){                   //Imprime la lista
			imprimirAlumno(actual->alumno);
			actual = actual->enlace;  
		}
		printf("NULL\n\n");
    }
}
