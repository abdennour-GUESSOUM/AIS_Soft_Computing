#ifndef PARAMS_H
#define PARAMS_H

#define  NBVILLES    30
#define COTECARTE    10

/* DANS LA SUITE, NE PAS TOUCHER:
   TAILLEPOP, N, D, NBGENERATIONS, NBGENERATIONSINJECTION !!!
   ==> agir sur les parametres de la ligne de commande                */

#define  TAILLEPOP   100
#define          N   50   /* Selection: En % de TAILLEPOP (Max 100%!) */
#define          D   20   /* Injection: En % de TAILLEPOP (Max 100%!) */

#define  NBGENERATIONS            100
#define  NBGENERATIONSINJECTION    20

#define   NBCLONES  (N*TAILLEPOP)/100
#define NBNOUVEAUX  (D*TAILLEPOP)/100

/*********************************************************************/
/************ Verification contraintes sur les defines ***************/
/*********************************************************************/


#if NBVILLES>COTECARTE*COTECARTE
#error "Attention: NBVILLES>COTECARTE*COTECARTE"
#endif

#if N>100
#error "Attention: N trop grand"
#endif

#if D>100
#error "Attention: D trop grand"
#endif

#define ERROR_PARAM 0
#if TAILLEPOP!=100
#error "Attention: params.h, ne pas toucher TAILLEPOP !"
#error "==> agir sur les parametres de la ligne de commande"
#endif
#if N!=50
#error "Attention: params.h, ne pas toucher N !"
#error "==> agir sur les parametres de la ligne de commande"
#endif
#if D!=20
#error "Attention: params.h, ne pas toucher D !"
#error "==> agir sur les parametres de la ligne de commande"
#endif
#if NBGENERATIONS!=100
#error "Attention: params.h, ne pas toucher NBGENERATIONS !"
#error "==> agir sur les parametres de la ligne de commande"
#endif
#if NBGENERATIONSINJECTION!=20
#error "Attention: params.h, ne pas toucher NBGENERATIONSINJECTION !"
#error "==> agir sur les parametres de la ligne de commande"
#endif


#endif /* PARAMS_H */
