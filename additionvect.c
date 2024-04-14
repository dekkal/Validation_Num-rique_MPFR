
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>



void addition(mpfr_t* dest, mpfr_t *a, mpfr_t *b, int size){
int i;
for(i=0;i<size;i++){

  mpfr_add(dest[i],a[i],b[i],MPFR_RNDN);
  mpfr_printf("%.10Rg\n",dest[i]);    
}}


int main(void){

int size=3 ;  
int i ;
mpfr_t dest[size];
   for(i=0;i<size;i++){
        mpfr_init(dest[i]);  
    }
double v1[2]={10,15};

mpfr_t a[size];
   for(i=0;i<size;i++){
        mpfr_init(a[i]);
        mpfr_set_d(a[i],v1[i],MPFR_RNDN);
    }
double v2[2]={12,16};
mpfr_t b[size];
   for(i=0;i<size;i++){
        mpfr_init(b[i]);
        mpfr_set_d(b[i],v2[i],MPFR_RNDN);
    }

addition(dest,a,b,size);

//  mpfr_out_str (stdout, 10, 0, MPFR_RNDD);
}