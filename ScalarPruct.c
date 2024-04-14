#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>



void scalar_vector(mpfr_t* dest, mpfr_t *v, mpfr_t s, int size){
int i;
for(i=0;i<size;i++){

  mpfr_mul(dest[i],v[i],s,MPFR_RNDN);
  mpfr_printf("%.10Rg\n",dest[i]);    
}
}


int main(void){

int size=3 ;  
int i ;
mpfr_t dest[size];
   for(i=0;i<size;i++){
        mpfr_init(dest[i]);  
    }
double b[2]={10,15};

mpfr_t v[size];
   for(i=0;i<size;i++){
        mpfr_init(v[i]);
        mpfr_set_d(v[i],b[i],MPFR_RNDN);
    }

mpfr_t s;
mpfr_init(s); 
mpfr_set_d(s,2,MPFR_RNDN);

scalar_vector(dest, v,s,size);

//  mpfr_out_str (stdout, 10, 0, MPFR_RNDD);
}