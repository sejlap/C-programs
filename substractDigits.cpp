#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void oduzmi_cifre(int niz[], int vel){
	int i=0,br=0,indeks=0,rez,j=0,trazeni=0,k=0;
	for(i=0; i<vel; i++) {
		int broj=abs(niz[i]);
		br=0;
		int noviniz[10]= {0}; //niz za pohranu razlike cifara
		indeks=0;
		while(broj!=0) {    //dijelimo broj na cifre
			int cifra1=broj%10;
			broj/=10;
			if(broj==0) break;
			rez=abs(cifra1-broj%10);
			if(broj!=0) br++;
			if(br>0) {
				noviniz[indeks]=rez;
				indeks++;
			}
		}
		if(br==0) niz[i]=0; //ako je jedna cifra, vraca 0
		else if(br>0) {
			k=1;
			trazeni=0;
			for(j=indeks-1; j>=0; j--) {
				trazeni+=(noviniz[j] * pow(10,indeks-k)); //upis clanova iz novog niza u varijablu int
				k++;
			}
			niz[i]=trazeni;
		}
	}
}

int main(){

	int niz[] = {-9533, 7, -19173}, i;
	oduzmi_cifre(niz, 3);
	for (i=0; i<3; i++)
		printf("%d ", niz[i]);

	return 0;
}
