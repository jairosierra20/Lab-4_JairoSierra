#include <iostream>
using std::cout;
using std::cin;
using std::endl;
  int menu();
  //Provisionar la matriz de chars para el laberinto
char** provisionarMatriz(int);
//liberar memoria de la matriz
void liberarMatriz(char**&,int);
//imprimir la matriz
void printMatrix(char**,int);

int main()
{
 int opcion = 0;
	do{
	switch(opcion=menu()){
		case 1:
			
	    break;
		case 2:
		cout<<"El programa se cerrara"<<endl;
		    break;
	}
}while(opcion!=2);
	}
int menu(){
	while(true){
  	//cout<<"MENU"<<endl;
  	//mostrar tres opciones
  	//1.- Ejercicio
  	//2.- salir
  	cout<<"MENU"<<endl
  	<<"1.- Ejercicio"<<endl
  	<<"2.- salir"<<endl;
  	//pedir al usuario una opcion
  	cout<<"Ingrese una opcion: ";
  	int opcion =0;
  	//leer la opcion
  	cin>>opcion;
  	//validar la opcion
  	if(opcion>=1 && opcion<= 2){
  		//si es valido retornar
  		return opcion;
	  }
	  else{
	  
  	//else mostrar mensaje de error al usuario
  	cout<<"La opcion elegida no es valida, ingrese un valor entre 1 y 4"<<endl;
  }
  }//end del while
  	return 0;
  }
char** provisionarMatriz(int size){
   char** matrix = NULL;
   matrix = new char*[size];
   for(int i=0;i<size;i++){
      matrix[i]=new char[size];
   }
   return matrix;
}
void liberarMatriz(char**& matrix,int size){
   for(int i=0;i<size;i++){
    if(matrix[i] != NULL){
     delete[] matrix[i];
     matrix[i]=NULL;
    }
  }
void printMatrix(char** matrix,int size){
    for(int i=0;i<size;i++){
     for(int j=0;j<size;j++){
        cout<<matrix[i][j]<<"  ";
     }
     cout<<endl;
  }

}

