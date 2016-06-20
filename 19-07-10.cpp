#include <fstream>
#include <iostream>

using namespace std;

fstream input,output;
// PUNTI 2 - Questa funzione conta le righe del file.
int contaRighe(char nomeFile[])
{
	int num;
	int i=0;
input.open(nomeFile, ios::in);
 while(input >> num) {
 	i++;
}
input.close();
return i;
	
}
// PUNTI 3 – Questa procedura carica i dati contenuti nel file nel vettore.
void caricaVettore (char nomeFile[], int vettore[])
{
	int num;
	input.open(nomeFile,ios::in);
	for (int i=0;input>>num;i++) vettore[i]=num;
	input.close();
}
// PUNTI 3 – Questa procedura ordina il vettore.(bubblesort,come richiesto da lui)
void ordina( int vettore[], int dimensione )
{
	int temp; // variabile d'appoggio
	bool scambio=true;
	while(scambio)
	{
		scambio=false;
		for (int i=0;i<dimensione-1;i++) 
		{
		if (vettore[i]>vettore[i+1])
		{
			temp=vettore[i];
			vettore[i]=vettore[i+1];
			vettore[i+1]=temp;
			scambio=true;
		}
	}
}
}
//Questa procedura prende i dati contenuti in vettoreIn1 e in vettoreIn2 e li inserisce in vettoreSum.
void fondi ( int vettoreSum[], int vettoreIn1[], int vettoreIn2[], int dimVett1, int dimVett2 )
{
	int f=0;
	int g=dimVett1;
	for (int i=0;i<dimVett1;i++) vettoreSum[i]=vettoreIn1[i]; // metto prima i numeri di vett1 in vettoresum
	while (g<(dimVett1+dimVett2))
	{
		vettoreSum[g]=vettoreIn2[f]; //...poi quelli di vett2 in vettoresum
		g++;f++;
	}
}
// PUNTI 3 – Questa procedura elimina i dati contenuti in vettDel da vettSum e mette i dati rimanenti in vettOut.
void pulisci ( int vettOut[], int vettSum[], int vettDel[], int& dimVettSum, int dimVettDel) 
{ // dimVettSum passato come riferimento in modo da aggiornarsi ogni volta che viene tolto un elemento
// che tornerà utile quando andrò a stampare gli elementi del vettoreSum
	int i=0,d=0,c=0,temp;
	while (i<dimVettSum)
	{
		if (vettDel[d]==vettSum[i]) //se trova un elemento di vettDel in vettSum
		{
			vettOut[c]=vettSum[i]; // lo sposta vettOut
			for (int q=i;q<dimVettSum;q++){
			vettSum[q]=vettSum[q+1]; //in questo modo elimino l'elemento dall'array vettSum
			}
			d++;i++;dimVettSum--;c++; // diminuisce il numero di elementi di dimVettSum e incrementa d,i,c
		}
		else i++; // se non lo trova incrementa solo i
	}
}
// PUNTI 2 – Questa procedura salva il vettore risultante in un file.
void salvaFile( char nomeFile[], int vettore[], int dim )
{
	int y=0;
	output.open(nomeFile,ios::out);
	while (y<dim)
	{
		output << vettore[y] << endl;
		y++; 
	}
}
// PUNTI 1 – Questa procedura scambia gli elementi a e b di un vettore.
void scambiaElementi( int &a, int &b )
{ //utilizzare questa funzione nel bubblesort, non so quanto sià efficente,però dato che la richiede l'ho fatta
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main ()
{
char nomeel1[20]={"elenco1.txt"},nomeel2[20]={"elenco2.txt"},nomeel3[20]={"elenco3.txt"};
int dimel1=contaRighe(nomeel1);
int dimel2=contaRighe(nomeel2);
int dimel3=contaRighe(nomeel3);
int vett1[dimel1], vett2[dimel2],vett3[dimel3];
caricaVettore(nomeel1,vett1);
caricaVettore(nomeel2,vett2);
caricaVettore(nomeel3,vett3);
int dimsum=dimel1+dimel2; 
int vettoresum[dimsum];
fondi(vettoresum,vett1,vett2,dimel1,dimel2);
int vettoreout[dimel3];
pulisci(vettoreout,vettoresum,vett3,dimsum,dimel3);
ordina(vettoresum,dimsum);
char nomefin[20]={"risultato.txt"};
salvaFile(nomefin,vettoresum,dimsum);
return 0;
}
