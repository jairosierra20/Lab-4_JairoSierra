#include <iostream>
using std::cout;
using std::cin;
using std::endl;
  int menu();
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
