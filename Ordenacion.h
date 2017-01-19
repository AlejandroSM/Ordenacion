#include <iostream>
#include<stdio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstdlib>
#include<math.h>
#include<libxl.h>
#include<C:\Users\Alex_Salazar_M\Desktop\C++\Ordenacion\convertircadena.h>
#include<C:\Users\Alex_Salazar_M\Desktop\C++\Ordenacion\intercalaciones.h>   
using namespace std;
using namespace libxl;
FILE *datosexcel;
int qmas=0,qcam=0;

void archivoexcel(string nombr,int iter,int comp)
{
	char linea[100];int a=0;
	datosexcel=fopen("resultsort.xls","a+");		
	//fprintf(datosexcel,"\n\t\t\t Metodo\t iteracion\t comparacion\tsuma\n");
	
		fprintf(datosexcel,"\n\t\t\t%s\t%d\t%d\t=E4+F4",nombr.c_str(),iter,comp);		
		fclose(datosexcel);
	
}
void menu(int array[],int espacio);
int menor (int arreglo[], int desde,int TAM,int *inter,int *comp)
{
     int i, menor;

     menor = desde++;
     for (i=desde; i<TAM; i++){
          *comp++;
		  if (arreglo[i] < arreglo[menor]){
               menor = i;
				*inter++;
				}
				}
     return menor;
}

void mostrar (int arreglo[],int TAM,int comp,int inter,string nombre)
{
    int i;


     for (i=0; i<TAM; i++)
          printf ("\n\tElemento[%d] = %d", i, arreglo[i]);

     printf ("\n\n\t");
     cout<<"comparaciones: "<<comp;
     cout<<"intercambio: "<<inter;
     archivoexcel(nombre,inter,comp);
     
//     PAUSA();
}


void ord_rap (int arreglo[], int inf, int sup)
{
     int elem_div = arreglo[sup];
     int temp;
     int i = inf - 1, j = sup;
     int cont = 1;
     int comp=0,inter=0;

     if (inf >= sup)     /* ¨Se cruzaron los ¡ndices ? */
          return;

     while (cont)
          {
		  
          while (arreglo[++i] < elem_div){qmas++;}
          while (arreglo[--j] > elem_div){qmas++;}
          /* ¨Se cumple la condici¢n ? */
          if (i < j)
               {comp++;
               temp = arreglo[i];
               arreglo[i] = arreglo[j];
               arreglo[j] = temp;
               inter++;
               qcam++;
               }
          else
              cont = 0;
          }

     /* Dejamos el elemento de divisi¢n en su posici¢n final */
     temp = arreglo[i];
     arreglo[i] = arreglo[sup];
     arreglo[sup] = temp;
		inter++;
     /* Aplicamos recursivamente a los subarreglos generados */
     ord_rap (arreglo, inf, i - 1);
     ord_rap (arreglo, i + 1, sup);
     
 //    mostrar(arreglo,sup,cont,inter,"QuickSort");
}

void burbuja (int arreglo[],int tam)
{
    int TAM=tam;
     int i, j;
     int temp,comp=0,inter=0;

     for (i=1; i<TAM; i++)
          {
              for (j=0; j<TAM - i; j++)
               if (arreglo[j] > arreglo[j+1])
               {
               		comp++;
                    /* Intercambiamos */
                    temp = arreglo[j];
                    arreglo[j] = arreglo[j+1];
                    arreglo[j+1] = temp;
                    inter++;
               }else
			   {
			   	comp++;
			   }
		 }

     printf ("\n\n\tOrdenamiento burbuja.");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo,TAM,comp,inter,"Burbuja1");
}

void ordBurbuja(int a[], int n)
{ 
	int i = 1, len = n,aux;
    bool sorted = false;
    int pasada, j,comp=0,inter=0;
	while(i<n && !sorted)
	{
		i++;
		sorted=true;
		for(int index=0;index<len;index++)
		{
			comp++;
			if(a[index] > a[index+1]){
				sorted=false;
				aux=a[index];
                a[index] = a[index+1];
                a[index+1] = aux;
				inter++;			
			}
		}
	}
   mostrar (a,n,comp,inter,"Burbuja2");
}

/*
 Ordenación por burbuja: array de n elementos
 Se realizan una serie de pasadas mientras indiceIntercambio > 0
*/
void ordBurbuja2(int a[],int n)
{
     int i, j;
     int indiceIntercambio;
     /* i es el índice del último elemento de la sublista */
     i = n-1;
     int comp=0,inter=0;
     /* el proceso continúa hasta que no haya intercambios */
     while (i > 0)
     {
         indiceIntercambio = 0;
         /* explorar la sublista a[0] a a[i] */
         for (j = 0; j < i; j++)
		 {
	             	comp++;
	         /* intercambiar pareja y actualizar IndiceIntercambio */
	             if (a[j+1] < a[j])
	             {
	                 int aux = a[j];
	                 a[j] = a[j+1];
	                 a[j+1] = aux;
	                 indiceIntercambio = j;
	             	inter++;
				 }
		 }
	/* i se pone al valor del índice del último intercambio */
     i = indiceIntercambio;
     }
     mostrar (a,n,comp,inter,"Burbuja3");
}

void ordenacioninsercciondos(int a[], int n)
{
	 int intervalo, i, j, k;
	 intervalo = n / 2;
	 int comp=0,inter=0;
	 while (intervalo > 0)
	 {
		 for (i = intervalo; i < n; i++)
		 {
			 j = i - intervalo;
			 while (j >= 0)
		 		{
					 k = j + intervalo;
					 if (a[j] <= a[k]){
					 	j = -1; /* así termina el bucle, ya está ordenado */
					 comp++;
					 }else
					 {
					 	comp++;
						 double temp;
						 temp = a[j];
						 a[j] = a[k];
						 a[k] = temp;
						 j -= intervalo;
						 inter++;
					}
	 			}
	 	}
	 intervalo = intervalo / 2;
	 }
     mostrar (a,n,comp,inter,"Insertion2");
}


void seleccion (int arreglo[],int tam)
{
	
     int TAM=tam;
     int i,j,inter=0,comp=0;
     int temp, pos_men;
     for (i=0; i<TAM - 1; i++)
     {
		  pos_men=i++;
		  for(j=i;j<TAM;j++)
		  {
		  	comp++;
		  	if(arreglo[j]<arreglo[pos_men])
			{
				pos_men=j;
				inter++;
		  	}
		  }
          temp = arreglo[i];
          arreglo[i] = arreglo [pos_men];
          arreglo [pos_men] = temp;
          //inter++;
    }

     printf ("\n\n\tOrdenamiento por selecci¢n.");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo,tam,comp,inter,"Selection");
}

void insercion (int arreglo[],int tam)
{
    int TAM=tam;
     int i, j, temp;
	int inter=0,comp=0;
     for (i=1; i<TAM; i++)
    {
          temp = arreglo[i];
          j = i - 1;
          /* Desplazamos los elementos mayores que arreglo[i] */
          while ( (arreglo[j] > temp) && (j >= 0) )
               {
               	comp++;
               arreglo[j+1] = arreglo[j];
               j--;
               inter++;
               }
          /* Copiamos arreglo[i] en su posici¢n final */
          arreglo[j+1] = temp;
          inter++;
    }

     printf ("\n\n\tOrdenamiento por inserci¢n.");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo,TAM,comp,inter,"Insertion1");
}

void quicksort (int arreglo[],int TAM)
{
     ord_rap (arreglo, 0, TAM - 1);

     printf ("\n\n\tOrdenamiento r pido (QUICKSORT).");
     printf ("\n\tEl arreglo ordenado es:\n");
     mostrar (arreglo,TAM,qmas,qcam,"Quicksort");
}

void archivo(string nombre)
{
	fstream ficheroEntrada;
	char lineas[400];
	int letras[500];
	char letra;
	int i=0;
	int a,r;
    ficheroEntrada.open (nombre.c_str(), ios::in);
	int op;
    if (ficheroEntrada.is_open())
        {
        	ficheroEntrada.getline(lineas,10);
        	ficheroEntrada.getline(lineas,10);
          	printf("\t\tnumero de elementos = %d",a = atoi(lineas));
            cout<<endl<<endl<<"\t";
			while (!ficheroEntrada.eof())
            {
             	ficheroEntrada.getline(lineas,10);
            	letras[i]=atoi(lineas);
            	cout<<letras[i];
                i++;
                if(i<100 && op<20)
				{
					cout<<"-";
				}else
				{
					cout<<";";
				}
                if(op==20)
				{
					cout<<endl;
					cout<<"\t";
					op=0;
				}
				op++;
            }
            
            ficheroEntrada.close();
     
	 }else{cout << "Fichero inexistente"<<endl;}
	 menu(letras,a);
}


void burbujados(int array[],int tam)
{
    int TAM=tam;
            int i = 1, len = TAM;
        boolean sorted = false;
        int temp;
        while(i < len && !sorted) {
            i++;
            sorted = true;
            for(int index = 0; index < len; index++) {
                if(array[index+1]==array[index] && array[index]< 0 && array[index+1]<0) {
                    sorted = false;
                    temp = array[index+1];
                    array[index+1] = array[index];
                    array[index] = temp;
                }
            }
        }
       mostrar (array,tam,0,0,"Burbuja");
}
void menu(int array[],int espacio)
{

    int num=espacio;
	int aux;
	int caso;
	int a=1,version;
	int arreglo[espacio];
	for(int x=0;x<espacio;x++)
    {
     	arreglo[x]=array[x];
    }
    
             while(a!=0)
            {
					cout<<endl;
                    cout<<endl<<"\t\t1>> BubleSort>> 1";
                    cout<<endl<<"\t\t2>> BubleSort>> 2";
                    cout<<endl<<"\t\t3>> BubleSort>> 3";
                    cout<<endl<<"\t\t4>> SelectionSort";
                    cout<<endl<<"\t\t5>> IsertSort>> 1";
                    cout<<endl<<"\t\t6>> IsertSort>> 2";
                    cout<<endl<<"\t\t7>> QuickSort";
                    cout<<endl<<"\t\t8>> Intercalacion";
                    cout<<endl<<endl<<"\t\t>> Que desea conocer:  ";
                    cin>>caso;
                    switch(caso)
                    {
                        case 1:burbuja(arreglo,num);break;
                        case 2:ordBurbuja(arreglo,num);break;
                        case 3:ordBurbuja2(arreglo,num);break;
                        case 4:seleccion(arreglo,num);break;
                        case 5:insercion(arreglo,num);break;
                        case 6:ordenacioninsercciondos(arreglo,num);break;
                        case 7:quicksort(arreglo,num);break;
                        case 8:decidiointercalacion();break;
                        default:cout<<"\t"<<"lo sentimos no existe el metodo dado";break;
                    }
          			cout<<endl<<"\n\tpara terminar solo inserte 0";
                    cout<<endl<<"\tingresa un numero >> ";
                    cin>>a;
}            }
