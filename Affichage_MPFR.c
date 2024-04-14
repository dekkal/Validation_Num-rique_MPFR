#include<stdio.h>
#include<mpfr.h>

void affichage_b(double *b,int n){

int i;

mpfr_t H[n];
mpfr_printf("matrice b est \n");

for(i=0;i<n;i++)
{
mpfr_init2(H[i],53);
mpfr_set_d(H[i],b[i],MPFR_RNDN);
mpfr_printf("%.10Rg\n",H[i]);
}
}



int main(void)
{
// Affiche de b
double b[2]={10,15};
affichage_b(b,2);

}

