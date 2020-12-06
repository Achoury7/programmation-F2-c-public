#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define B_PORTE_AVION 5
#define B_CROISEUR 4
#define B_CONTRE_TORPILLEUR 3
#define B_SOUS_MARIN 3
#define B_TORPILLEUR 2
#define C_EAU 0
#define C_EAU_T 1 //Bateau touché
#define C_BAT_T 2 //Bateau "en vue"
#define TAILLE_GRILLE 10

//Prototypes
// Couleur de la grille
const char line[] = "  +---+---+---+---+---+---+---+---+---+---+",
EAU[] = "   |",
EAU_T[] = ANSI_COLOR_BLUE " X " ANSI_COLOR_RESET "|",
BAT[] = ANSI_COLOR_GREEN "***" ANSI_COLOR_RESET "|",
BAT_T[] = ANSI_COLOR_RED "XXX" ANSI_COLOR_RESET "|";


typedef struct {
                                                    // 1 porte-avion (5 cases),
                                                      //1 croiseur (4 cases),
                                                      //1 contre torpilleur (3 cases),
                                                      //1 sous-marin (3 cases),
                                                     // 1 torpilleur (2 cases),

	 // Cases restantes pour les bateaux
	int porteAvion, croiseur, contreTorpilleur, sousMarin, torpilleur, points;
	int grille[TAILLE_GRILLE][TAILLE_GRILLE];
	int grilleEnnemie[TAILLE_GRILLE][TAILLE_GRILLE];
} Plateau;

typedef struct {
	int x, y;
	char d;
} Coordonnees;

Coordonnees strToCoord(char string[], int aDirection) {
	Coordonnees c;
	char strX[2 + 1];
	int i;

	// Pour permettre de faire la direction du bateau
	if (aDirection > 0) {
		aDirection = 1;
		c.d = string[strlen(string) - 1];
	}
	else {
		aDirection = 0;
	}

	// Pour couper le charactere

	c.y = string[0] - 'a';
	for (i = 0; i < strlen(string) - (1 + aDirection); i++) {
		strX[i] = string[i + 1];
	}
	for (i + 1; i < strlen(strX); i++) {
		strX[i] = '\0';
	}

	c.x = strtol(strX, NULL, 10) - 1;    //Cette fonction, signifiant ,"string to long", permet de transformer une chaîne de caractères, en un entier type long.

	return c;
}

//  Initialise un plateau vierge qui retourne un Plateau initialisé

Plateau initPlateau() {
	Plateau p;
	int i, j;
	* contreTorpilleur = B_CONTRE_TORPILLEUR;
	* croiseur = B_CROISEUR;
	* porteAvion = B_PORTE_AVION;
	* sousMarin = B_SOUS_MARIN;
	* torpilleur = B_TORPILLEUR;
	* points = 0;

	for (i = 0; i < TAILLE_GRILLE; i++) {
		for (j = 0; j < TAILLE_GRILLE; j++) {
			* grille[i][j] = C_EAU;
		}
	}

	return p;
}

//Ce code affiche une grille de jeu
void afficherGrille(int g[TAILLE_GRILLE][TAILLE_GRILLE]) {
	int i, j;


	puts("\n  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|");
	puts(line);
	for (i = 0; i < TAILLE_GRILLE; i++) {
		printf("%c |", i + 'A');
		for (j = 0; j < TAILLE_GRILLE; j++) {
			if ((int)g[i][j] == C_EAU) { // Le tir est dans l'eau
				printf("%s", C_EAU);
			}
			else if (g[i][j] == C_EAU_T) { // Le tir est touché
				printf("%s", C_EAU_T);
			}
			else if (
				g[i][j] == B_PORTE_AVION ||
				g[i][j] == B_CROISEUR ||
				g[i][j] == B_CONTRE_TORPILLEUR ||
				g[i][j] == B_SOUS_MARIN ||
				g[i][j] == B_TORPILLEUR
				) {
				printf("%s", BAT);
			}
			else {
				printf("%s", BAT_T);
			}
		}
		printf("\n");
	}
}



int CompPlateau(Plateau p) {
	return * contreTorpilleur + * croiseur + * porteAvion + * sousMarin + * torpilleur;
}



//Ce code permet de placer un bateau dans la grille
Plateau placerBat(Plateau p, char nom[], int taille, int val) {
	int done, error, i;
	Coordonnees c;
	char pos[4 + 1], // Coordonnées
		orientation[10 + 1],
		reponse;

	afficherGrille(* grille);

	printf("Pour placer un bateau, donnez les coordonées de la case de destination, puis\n"
		"son orientation (h/v). Les bateaux seront positionnés sur la droite de\n"
		"la case donnée pour les placements horizontaux, et vers le base pour les \n"
		"placements verticaux. Exemple : a10v\n\n");
	printf("Veuillez placer le %s (%i cases)\n\n", nom, size);
	do {
		// Re-inititialisation des valeurs
		error = 0;
		done = 0;
		strcpy(orientation, "horizontal");

		// Pour demander les coordonées du bateau (vis a vis de la position)
		printf("Position : ");
		scanf("%s", pos);

		c = strToCoord(pos, 1);


		if (c.x < 0 || c.y < 0 || c.x > TAILLE_GRILLE || c.y > TAILLE_GRILLE) {
			printf(" > Mauvaises coordonnées...");
			error = 1;
		}
		else if (c.d == 'v') {// Vérification placement des bateaux
			strcpy(orientation, "vertical");
			// Sortie de carte
			if (c.y + taille > TAILLE_GRILLE) {
				printf(" > Vous ne pouvez pas placer votre bateau ici. Il sortirait de la carte...(y=%i)\n", c.y);
				error = 1;
			}
			else {
				// Ce code gere les chevauchements entre deux bateaux. (En coordonnée Y)
				for (i = c.y; i < c.y + taille; i++) {
					if (p.grille[i][c.x] != C_EAU) {
						puts(" > Il y a déjà un bateau ici...");
						error = 1;

						break;
					}
				}
			}
		}
		else if (c.x + taille > TAILLE_GRILLE) {
			printf(" > Vous ne pouvez pas placer votre bateau ici. Il sortirait de la carte...(x=%i)\n", c.x);
			error = 1;
		}
		else {
			// Ce code gere les chevauchements entre deux bateaux.(En coordonnée X)
			for (i = c.x; i < c.x + taille; i++) {
				if (p.grille[c.y][i] != C_EAU) {
					puts(" > Il y a déjà un bateau ici...");
					error = 1;

					break;
				}
			}
		}

		if (error == 0) {
			getchar();
			printf("Placement %s en %c:%i. Est-ce correct ? [o/N] ", orientation, c.y + 'a', c.x + 1);
			reponse = getchar();
			if (reponse == 'o' || reponse == 'O') {
				done = 1;
			}
		}
	} while (done == 0);





//Procedure principale
int main() {
	 // Génération de la grille
	Plateau plateau = initPlateau();

	printf("Placement de vos bateaux\n");

	// Placement des bateaux
	plateau = placerBat(plateau, "porte avions", B_PORTE_AVION, C_PORTE_AVION);
	plateau = placerBat(plateau, "croiseur", B_CROISEUR, C_CROISEUR);
	plateau = placerBat(plateau, "contre-torpilleur", B_CONTRE_TORPILLEUR, C_CONTRE_TORPILLEUR);
	plateau = placerBat(plateau, "sous-marin", B_SOUS_MARIN, C_SOUS_MARIN);
	plateau = placerBat(plateau, "torpilleur", B_TORPILLEUR, C_TORPILLEUR);




}
