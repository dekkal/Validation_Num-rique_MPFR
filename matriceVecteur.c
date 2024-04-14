#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>

void dotProduct(mpfr_t* dest ,mpfr_t* matrix,mpfr_t *v ,int size) {
    
    mpfr_t dot;
    mpfr_init(dot);
    mpfr_set_d(dot,0,MPFR_RNDN);
    int i,j;
    mpfr_t c[size];
    for( i=0;i<size;i++){
        mpfr_init(c[i]);
    }
     mpfr_t vect[size];
    for( i=0;i<size;i++){
        mpfr_init(vect[i]);
    }    
    for (i = 0; i < size; i++) {
        for ( j = 0; j < size; j++)
        {
            /* code */
        }     
        mpfr_mul(c[i],matrix[i*size+j],v[i],MPFR_RNDN);
        //mpfr_printf("multiplicatiompfr_set_d(matrix[1],1.0,MPFR_RNDN);n = %.10Rg\n",c[i]);
        mpfr_add(vect[i],c[i],dot,MPFR_RNDN);
       
    }
     //mpfr_printf("sum= %.10Rg\n",dot);
    //res=dot;
   mpfr_set(dest[i],vect[i],MPFR_RNDN);  
}

int main(){

int size=3;  
int i ;
double v1[2]={4,5,5,6};

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

mpfr_t res[i];
   for( i=0;i<size;i++){
        mpfr_init(res[i]);
       
    }

dotProduct(a, b,size,res);


}