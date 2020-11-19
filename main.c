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

static int init();
static int viejoueur();
static int motadev();


/* determine le nombre de lettres trouvées*/
int verif_mot(char *mot, char lettre, size_t TailleMotEtZonePendue, char *zonependue){
    int lettretrouve = 0;
    for (int i = 0; i < TailleMotEtZonePendue; i++){
      /* si on a trouve la lettre dans le mot */
        if(mot[i] == lettre){
           /* on remplit notre sone de pendu*/
            zonependue[i] = lettre;
            /* on augement le compteur de lettre trouves*/
            lettretrouve++;
        }
    }


    return lettretrouve;
}

static int zonependueincomplete(char *zonependue, size_t TailleMotEtZonePendue)
{
  int incomplete = 0;
  if (zonependue==NULL) {// Safegard en cas de chaîne vide
    return 0;
  }


  for (int i =0; i < TailleMotEtZonePendue; i++) {
      if (zonependue [i] == '-') {
          incomplete = 1;
      }
  }
  return incomplete;
}

int main()  //Initialisation du jeu

{

    char motadev[]     = "BONJOUR";
    char zonependue[]  = "-------";

    char caracfourni = '\0';

    int nombredevies = 10;
    int const nombredeviesmax = 10;

    size_t TailleMotEtZonePendue = strlen(motadev);
    if(TailleMotEtZonePendue>TAILLEMOTMAX){
        TailleMotEtZonePendue=TAILLEMOTMAX;
    }


    while (nombredevies > 0 && zonependueincomplete (zonependue, TailleMotEtZonePendue)){
        printf("Donnez moi une lettre majuscule :\n ");
        scanf ("%c", &caracfourni);
        int trouve = 0;


            if (caracfourni >= 'A' && caracfourni <='Z') {
                trouve = verif_mot(motadev, caracfourni, TailleMotEtZonePendue, zonependue);
        }

    if (motadev == 0) nombredevies--;

    }

    printf("(%d/%d) %s\n", nombredevies, nombredeviesmax, zonependue);
    return 0;
}



