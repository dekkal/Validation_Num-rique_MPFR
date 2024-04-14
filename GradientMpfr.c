#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<mpfr.h>


// mynorm1 : ||x||_1

void mpfr_mynorm1(mpfr_t ret, mpfr_t x[], int dim)
{
	int i;
	mpfr_t abs_x;
	mpfr_init2(abs_x, mpfr_get_prec(ret));

	mpfr_set_ui(ret, 0, MPFR_RNDN);

	for(i = 0; i < dim; i++)
	{
		mpfr_abs(abs_x, x[i], MPFR_RNDN);
		mpfr_add(ret, ret, abs_x, MPFR_RNDN);
	}
	mpfr_clear(abs_x);
}

// mynormi : ||x||_inf
void mpfr_mynormi(mpfr_t ret, mpfr_t x[], int dim)
{
	int i;
	mpfr_t abs_x;

	mpfr_init2(abs_x, mpfr_get_prec(ret));

	mpfr_abs(ret, x[0], MPFR_RNDN);

	for(i = 1; i < dim; i++)
	{
		mpfr_abs(abs_x, x[i], MPFR_RNDN);
		if(mpfr_cmp(ret, abs_x) < 0)
			mpfr_set(ret, abs_x, MPFR_RNDN);
	}
	mpfr_clear(abs_x);
}


// mynorm2 : ||x||_2
void mpfr_mynorm2(mpfr_t ret, mpfr_t* x, int dim)
{
	int i;

	mpfr_set_ui(ret, 0UL, _tk_default_rmode);

	for(i = 0; i < dim; i++)
		mpfr_fma(ret, x[i], x[i], ret, _tk_default_rmode);
		//ret += x[i] * x[i];

	mpfr_sqrt(ret, ret, _tk_default_rmode);
	return;
}

void assigner_valeur_vecteur(mpfr_t* a, mpfr_t *b,int size){
    int i;
for(i=0;i<size;i++){
    mpfr_set_d(a[i],b[i],MPFR_RNDN);
    mpfr_printf("%.10Rg\n",a[i]);    
}
}

void mpfr_clear_array(mpfr_t * array, int dim)
{
	int i;

	for(i = 0; i < dim; i++)
		mpfr_clear(array[i]);
}

void substact(mpfr_t* dest, mpfr_t *a, mpfr_t *b, int size){
int i;
for(i=0;i<size;i++){

mpfr_sub(dest[i],a[i],b[i],MPFR_RNDN);
mpfr_printf("%.10Rg\n",dest[i]);    
}}

void scalar_vector(mpfr_t* dest, mpfr_t *v, mpfr_t s, int size){
int i;
for(i=0;i<size;i++){

  mpfr_mul(dest[i],v[i],s,MPFR_RNDN);
  mpfr_printf("%.10Rg\n",dest[i]);    
}
}

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



int main(int argc, char **argv){ 

int i, tailleMatrice=2304; 
int tailleVect=48;     
	  /* Matice A */
	  double* matrix = malloc(tailleMatrice * sizeof(double)); 
 	//   /* Mon vecteur, B */ 
	  double* b = malloc(tailleVect * sizeof(double));
	  
        FILE* fichier=NULL;
	    // fseek(fichier,0x041B,SEEK_SET);

   
       fichier =fopen("./files/bcsstk01.mtx.txt","r");
       if (fichier!=NULL){

	  /* Lire ma matrice A */
	  for (i = 0; i < tailleMatrice; i++) { 
	  
            fscanf(fichier,"%lf",&matrix[i]);
	                                      }
      
       for (i = tailleMatrice; i < 2353; i++) {
	  
            fscanf(fichier,"%lf",&b[i]);
	                                    }
	                        
       fclose(fichier);
                                        } 

    //  Affichage de la matrice A
    //    for (i = 0; i <tailleMatrice ; i++) {

	//   	  printf("La valeur de l'élément [%d]=%lf\n", i,matrix[i]);
          
	//   } 
     


//    Affiche du vecteur b
    //   for (i = tailleMatrice; i < 2353; i++) { 
	  
    //       	  printf("La valeur de l'élément vecteur b [%d]=%lf\n", i,b[i]);
	//                                       }        
        // printf("Mon premier élément est \n\n");
        // printf(" %lf\n",matrix[0]);
        // printf(" %lf\n",matrix[1]);
        // printf("Mon premier élément est \n\n");
        // printf(" %lf\n",b[0]);
        // printf(" %lf\n",b[1]);
        // printf(" %lf\n",b[4]);
mpfr_t A[i];
   for( i=0;i<tailleMatrice;i++){
        mpfr_init(A[i]);
        mpfr_set_d(A[i],matrix[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\n",A[i])     
    }
mpfr_printf("FIRST TERME est : \n %.10Rg\n",A[1]);
 
mpfr_t vect_b[i];
 for (i = 2304; i < 2353; i++){      
        mpfr_init(vect_b[i]);
        mpfr_set_d(vect_b[i],b[i],MPFR_RNDN);
        mpfr_printf("%.10Rg\n",vect_b[i]);   
    }
mpfr_printf("Mon premier élément est : \n %.10Rg\n",vect_b[2309]);

int k = 0,max_iterations;
double tolerance;
int ordre=48;
mpfr_t alpha;
mpfr_init(alpha);

mpfr_t beta;
mpfr_init(beta);

double* x = malloc(ordre*sizeof(double));
mpfr_t x[i];
 for (i = 0; i <ordre ; i++){      
        mpfr_init(x[i]);
        mpfr_set_d(x[i],x[i],MPFR_RNDN);
        
        // mpfr_printf("%.10Rg\n",x[i]);   
                            }

double* s= malloc(ordre*sizeof(double));
mpfr_t s[i];
 for (i = 0; i <ordre ; i++){      
        mpfr_init(s[i]);
        // mpfr_set_d(s[i],s[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\n",x[i]);   
                            }

double* x_prev = malloc(ordre * sizeof(double));

mpfr_t x_prev[i];
 for (i = 0; i <ordre ; i++){      
        mpfr_init(x_prev[i]);
        // mpfr_set_d(x_prev[i],x_prev[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\n",x[i]);   
                            }

double* p = malloc(ordre * sizeof(double));

mpfr_t p[i];
 for (i = 0; i <ordre ; i++){      
        mpfr_init(p[i]);
        mpfr_set_d(p[i],p[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\n",x[i]);   
                            }


double* p_prev = malloc(ordre * sizeof(double));

 for (i = 0; i <ordre ; i++){      
        mpfr_init(p_prev[i]);
        mpfr_set_d(p_prev[i],p_prev[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\n",x[i]);   
                            }

double* r = malloc(ordre * sizeof(double));

 for (i = 0; i <ordre ; i++){      
        mpfr_init(r[i]);
        mpfr_set_d(r[i],r[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\
                           
                            }
double* r_prev = malloc(ordre * sizeof(double));

 for (i = 0; i <ordre ; i++){      
        mpfr_init(r_prev[i]);
        mpfr_set_d(r_prev[i],r_prev[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                            }

double* r_prev_prev = malloc(ordre * sizeof(double));


 for (i = 0; i <ordre ; i++){      
        mpfr_init(r_prev_prev[i]);
        mpfr_set_d(r_prev[i],r_prev_prev[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                            }


double* holderVector = malloc(ordre * sizeof(double));

 for (i = 0; i <ordre ; i++){      
        mpfr_init(holderVector[i]);
        mpfr_set_d(holderVector[i],holderVector[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                            }


/* On copie les valeurs du vecteur b vers   */
for (i = 0; i <ordre ; i++){      
        mpfr_set_d(r[i],vect_b[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                            }

for (i = 0; i <ordre ; i++){      
        mpfr_set_d(r_prev[i],vect_b[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                           }

for (i = 0; i <ordre ; i++){      
        mpfr_set_d(r_prev_prev[i],vect_b[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                        }

 for (i = 0; i < ordre; i++) {
	mpfr_set_d(x[i],0,MPFR_RNDN);    
	
                             }
dotProduct(r, r, ordre); 
while ((k < max_iterations) && r[i] > tolerance){
    // memcpy(r_prev_prev, r_prev, (order * sizeof(double)));


 assigner_valeur_vecteur(r_prev_prev,r_prev,ordre);
 assigner_valeur_vecteur(r_prev,r,ordre);
 assigner_valeur_vecteur(p_prev,p,ordre);
 assigner_valeur_vecteur(x_prev,x,ordre);

 k++;

 if(k==1){

 for (i = 0; i <ordre ; i++){      
    mpfr_set_d(p[i],r_prev[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                           }

 for (i = 0; i <ordre ; i++){      
    mpfr_set_d(p_prev[i],p[i],MPFR_RNDN);
        // mpfr_printf("%.10Rg\                          
                           }
printf("The norm of the residual calculated by the conjugate gradient method: \n");
 }

 if(k!=1){   

 /* BETA_k = [R_(k-1) * R_(k-1)] / [R_(k-2) * R_(k-2)]  */

mpfr_t res;
mpfr_init(res); 

dotProduct(r_prev, r_prev, ordre,res);
dotProduct(r_prev_prev, r_prev_prev, ordre,res);
mpfr_d_div(beta,r_prev,r_prev_prev,MPFR_RNDN);
/* P_k = R_(k-1) + [BETA_k * P_(k-1)] */

scalar_vector( holderVector,s,alpha,ordre);
substact(r,r_prev,holderVector,ordre);

}  

printf("========= System Complet ========= \n");

printf("Solution to the matrix: \n");
		  for (i = 0; i < ordre; i++) {
	     mpfr_printf("%.10Rg\n",x[i]); 
		                                }	  	
// il y trois différentes manières de calculer le gradient 
printf("La norme calculée par le gradient conjuguée est: \n");
mpfr_t norm;
mpfr_init(norm);
mpfr_set_d(norm,0,MPFR_RNDN);
pfr_mynorm2(norm,r, ordre);
}
/* Calculate the residual with the algorithm
	  	 R_k = B - (A * X_k) */

dotProduct(holderVector , matrix,x,ordre);
substact(r,vect_b,holderVector,ordre);

// calculer le gradint pour le résidu 
mpfr_t norm2;
mpfr_init(norm2);
mpfr_set_d(norm2,0,MPFR_RNDN);

pfr_mynorm2(norm2,r,ordre);

/* Libérer tout les espaces alloués aux niveau de la mémoire*/

mpfr_clear_array(matrix,tailleMatrice);
mpfr_clear_array(vect_b,tailleVect);

mpfr_clear_array(x,vect_b);
mpfr_clear_array(s,vect_b);
mpfr_clear_array(p,vect_b);
mpfr_clear_array(r,vect_b);

mpfr_clear_array(x_prev,vect_b);
mpfr_clear_array(p_prev,vect_b);
mpfr_clear_array(r_prev,vect_b);
mpfr_clear_array(r_prev_prev,vect_b);
mpfr_clear_array(holderVector,vect_b);
return 0;

}                          

