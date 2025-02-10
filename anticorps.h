                           /* anticorps.h : les anti-corps */
#ifndef ANTICORPS_H
#define ANTICORPS_H

#include "params.h"

/*
  Dans anticorps.c, il y a un passage de parametre pas tres joli!

  extern  Carte carte; (calculCoutAc, dessineParcoursAc)
*/

/* On utilise NBVILLES (genereAc) */


/**********************************************************************/
/********* Les Anti-corps *********************************************/
/**********************************************************************/

typedef struct { int    parcours[NBVILLES];
                 double cout;
                 int    nbVilles;
               }                            Ac;

extern void genereAc(Ac *ac);
extern void calculCoutAc(Ac *ac);
extern void printAc(const Ac *ac);
extern void printParcoursAc(const Ac *ac);
extern void printCoutAc(const Ac *ac);
extern void dessineAc(FILE* flot,const Ac *ac);
extern void dessineParcoursAc(FILE* flot,const Ac *ac);
extern void cloneAc(const Ac *ac,Ac *nouvelAc);
extern void muteAc(Ac *ac, int nbMutations);
extern void echange(Ac *ac,int nbMutations);
extern void inversion(Ac *ac,int nbMutations);
extern void translation(Ac *ac,int nbMutations);
#endif /* ANTICORPS_H */
