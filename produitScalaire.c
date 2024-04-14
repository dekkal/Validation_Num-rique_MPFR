#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>
//Fonction qui permet de réaliser le scalar produit----------------------oky 
void dotProduct(mpfr_t* a, mpfr_t* b, int size, mpfr_t res) {
    
    mpfr_t dot;
    mpfr_init(dot);
    mpfr_set_d(dot,0,MPFR_RNDN);
    int i;
    mpfr_t c[size];

    for( i=0;i<size;i++){
        mpfr_init(c[i]);
    }

    for (i = 0; i < size; i++) {

        mpfr_mul(c[i],a[i],b[i],MPFR_RNDN);
        //mpfr_printf("multiplicatiompfr_set_d(matrix[1],1.0,MPFR_RNDN);n = %.10Rg\n",c[i]);
        mpfr_add(dot,c[i],dot,MPFR_RNDN);
       
    }
     //mpfr_printf("sum= %.10Rg\n",dot);
    //res=dot;
   mpfr_set(res,dot,MPFR_RNDN);  
}


int main(void){
int size=3;  
int i ;
double v1[2]={4,5};

mpfr_t a[i];
   for( i=0;i<size;i++){
        mpfr_init(a[i]);
        mpfr_set_d(a[i],v1[i],MPFR_RNDN);
    }

double v2[2]={2,3};
mpfr_t b[i];
   for( i=0;i<size;i++){
        mpfr_init(b[i]);
        mpfr_set_d(b[i],v2[i],MPFR_RNDN);
    }
// b=malloc(size*sizeof(mpf_t));

mpfr_t res;
mpfr_init(res); 
dotProduct(a, b,size,res);
}