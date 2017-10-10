#include <stdio.h>
//V cju podatkovni tip kazalci **********************************
//Spremenljivka ki hrani pomnilniške lokacije ("pointa", kje se nahaja določena vrednost)
//
//Primer
//	int x,y;
//	int *p; v tem pointerju bomo hranili pomnilniški naslov, na tem pomn. naslovu pa bo neko celo število, zato moramo deklerirati pod. tip
//
//

void vaja1(){
	int x,y;
	int *p;
	x=3;
	p=&x; //tukaj smo v *p zapisali naslov, na katerem se nahaja spremenljivka x
	y=*p; //tako pa na y nastavimo vrednost tega pointerja, ki pa kaže na x, kateri je 3
	*p=x+y; //tukaj pa x nastavimo vrednotsi x+y in nastane 6
	//glej na list v akti
	print("%d %d",x,y);

}

int main(){
	vaja1();
}

