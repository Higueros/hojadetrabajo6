// Ejercicio 2

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream> 
using namespace std;


int main(){
	int i,N,aux,contador=0;
	int j;
	char genero;
	int peso, altura,edad;
	int pesoacum,alturaacum,edadacum;
	int prompeso,promaltura,promedad;


	
	
	
	cout<<"Ingrese la cantidad de personas: "<<endl;
	cin>>N;
	ofstream db;
	for(i=1;i<=N;i++){
		cout<<"Ingrese la edad: "<<endl;
		cin>>edad;
		edadacum += edad;
		cout<<"Ingrese el genero (M) o (F) : "<<endl;
		cin>>genero;
		cout<<"Ingrese el peso: "<<endl;
		cin>>peso;
		pesoacum += peso;
		cout<<"Ingrese la altura: "<<endl;
		cin>>altura;
		alturaacum += altura;
		contador++;
	}
	
	for(i=0;i<N;i++){
			for(j=0;j<1;j++){
				if(edadacum[j] > edadacum[j+1]){
					aux = edadacum[j];
					edadacum[j] = edadacum[j+1];
					edadacum[j+1] = aux;
				}
			}
	}
		
		

	
	
	promedad = edadacum / contador;
	prompeso = pesoacum / contador;
	promaltura = alturaacum / contador;

	
	cout<<"El promedio de peso fue de: "<<prompeso<<endl;
	cout<<"El promedio de altura fue de: "<<promaltura<<endl;
	cout<<"El promedio de edad: "<<promedad<<endl;
	
	

	try{
		db.open("personas.txt",ios::app);
		
		db<<edad<<"\t"<<peso<<"\t"<<altura<<"\t"<<genero<<endl;
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}
		
/*	 try{
		db.open("personas.txt",ios::app);
		db<<idiai<<"\t"<<imod<<"\t"<<icant<<"\t"<<endl;	
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}
	*/
}
