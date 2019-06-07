#include <stdio.h>
char *zamijeni_min_max(char *s){
	char *p=s;
	int ne_slovo=0,brojaci[200]= {0},br=0;
	char *prethodni=s;
	int i=0;
	//provjeravamo duzine rijeci i stavljamo u niz brojaca
	while(*p!= '\0') {
		if(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?' || *p==';') ne_slovo=1;
		if(ne_slovo==1) {
			ne_slovo=0;
			brojaci[i]=(p-prethodni);
			i++;
			br++;
			prethodni=p+1;
		}
		p++;
		if(*p=='\0') break;
	}
	if(*p=='\0') {
		ne_slovo=0;
		brojaci[i]=(p-prethodni);
		i++;
		br++;
		prethodni=p+1; //stavljat ce i nule pazit na to
	}
	i=0;
	int max=0,maxi=-99999,mini=0,j,min=9999;
	for(i=0; i<br; i++) {
		if(brojaci[i]>max) { //daj najduzu rijec
			max=brojaci[i];
			maxi=i;
		}
	}

	for(j=0; j<br; j++) {
		if(brojaci[j]<min && brojaci[j]!=0) { //daj najkracu rijec
			min=brojaci[j];
			mini=j;
		}
	}
	p = s;
	if(max==min) return s; //ako su iste duzine nista ne radi
	else {
		char tekstmini[100] = {'\0'};  //prebacivanje najmanje rijeci u tekstmini
		char *tekstmini2 = tekstmini;
		int rijec_je=0,broj_rijeci=0, br_znakova=0,bio=0;
		while(*p!='\0') {
			if(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?' || *p==';') {
				rijec_je=1;
				br_znakova++;
			} 
			else if(rijec_je==1) {
				rijec_je=0;
				broj_rijeci++;
				int minbroj=min;
				if(bio==1) break;
				if(br_znakova==mini || broj_rijeci==mini) {
					char *pom=p;
					while(minbroj!=0) {
						*tekstmini2++=*pom++;
						minbroj--;
					}
					bio=1;
				}
			}
			p++;
		}

		//prebacivnje najduze rijeci u tekstmaxi
		char tekstmaxi[100] = {'\0'};
		char *tekstmini3 = tekstmaxi;
		p = s;
		rijec_je=0 ;
		broj_rijeci=0;
		br_znakova=0;
		bio=0;
		while(*p!='\0') {
			if(br_znakova==maxi || broj_rijeci==maxi) {
				int minbroj=max;
				char *pom=p;
				if(bio==1) break;
				while(minbroj!=0) {
					*tekstmini3++=*pom++;
					minbroj--;
					bio=1;
				}
			}
			if(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?' || *p==';') {
				rijec_je=1;
				br_znakova++;
			} 
			else if(rijec_je==1) {
				rijec_je=0;
				broj_rijeci++;
				int minbroj=max;
				if(br_znakova==maxi || broj_rijeci==maxi) {
					char *pom=p;
					if(bio==1) break;
					while(minbroj!=0) {
						*tekstmini3++=*pom++;
						minbroj--;
						bio=1;
					}
				}
			}
			p++;
		}

		//izbacivanje najduze rijeci iz recenice
		p=s;
		rijec_je=0,broj_rijeci=0,br_znakova=0,bio=0;
		char *poc= NULL;
		if(br_znakova==maxi || broj_rijeci== maxi) poc=p;
		while(*p!='\0') {
			if(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?' || *p==';') {
				rijec_je=1;
				br_znakova++;
				if(br_znakova==maxi+1) {
					while(*poc++ = *p++);  //za izbacivanje viska najduze rijeci
					p--;
				}
			} 
			else if(rijec_je==1) {
				rijec_je=0;
				broj_rijeci++;

				if(br_znakova==maxi || broj_rijeci==maxi) { 
					poc=p;
					char *k=p;
					int brojk=max;
					while(brojk!=0) {
						brojk--;
						k++;
					}
					if(*k=='\0') *p='\0';
				}

				if(br_znakova==maxi+1 || broj_rijeci==maxi+1) {
					while(*poc++=*p++);  //za izbacivanje viska najduze rijeci

					p--;
				}

			}
			if(*p=='\0') break;
			p++;
		}

		//ubacivanje najduze rijeci na mjesto indeksa mini
		p=s;
		rijec_je=0,broj_rijeci=0,br_znakova=0;
		while(*p != 0) {
			if(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?' || *p==';') {
				rijec_je=1;
				br_znakova++;
			} 
			else if(rijec_je==1) {
				rijec_je=0;
				broj_rijeci++;
				if(br_znakova==mini || broj_rijeci==mini) {
					char *kraj=p;
					while(*kraj!= '\0') kraj++;
					while(kraj>p) {
						*(kraj+(max-min))=*kraj;
						kraj--;
					}
					if(*kraj=='\0') break;
					kraj--;
					char *s1=tekstmaxi;
					while(*s1!='\0') *p++=*s1++;
					if(*p=='\0') break;
				}
			}
			p++;
		}


		//ubacivanje najkrace rijeci na mjesto maxi
		p=s;
		rijec_je=0,broj_rijeci=0,br_znakova=0;
		while(*p != 0) {
			if(*p==' ' || *p=='.' || *p==',' || *p=='!' || *p=='?' || *p==';') {
				rijec_je=1;
				br_znakova++;
				if(br_znakova==maxi+1) {
					char *end=p;
					while(*end !='\0') end++;

					while(end>=p) {
						*(end + min) = *end;
						end--;
					}
					char *s2=tekstmini;
					while(*s2!='\0') *p++=*s2++;
				} 
				else if(br_znakova==maxi && *(p+1)=='\0') {
					p++;
					char *s2=tekstmini;
					while(*s2!='\0') *p++=*s2++;
				}
			}
			if(*p=='\0') break;
			p++;
		}

		return s;
	}
}


int main()
{
	char recenica[] = "Ovo je primjer recenice sa dugackim, kratkim rijecima.";
	printf ("'%s'", zamijeni_min_max(recenica));
}
