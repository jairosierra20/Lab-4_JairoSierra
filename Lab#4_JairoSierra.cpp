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
//Crear Matriz
char** crear(char**, int);
//Metodo
char** metodo(char**, int);
//Contar puntos
void contar(char**, int);
int main()
{
 int opcion = 0;
	do{
		int size=0;
		 char** labMatrix=NULL;
	switch(opcion=menu()){
		case 1:
			cout<<"Ingrese el tamaño de la matriz: "<<endl;
			cin >> size;
			if(size<=0){
			  cout<<"No se permiten negativos"<<endl;
			  cout<<"Ingrese el tamaño de la matriz: "<<endl;
                        cin >> size;
			}
			//inicializar matriz n x n
                        labMatrix=provisionarMatriz(size);
			//Crea la matriz con la primera fila llena con lo que ingresa el usuario
			crear(labMatrix, size);
			//Llena la matriz con las demas validaciones
			metodo(labMatrix,size);
			//Cuenta los azulejos seguros de la matriz
			contar(labMatrix,size);
			//Imprime la matriz final
			printMatrix(labMatrix,size);
			
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
}
void printMatrix(char** matrix,int size){
    for(int i=0;i<size;i++){
     for(int j=0;j<size;j++){
        cout<<matrix[i][j]<<"  ";
     }
     cout<<endl;
  }

}
char** crear(char** matrix, int size){
	char letra;
	//Llena la primera fila de la matriz con lo que ingresa el usuario
    for(int i=0;i<size;i++){
       cout<<"Ingrese el caracter"<<endl;
       cin >> letra;
       matrix[0][i] = letra;
    }
    return matrix;
}
char** metodo(char** matrix, int size){
   for(int i=1;i<size;i++){
      for(int j=0;j<size;j++){
         if(j==0){
           //Llena la esquina de la izquierda		 
	   if((matrix[i-1][j] == '^' && matrix[i-1][j+1] == '^') || (matrix[i-1][j] == '.' && matrix[i-1][j+1] == '^')){
	     matrix[i][j] = '^';
	   }
	   else{
	      matrix[i][j]='.';
	   }
	 }
	 //Llena la matriz para que no se corran los espacios
	if(j!= 0 && j != size-1)
		matrix[i][j] = '*';
         //LLena la esquina de la derecha
	 if(j==size-1){
      if((matrix[i-1][size-2] == '^' && matrix[i-1][size-1] == '^') ||( matrix[i-1][size-2] == '^' && matrix[i-1][size-1] == '.')){
            matrix[i][j] = '^';
      } 
      else{
         matrix[i][j]='.';
      }
          }
     //Metodo para la validacion del medio
     if(j!=0 && j!= size-1){
       if((matrix[i-1][j-1] == '^' && matrix[i-1][j] == '^' && matrix[i-1][j+1] == '.') || (matrix[i-1][j-1] == '.' && matrix[i-1][j] == '^' && matrix[i-1][j+1] == '^') || (matrix[i-1][j-1] == '^' && matrix[i-1][j] == '.' && matrix[i-1][j+1] == '.') || (matrix[i-1][j-1] == '.' && matrix[i-1][j] == '.' && matrix[i-1][j+1] == '^')){
		          matrix[i][j] = '^';
		       }
	   else{
	         matrix[i][j] = '.';
	 }
                      }	     
        }
      }
   return matrix;
}
void contar(char** matrix, int size){
  int cont=0;	
  for(int i=0;i<size;i++){
     for(int j=0;j<size;j++){
        if(matrix[i][j] == '.'){
	   cont++;
	}	
     }
  }
cout<<"El total de azulejos seguros son: "<<cont<<endl;
}
