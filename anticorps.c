                           /* anticorps.c : les anti-corps */
#include <stdio.h>
#include <math.h>          /* Pour fabs */
#include <stdlib.h>        /* Pour malloc, free */
#include <string.h>        /* Pour memmove */

#include "params.h"
#include "geo.h"
#include "anticorps.h"
#include "random.h"
#include "gnuplot.h"

extern    Carte carte;     /* Un passage de parametre pas tres joli ! */
                           /* Pour calculCoutAc et dessineParcoursAc  */


/* On utilise NBVILLES (genereAc) */


/**********************************************************************/
/********* Les Anti-corps *********************************************/
/**********************************************************************/
/*
typedef struct { int    parcours[NBVILLES];
                 double cout;
                 int    nbVilles;
               }                            Ac;
*/


/* Generation aleatoire du parcours d'un Anti-Corps */
void genereAc(Ac *ac)
{
 int nbVillesGenerees=0;

 ac->nbVilles = NBVILLES;

 while (nbVillesGenerees!=ac->nbVilles)
 {
   int entier=myRandomMinMax(0,ac->nbVilles-1);
   
   /* Il faut rechercher si l'entier est deja present dans le parcours */

   int i=0,trouve=0;
   for(i=0;i<nbVillesGenerees;i++)
   { 
    if (ac->parcours[i]==entier) trouve=1;
   }
   if (!trouve) ac->parcours[nbVillesGenerees++]=entier;
 }

 calculCoutAc(ac);
}

/* Calcul du cout du parcours d'un Anti-Corps */
void calculCoutAc(Ac *ac)
{
 int i=0;

 const Ville *villeInitiale,*villePrecedente,*villeCourante;

 ac->cout=0.0;

 if (ac->nbVilles==1) return; /* 1 seule ville, cout: 0.0 */

 villeInitiale=&carte.villes[ac->parcours[0]];
 villePrecedente=villeInitiale;

 for(i=1;i<ac->nbVilles;i++)
 {
  villeCourante=&carte.villes[ac->parcours[i]];

  ac->cout+=distanceVilles(villePrecedente,villeCourante);

  villePrecedente=villeCourante;
 }

 if (ac->nbVilles==2) return; /* 2 villes seulement, donc distance
                                 premiere/derniere Ville deja calculee */
 
 ac->cout+=distanceVilles(villePrecedente,villeInitiale);
}

/* Affichage d'un Anti-Corps */
void printAc(const Ac *ac)
{
 printParcoursAc(ac);
 printCoutAc(ac);
}

/* Affichage du parcours d'un Anti-Corps */
void printParcoursAc(const Ac *ac)
{
 int i=0;
 for(i=0;i<ac->nbVilles;i++)
 {
  printf("%d",ac->parcours[i]);
  if (i!=ac->nbVilles-1) printf(" ");
 }
 printf("\n");
}

/* Affichage du cout d'un Anti-Corps */
void printCoutAc(const Ac *ac)
{
 printf("Cout:%f\n",ac->cout);
}

/* Dessin d'un Anti-Corps */
void dessineAc(FILE* flot,const Ac *ac)
{
 dessineParcoursAc(flot,ac);
 printCoutAc(ac);
}
/* Dessin du parcours d'un Anti-Corps */
void dessineParcoursAc(FILE* flot,const Ac *ac)
{
 int    i=0;

 beginPointsToGnuplot(flot,"linespoint");

 for(i=0;i<ac->nbVilles-1;i++)
 {
  vectorGnuplot(flot,
                carte.villes[ac->parcours[i]].x,
                carte.villes[ac->parcours[i]].y,
                carte.villes[ac->parcours[i+1]].x,
                carte.villes[ac->parcours[i+1]].y);
 }
 
 vectorGnuplot(flot,
               carte.villes[ac->parcours[ac->nbVilles-1]].x,
               carte.villes[ac->parcours[ac->nbVilles-1]].y,
               carte.villes[ac->parcours[0]].x,
               carte.villes[ac->parcours[0]].y);

 endPointsToGnuplot(flot);
}

/* Clonage d'un Anti-Corps */
void cloneAc(const Ac *ac,Ac *nouvelAc)
{
 /* *nouvelAc=*ac; */

 nouvelAc->cout     = ac->cout;
 nouvelAc->nbVilles = ac->nbVilles;
 memmove(nouvelAc->parcours,ac->parcours,ac->nbVilles*sizeof(int));
}

/* Mutation d'un Anti-Corps */
void muteAc(Ac *ac,int nbMutations)
{
 (void)ac; (void)nbMutations;
 for(int i = 0;i<nbMutations;i++){
  // code d'une transformation
  int random1 = myRandomMinMax(0,ac->nbVilles-1);
  int random2 = myRandomMinMax(0,ac->nbVilles-1);

  while(random1 ==random2){
    random2 = myRandomMinMax(0,ac->nbVilles-1);
  }
  printf("Ac intial : %d %d\n", ac->parcours[random1], ac->parcours[random2]);

  int temp;
  temp = ac->parcours[random1];
  ac->parcours[random1] = ac->parcours[random2];
  ac->parcours[random2] = temp;
  printf("Ac muté : %d %d\n", ac->parcours[random1], ac->parcours[random2]);
 }
 calculCoutAc(ac);
}
