#include <stdio.h>

int daj_sljedeci_broj(int broj){
	static int dno=0;  //static varijable za pamcenje prethodne vrijednosti
	static int vrh=100;
	static int srednji;

	while(vrh>=dno) {
		srednji=(vrh+dno)/2;  //polovljenje intervala
		if(broj==1) {
			dno=srednji;  // ako je veci otpisujemo jedan dio intervala
			srednji=(vrh+dno)/2;
		}
		if(broj==-1) {
			vrh=srednji;   //i ako je manji otpisujemo dio intervala
			srednji=(vrh+dno)/2;
		}
		if(broj==0) return srednji;
		else break;
	}

	return srednji;

}
int main(){

	char odgovor='J';
	int x=daj_sljedeci_broj(0);
	printf("Zamislite neki broj...\n");
do {
		printf("Da li je taj broj %d? ", x);
		scanf("%c", &odgovor);
		if(odgovor=='\n') odgovor=getchar();
		if(odgovor=='J')  x=daj_sljedeci_broj(0);
		else if(odgovor=='M') x=daj_sljedeci_broj(-1);
		else if(odgovor=='V') x=daj_sljedeci_broj(1);
		if(odgovor!='M' &&  odgovor!='V' && odgovor!='J')
			printf("Pogresan unos, probajte ponovo.\n");
		if(odgovor=='J') {
			printf("Pogodio sam!");
			break;
		}
	} while(odgovor!='J');

	return 0;
}
