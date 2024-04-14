#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>



void assigner_valeur_vecteur(mpfr_t* a, mpfr_t *b,int size){
int i;
for(i=0;i<size;i++){
mpfr_set_d(a[i],b[i],MPFR_RNDN);
mpfr_printf("%.10Rg\n",a[i]);    
}
}

int main(){



}