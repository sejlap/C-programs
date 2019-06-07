#include <stdio.h>

char *dvostruko(char *s){
	char *p=s;
	int brojacnovi=0,brojacprije=0,negativan=0;
	while(*p!='\0') {
		int tmp;
		int prvaNula=0;
		if(*p=='-')
			negativan=1;
		if(*p>='0' && *p<='9') {
			if(*p=='0' && !(*(p-1)>='0' && *(p-1)<='9')) prvaNula=1;
			tmp=0;
			brojacnovi=0;
			brojacprije=0;
			char *p1=p;
			while(*p1>='0' && *p1<='9') {	//brojimo cifre prije pretvorbe
				brojacprije++;
				p1++;
			}
			while(*p>='0' && *p<='9') { //pretvaramo string u int
				tmp=tmp*10 + *p - '0';
				p++;
			}
			tmp*=2; //dvostruka vrijednost naseg broja
			int broj=tmp;
			do {
				brojacnovi++;  ///brojimo cifre poslije pretvorbe
				broj/=10;
			} while(broj!=0);

			if(brojacnovi<brojacprije || (brojacnovi==1 && brojacprije==1)) { //ako je broj jednocifren
				char *s1=p;
				s1--;
				do {
					*s1--=tmp%10 + '0';
					tmp/=10;
				} while(tmp!=0);
			} else if(prvaNula==1 && brojacnovi<=brojacprije) { //ako se nula nalazi prije broja
				char *kraj=p;
				while(*kraj!='\0')	kraj++;
				while(kraj>=p) {
					*(kraj+(brojacnovi-brojacprije+1))=*kraj;
					kraj--;
				}
				char *s3=p;
				do {
					*s3--=tmp%10 + '0';
					tmp/=10;
				} while(tmp!=0);
				*s3='0';
			}

			else {
				char *kraj=p;
				while(*kraj!='\0')
					kraj++;
				while(kraj>=p) {
					*(kraj+(brojacnovi-brojacprije))=*kraj;
					kraj--;
				}
				if(negativan==1) p--;
				char *s3=p;
				do {
					*s3--=tmp%10 + '0';
					tmp/=10;
				} while(tmp!=0);
			}

		}
		p++;
	}

	return s;
}
int main()
{

	char tekst[100] = "Za broj -13 ispravno rjesenje je i -2292 i -333.";
	printf("'%s'", dvostruko(tekst));


	return 0;
}
