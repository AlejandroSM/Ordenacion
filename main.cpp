#include <iostream>
#include<stdio.h>
#ifdef __LCC__
#include <windows.h>
#endif
#ifdef __MINGW32__
#include <windows.h>
#endif
#include <string>

#include <C:\Users\Alex_Salazar_M\Desktop\C++\Ordenacion\ordenacion.h>

using namespace std;

int main()
{
	datosexcel=fopen("resultsort.xls","a+");		
	
	fprintf(datosexcel,"\n\t\t\t Metodo\t intercambio\t comparacion\tsuma\n");
	
	fclose(datosexcel);
	int a=1;
    string narchvio;
    while(a!=0)
	{        
            cout<<endl<<"\t\tingresa el nombre del fichero:"<<endl;
            cout<<"\t\t>>";
            cin>>narchvio;
            cout<<endl;
            archivo(narchvio);
            cout<<endl<<"si deseas terminar presiona la tecla 0>> ";cin>>a;
		}

}
