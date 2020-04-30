/*HT6_ejercicio1*/


#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

void mp();
void ingresa_venta();
void reporte_venta();
void eliminar();
void modificar();

using namespace std;


int main(){
	mp();
	
	/* return 0;*/
}

void mp(){
	int resp;
	
	do {
		system("CLS");
		cout<<"_________________________________"<<"\n"<<"\n";
		cout<<"	MENU PRINCIPAL	"<<"\n";
		cout<<"_________________________________"<<"\n"<<"\n";
		cout<<" 1 . 	Ingresa Venta			"<<"\n";
		cout<<" 2 . 	Reporte 				"<<"\n";
		cout<<" 3 . 	Elimina Registro		"<<"\n";
		cout<<" 4 . 	Modifica Registro		"<<"\n";
		cout<<"\n";
		cout<<" 5 .	SALIR					"<<"\n";
		cout<<"_________________________________"<<"\n"<<"\n";
		cout<<" Selecciona una opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			ingresa_venta();			
		}
		else if (resp==2){		
			system("CLS");
			reporte_venta();
		}
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void ingresa_venta(){
	int i,idiai, imod, icant,suma1,suma2,suma3,suma4;
	float precio1=0,precio2=0,precio3=0,precio4=0, total1=0,total2=0,total3=0,total4=0;
	
	ofstream db;
	
	system("CLS");
	cout<<"_________________________________________________"<<"\n"<<"\n";
	cout<<"			INGRESO DE VENTA DE CUADERNO			"<<"\n"<<"\n";
	cout<<"_________________________________________________"<<"\n"<<"\n";
	cout<<"- Ingresa número de día: ";
	cin>>idiai;
	cout<<"- Ingresa modelo a comprar:";
	cin>>imod;
	cout<<"- Ingresa cantidad a comprar: ";
	cin>>icant;
	

	if(imod==1){
		imod = 1;
		precio1 = 10.00;
	}
	else if(imod==2){
		imod = 2;
		precio2 = 15.00;
	}
	else if(imod==3){
		imod = 3;
		precio3 = 18.50;
	}
	else if(imod==4){
		imod = 4;
		precio4 = 25.00;
	}
	
	total1 = precio1 * icant;
	total2 = precio2 * icant;
	total3 = precio3 * icant;
	total4 = precio4 * icant;
	
	cout<<"Total: "<<total1<<endl;
	
	cout<<"Total: "<<total2<<endl;
	
	cout<<"Total: "<<total3<<endl;
	
	cout<<"Total: "<<total4<<endl;

	
	
	system("Pause");
//	
	
	
	try{
		db.open("HT6_EJERCICIO_01.txt",ios::app);
		db<<idiai<<"\t"<<imod<<"\t"<<icant<<"\t"<<endl;	
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}
	
}

void reporte_venta(){
	int i,odiai, omod, ocant,suma,suma1=0,suma2=0,suma3=0,suma4=0;
	float precio1,precio2,precio3,precio4, total1,total2,total3,total4,totalmod=0;
	int mayormod, mayortotal = 0;
	
	ifstream db;
	try{
		db.open("HT6_EJERCICIO_01.txt",ios::in);
		cout<<"__________________________________________"<<"\n"<<"\n";
		cout<<"	DATOS DE VENTA...	"<<"\n"<<"\n"<<endl;
		cout<<"Dia	|"<<"\t"<<"Modelo	|"<<"\t"<<"Cantidad	"<<endl;
		while(db>>odiai>>omod>>ocant){
			
			cout<<setw(3)<<odiai<<"	|"<<setw(12)<<omod<<"	|	"<<setw(3)<<ocant<<endl;

			if(omod==1){
				total1++;
				suma1+=total1;
			}	
			else if(omod==2){		
				total2++;
				suma2+=total2;
			}
			else if(omod==3){	
				total3++;
				suma3+=total3;
			}
			else if(omod==4){		
				total4++;	
				suma4+=total4;
			}
		
			
			if(suma1>suma2 && suma1>suma3 && suma1>suma4){
				mayortotal = suma1;
				mayormod = 1;
			}	
				else if(suma2>suma1 && suma2>suma3 && suma2>suma4){
				mayortotal = suma2;
				mayormod = 2;
			}
			else if(suma3>suma1 && suma3>suma2 && suma3>suma4){
				mayortotal = suma3;
				mayormod = 3;
			}
			else if(suma4>suma1 && suma4>suma2 && suma4>suma3){
				mayortotal = suma4;
				mayormod = 4;
			}
		
		}
		db.close();
		
		cout<<"_________________________________________";
		cout<<"\n\n	RECAUDADO TOTAL POR MODELO	\n\n";
		cout<<"Total del modelo #1"<<": "<<suma1<<endl;
		cout<<"Total del modelo #2"<<": "<<suma2<<endl;
		cout<<"Total del modelo #3"<<": "<<suma3<<endl;
		cout<<"Total del modelo #4"<<": "<<suma4<<endl;
		cout<<"\n"<<endl;
		cout<<"_________________________________________";
		cout<<"\n\n	EL MODELO MAS VENDIDO	\n\n";
		cout<<"Modelo #"<<setw(3)<<mayormod<<" - El total del modelo - "<<setw(3)<<mayortotal<<endl;
		
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error al cargar del archivo"<<endl;
		cout<<"Erro: "<<X.what()<<endl;
		system("Pause");
	}
}

void eliminar(){
	ifstream db_a;
	ofstream db_n;
	int aux,odiai, omod, ocant,flag;
	remove("Temporal.txt");
	
	db_a.open("HT6_EJERCICIO_01.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<" - Ingresa el día a borrar: "<<endl;
	cin>>aux;
	
	while(db_a>>odiai>>omod>>ocant){
		if(aux==odiai){
			cout<<"REGISTRO ELIMINADO CON EXITO..."<<endl;
			flag=1;
		}
		else if(aux!=odiai){
			db_n<<odiai<<"\t"<<omod<<"\t"<<ocant<<endl;
		}
	}
	db_a.close();
	db_n.close();
	
	if(flag==1){
		remove("HT6_EJERCICIO_01.txt");
		rename("Temporal.txt","cuadernos.txt");
		
	}
	system("Pause");
	
}	

void modificar(){
	ifstream db_a;
	ofstream db_n;
	int auxd,auxc,odiai, icant,omod, ocant,flag;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("cuadernos.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingresa el día a modificar: "<<endl;
	cin>>auxd;
	cout<<"Ingresa el código del modelo a modificar: "<<endl;
	cin>>auxc;
	
	do {
		cout<<"Ingrese cantidad a modificar: "<<endl;
		cin>>icant;
		cout<<"\n\¿Está seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>odiai>>omod>>ocant){
		if(auxd==odiai && auxc==omod){
			db_n<<odiai<<"\t"<<omod<<"\t"<<icant<<endl;
			cout<<"SU ARCHIVO A SIDO ACTUALIZADO...."<<endl;
			flag =1;
		}			
		else if(auxd!=odiai && auxc!=omod)
			db_n<<odiai<<"\t"<<omod<<"\t"<<ocant<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("HT6_EJERCICIO_01.txt");
		rename("Temporal.txt","cuadernos.txt");
	}	
	system("Pause");
}




