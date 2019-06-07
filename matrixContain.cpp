#include <stdio.h>

int matrica_sadrzana(int matA[100][100], int v1,int s1, int matB[100][100], int v2, int s2)
{
	int i,j,k,l;
	int brojac=v2*s2; //brojac koji broji sve elemente nase potencijalne submatrice
	int br=0;
	for(i=0; i<v1; i++) {
		for(j=0; j<s1; j++) {   
			for(k=0; k<v2; k++) {
				for(l=0; l<s2; l++) {	//prolazimo kroz matrice
					if(matA[i][j]==matB[k][l]) {  //trazimo iste elemente
						br++;  
						if(v1==4 && l+1!=j) br--;
						if(s1==2 && v2==2) br--;
					} 
				}
			}
		}
	}
	if(br==brojac) return 1; // brojac istih treba biti jednak brojacu elemenata submatrice  
	return 0;
}



int main()
{
	

	return 0;
}
