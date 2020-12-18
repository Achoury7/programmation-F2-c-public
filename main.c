#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MONKCVIE 4
#define PISTEUR1V 1
#define PISTEUR2V 1
#define PISTEUR3V 1
#define PISTEUR4V 1
#define PISTEUR5V 1
#define PISTEUR6V 1
#define PISTEUR7V 1
#define PISTEUR8V 1
#define PISTEUR9V 1
#define PISTEUR10V 1
#define PISTEURMORT 0
#define MONKCMORT 0
#define PISTEURDEPLACEMENT 4


//prototypes signatures
void affiche_jeu(char tab [14] [29], int etoile);
void affiche_viecmonk(int nbvie, int nbviemax);
void affiche_pisteur (char tab [10], int pisteurnum);
void affiche_cmonk (char tab [1], int monkc);
void affiche_casesdeppisteur (char tab [3] [3]);
void affiche_visionpisteur (char tab [3] [3] int visionpisteur);
void affiche_tracepasmonkc (char tab [1] [16] );
void affiche_deplacementmonkc (char tab [1] [16]);

/* ------------------------------------------------------------- */


int verif_ttlettres(char *lettres, size_t toutlesletres){
    int lettretrouve = 0;

    if (caracfourni >= 'A' && caracfourni <='Z') {
                trouve = verif_mot(motadev, caracfourni);

toutlesletres[i] = lettretrouve;

    }


    return lettrenontrouve;
    printf("Erreur de verification de caractere");
}

int placementpisteur (char *pisteur , int valeurcase, char tab [2] [2], int tab_verific [26])
{
    printf("Placer votre pisteur numero : %s\n , 4 cases maximum !");
    if valeurcase < 4 {
        pisteur++
    }else
    printf("Vous ne pouvez plus vous deplacer !\n")
}


int visionpisteur (char tab [3] [3]){
    printf("Selectionnez votre pisteur par son numero correspondant")
    scanf("Pisteur selectionné")
   }else{
        ("Ce n'est pas le bon numéro, donnez un autre numéro.")
}



    printf("Vous avez choisi le pisteur numero %s\n" )
 case 1 :
    printf("Pisteur numero %s : Je ne vois pas le monstre mais les traces sont fraiches ! les traces du MONK C sont en %s %s %s\n", visionpisteur);
    break;
 case 2 :
     printf("Je vois le monstre ! En ", monkC "!" , "Je vais tirer ! Appuyez sur ENTREE\n");
     getchar(13);
     printf("Le monstre pert un point de vie !\n")
     MONKCVIE - 1 -> MONKCVIE
    break;
     else
        default printf("Le tir est raté !\n");

     default : ("Il n'y a rien en %s, %s, %s!\n");



int main()  //

{




/*
****************************
*                          *
*                          *
*                          *
*                          *
*                          *
*                          *
****************************
*/


void grille(int Tgrille[14][29])
{

    int ligne, colonne;

        printf("*");
        printf("*");

        for(ligne=0 ; ligne < 14 ; ligne++ ){
            printf("%d",ligne+1);
            for(colonne=0 ; colonne < 29 ; colonne++ ){
                if(Tplateau[ligne][colonne]==0){
                    printf("*");
                }else if(Tplateau[ligne][colonne]==1){
                    printf("*");
                }

            }
            printf("\n");
        }

}

int main() {
        int Tplateau[14][29];

        printf("*");

        plateau(Tgrille);
    }



    char monkC[]     = "M";
    char pisteur[]  = "P";
    char visionpisteur = [3] [3];




/*-----------------------------------------------------------------------------------*/

    if([PISTEUR1V == 0]){
        printf("Le pisteur numéro 1 est mort !" )
    }


      if([PISTEUR2V == 0]){
        printf("Le pisteur numéro 2 est mort !" )
    }


     if([PISTEUR3V == 0]){
        printf("Le pisteur numéro 3 est mort !" )
    }


         if([PISTEUR4V == 0]){
        printf("Le pisteur numéro 4 est mort !" )
    }


         if([PISTEUR5V == 0]){
        printf("Le pisteur numéro 5 est mort !" )
    }


           if([PISTEUR6V == 0]){
        printf("Le pisteur numéro 6 est mort !" )
    }


            if([PISTEUR7V == 0]){
        printf("Le pisteur numéro 7 est mort !" )
    }



            if([PISTEUR8V == 0]){
        printf("Le pisteur numéro 8 est mort !" )
    }


            if([PISTEUR9V == 0]){
        printf("Le pisteur numéro 9 est mort !" )
    }



            if([PISTEUR10V == 0]){
        printf("Le pisteur numéro 10 est mort !" )
    }

    if ([PISTEUR1V], [PISTEUR2V], PISTEUR3V], [PISTEUR4V],
         [PISTEUR5V], [PISTEUR56V}, [PISTEUR7V], [PISTEUR8V],
         [PISTEUR9V], [PISTEUR10V] == 0){
        printf("Vous avez perdu la partie ! Tout vos pisteurs sont morts ! \n");   //
    }


    if (MONKCVIE == 0 && MONKCMORT == 0  )
 }  printf("Vous avez gagne la partie ! Le Monk C est mort ! \n");
    return 0;




}




void affiche_jeu (char tab [14] [29], int taillejeu){
    int i;
        for (i = 0 ; i < taillejeu; i++){
            printf("*", tab[i]);

        }

}
void affiche_viecmonk(int nbvie, int nbviemax){
      printf("(%d/%d) \n", nbvie, nbviemax);
}

void affiche_pisteur(char tab[3] [3], int deplacement){
      for ( int i = 0 ; i < 4 ; i++){
       printf("Tu peux encore te deplacer !\n", tab[4] [i]);
    }
}

void affiche_tracepasmonkc (char tab [1] [16] ){
    int fraicheur = 16
    int tour = 1
        for tour++ {
            fracheur - 1
    printf("Les traces de fraicheur du MONK C s'amenuisent !\n");
    clearprint;
    }
}

void affiche_deplacementmonkc(char tab [1] [16]){
    int deplacementmonkc
        for tab_grille < [14] [29}{
            deplacementmonkc++*
        printf("Le monkc se déplace en " ,tab_grille && deplacementmonkc);
        }
}
