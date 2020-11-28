#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VIE 10
#define TAILLEMOTMAX 8
#define MORT 0



/* FEATURES
    Mettre en place un mot a deviner
    Nombre de pdv au joueur : 10
    Jeu lui meme: tentative au joueur de mettre une lettre
    Condition de victoire : deviner le mot en entier, lettres par lettres
    Condition de défaite :  pendu!
     */

//prototypes signatures
void affiche_pendu(char tab [] [65], int nbvie);                                           //Ces trois types void permet d'afficher a chaque
void affiche_vie(int nbvie, int nbviemax);                                                 //iteration, le nombre de vies restants, le nombre
void affiche_mot_pendue (char tab [], int n_taille);                                       //de vies maximum et le mot pendu.

/* ------------------------------------------------------------- */


int verif_mot(char *mot, char lettre, size_t TailleMotEtZonePendue, char *zonependue){    //On determine le nombre de lettres trouvées
    int lettretrouve = 0;
    for (int i = 0; i < TailleMotEtZonePendue; i++){                                      // Si on a trouve la lettre dans le mot, alors...
        if(mot[i] == lettre){

            zonependue[i] = lettre;                                                       //on remplit notre zone de pendu et...

            lettretrouve++;                                                               //...on augement le compteur de lettres trouvés , ps: == est un test.
        }
    }


    return lettretrouve;
}

int zonependueincomplete(char *zonependue, size_t TailleMotEtZonePendue)         //On definit la taille de la zone pendue et on la stocke dans
{                                                                                //une adresse (Ajout pointeur pour la zone pendue)
  int incomplete = 0;
  if (zonependue==NULL) {                                                        // Ce code permet une sortie du programme si il y'a une erreur.  //NULL est pour la réference.
    return 0;
  }


  for (int i =0; i < TailleMotEtZonePendue; i++) {
      if (zonependue [i] == '-') {                                              //On affiche la zone pendue avec le caractere '-' (lettres non trouvées)
          incomplete = 1;
      }
  }
  return incomplete;
}



int main()  //Initialisation du jeu
{

int tab_verific [26];       // Ajout d'un tableau comprenant l'alphabet en entier (26 lettres)



/*
   ----|
   |   |
   O   |
  /|\  |
   |   |
  / \  |
==========
*/
                                                                                     //11 Lignes et 65 caracteres au total (pour le code)
                                                                                     //On realise l'affichage du pendu, ligne par ligne.
    char tab_pendu [11] [65] = {                                                     //58 caracteres totaux de pendu + 7 retours a la ligne
"   ----|\n   |   |\n   O   |\n  /|\\  |\n   |   |\n  / \\  |\n==========\n",        //Ajout de la jambe droite            (MORT)
"   ----|\n   |   |\n   O   |\n  /|\\  |\n   |   |\n    \\  |\n==========\n",        //Ajout de la jambe gauche            (1 vies)
"   ----|\n   |   |\n   O   |\n  /|\\  |\n   |   |\n       |\n==========\n",         //Ajout du bras gauche                (2 vies)
"   ----|\n   |   |\n   O   |\n   |\\  |\n   |   |\n       |\n==========\n",         //Ajout du bras droit                 (3 vies)
"   ----|\n   |   |\n   O   |\n   |   |\n   |   |\n       |\n==========\n",          //Ajout du corps                      (4 vies)
"   ----|\n   |   |\n   O   |\n       |\n       |\n       |\n==========\n",          //Ajout de la tete                    (5 vies)
"   ----|\n   |   |\n       |\n       |\n       |\n       |\n==========\n",          //Ajout du poteau horizontal et corde (6 vies)
"       |\n       |\n       |\n       |\n       |\n       |\n==========\n",          //Ajout du poteau verticale           (7 vies)
"        \n        \n        \n        \n        \n        \n==========\n",          //Renforcement du sol                 (8 vies)
"        \n        \n        \n        \n        \n        \n----------\n",          //Construction du sol                 (9 vies)
"        \n        \n        \n        \n        \n        \n          \n"           //Rien n'est affiché                 (10 vies)
};



    char motadev[]     = "BONJOUR";
    char zonependue[]  = "-------";
    int lng = strlen(motadev);

    char caracfourni = '\0';

    int nombredevies = 10;

    int const nombredeviesmax = 10;

    size_t TailleMotEtZonePendue = strlen(motadev);                                 //Tant que le mot nest pas trouvé, on affiche le pendu
    if(TailleMotEtZonePendue>TAILLEMOTMAX){                                         //et on le limite a la TAILLEMOMAX, c'est a dire 8. (7+1)
        TailleMotEtZonePendue=TAILLEMOTMAX;
    }

        affiche_mot_pendue(zonependue, strlen(zonependue));
    while (nombredevies > 0 && zonependueincomplete (zonependue, TailleMotEtZonePendue)){



        printf("\nDonnez moi une lettre majuscule :\n ");
        scanf ("%c", &caracfourni); // On remplace le "/0" par le caractere fourni par l'utilisateur
        fflush (stdin);
        int trouve = 0;

            if (caracfourni >= 'A' && caracfourni <='Z') {  //Ecrasement du caractere precedent par le nouveau
                trouve = verif_mot(motadev, caracfourni, TailleMotEtZonePendue, zonependue);  //On delimite l'utilisateur aux lettres majuscules seulement.
        }



    if (trouve == 0) {
        nombredevies--;
        printf("Vous avez perdu une vie ! \n");   //Si l'utilisateur se trompe, il perd une vie.



    if (nombredevies<=0){
    printf("Vous avez perdu la partie ! \n");     // Si l'utilisateur n'a plus de vies, il a perdu la partie.
}
    }else{

    printf("Vous avez trouve la lettre %c\n", caracfourni);         //Sinon, une lettre est ajoutée au pendu.

    }






       affiche_pendu(tab_pendu, nombredevies);
       affiche_mot_pendue(zonependue, TAILLEMOTMAX);
       affiche_vie(nombredevies, nombredeviesmax);                          //Affiche_vie fait le lien entre nombredevies et nbvie (par exemple)
 }  printf("Vous avez gagne la partie ! \n");                               //Ceci s'affiche lorsque le joueur a trouvé toutes les lettres
    return 0;




}





void affiche_mot_pendue (char tab [], int n_taille){                        //Afficher le mot pendue
    int i;
        for (i = 0 ; i < n_taille; i++){
            printf("%c", tab[i]);

        }

}
void affiche_vie(int nbvie, int nbviemax){
      printf("(%d/%d) \n", nbvie, nbviemax);                               //Affichage du systeme de vie
}

void affiche_pendu(char tab[] [65], int nbvie){
      for ( int i = 0 ; i < 65 ; i++){
       printf("%c", tab[nbvie] [i]);                                      //Affichage d'abord, du pendu
    }
}



