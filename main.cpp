#include <iostream>
#include <fstream>
using namespace std;
int op;
ofstream intercambiar, ordenamiento, cuenta;
void menu();
void ingreso(int a[]);
void imprimir0(int a[]);
void intercambio(int a[]);
void Ejercicio2();
void datos(int a[], int b);
void imprimir(int a[], int b);
void ordenado(int a[], int b);
//Ejercicio 3 y funciones
void Ejercicio3();
void Ingresar(float Mes[]);
int Busqueda(float Mes[],float Monto);
int main() {
 do{
 menu();
 switch(op){
 case 1:
 int a[6];
 ingreso(a);
 cout<<"Arreglo ingresado:\n";
 imprimir0(a);
 intercambio(a);
 cout<<"Arreglo con intercambio:\n";
 imprimir0(a);
 break;

 case 2:
 Ejercicio2();
 break;
 case 3:
 Ejercicio3();
 break;

 case 4:
 cout<<"Gracias\n";
 break;
 default: cout<<"Error intente de nuevo:\n\n";
 }
 }while(op!=4);
return 0;
}
void menu(){
 cout<<"\t\tTRABAJO EN GRUPO.\n\n";
 cout<<"\tALGORITMO Y ESTRUCTURA DE DATOS\n\n";
 cout<<"\tSELECCIONE UNA OPCION DEL MENU:\n\n";
 cout<<"1. Intercambiar posiciones de un vector:\n";
 cout<<"2. Ordenamiento de un vector:\n";
 cout<<"3. Cuenta de ahorros virtual del Banco Pichincha\n";
 cout<<"4. Salir.\n";
 cout<<"OPCION: ";
 cin>>op;
}
void ingreso(int a[]){
 int p=0;
 for (int i=1;i<=6;i++){
 cout<<"Ingrese el elemento "<<i<<" : ";
 cin>>p;
 if(p<0){
 cout<<"Error de ingreso, intente de nuevo.\n";
 i--;
 }
 else
 a[i]=p;
}
}
void imprimir0(int a[]){
  intercambiar.open("intercambio.txt", ios::app);
for(int j=1;j<=6;j++){
 cout<<a[j]<<"\t";
 intercambiar<<a[j]<<"\t";
}
cout<<endl;
intercambiar<<endl;
intercambiar.close();
}
void intercambio(int a[]){
 int aux;
 int x=6;
 for(int i=1;i<=3;i++){
 aux=a[i];
 a[i]=a[x];
 a[x]=aux;
 x--; 

 }
}
void Ejercicio2(){
 int n;
 cout << endl;
 cout << "Escriba el número de elementos que va a ingresar: ";
 cin >> n;
 int arreglo[n];
 datos(arreglo, n);
 ordenamiento.open("ordenamiento.txt", ios::app);
 cout << "Datos ingresados: ";
 ordenamiento << "Datos ingresados: ";
 ordenamiento.close();
 imprimir(arreglo, n);
 ordenado(arreglo, n); // Método de la burbuja
}
void Ejercicio3()
{
  cuenta.open("cuenta.txt", ios::app);
 int mes,opcion;
 do{
 float Mes[12];
 cout << "\n_____________________________________\n";
 cout << "Bienvenido Alberto Perez\n";
 cout << "Que desea Hacer?\n";
 cout << "1.-Ingresar los montos de dinero\n";
 cout << "2.-Revisar monto Ingresado en un mes\n";
 cout << "3.-Salir\n";
 do{
 cin >> opcion;
 if(opcion>3)
 {
 cout << "Opcion Invalida\nVuelva a ingresar\n";
 }
 }while (opcion>3);
 switch(opcion)
 {
 case 1:
 Ingresar(Mes);
 break;
 case 2:
 float Monto;
 cout << "Ingrese el Monto que desea buscar: ";
 cuenta << "Ingrese el Monto que desea buscar: ";
 cin >> Monto;
 if(Busqueda(Mes, Monto)==-1)
 {
 cout << "Elemento no encontrado";
 cuenta << "Elemento no encontrado";
 }
 else
 { 

 cout << "Elemento encontrado En el mes : " << Busqueda(Mes, Monto);
 cuenta << "Elemento encontrado En el mes : " << Busqueda(Mes, Monto);
 }
 break;

 case 3:
 cout<<"Gracias por su visita:\n";
 break;
 default: cout<<"Error, vuelta a intentar:\n";

 }
 }while(opcion!=3);
 cuenta.close();

}
void Ingresar(float Mes[])
{
 for (int i=0;i<12;i++)
 {
 do{

 cout << "Ingrese El monto en el Mes " << i+1 << ": " ;

 cin >> Mes[i];
 if(Mes[i]<0)
 {
 cout << "Valor invalido\n";
 }
 }while(Mes[i]<0);

 }
}
int Busqueda(float Mes[],float Monto)
{
 for (int i = 1; i<=12 ;i++)
 {
 if(Mes[i]==Monto)
 {
 return i+1;
 }
 }
 return -1;
}
void datos(int a[], int b){
 for (int i = 0; i < b; i++){
 cout << "Ingrese el elemento " << i+1 << ": ";
 cin >> a[i];
 }
 cout << endl;
}
void imprimir(int a[], int b){
  ordenamiento.open("ordenamiento.txt", ios::app);
 for (int i = 0; i < (b-1); i++){
 cout << a[i] << ", ";
 ordenamiento << a[i] << ", ";
 }
 cout << a[b-1];
 cout << endl;
 ordenamiento << a[b-1];
 ordenamiento << endl;
 ordenamiento.close();
}
void ordenado(int a[], int b){
 int tem;
 cout << "Datos ordenados: ";
 for(int i=0; i<b; i++)
 {
 for(int j=i+1; j<b;j++)
 {
 if(a[j]<a[i])
 {
 tem=a[i];
 a[i]=a[j];

 a[j] = tem;

 }
 }
 }
 imprimir(a, b);
 cout << endl;
}