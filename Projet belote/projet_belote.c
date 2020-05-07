#include "projet_belote.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int reponse;

    printf("\n                   Belote\n\n\n");
    printf("Que voulez-vous faire ?\n\n");


    printf("1: Demarrer une nouvelle partie\n2: Afficher les meilleurs scores\n3: Quitter \n\nVotre reponse est: ");
    scanf("%d",&reponse);

    while(reponse != 1 && reponse!= 2 && reponse !=3)
    {
        system("cls");
        printf("\nVeuillez saisir un chiffre entre 1 et 3");
        printf("\n\n1: Demarrer une nouvelle partie\n2: Afficher les meilleurs scores\n3: Quitter \n\nVotre reponse est: ");
        scanf("%d",&reponse);
    }

    system("cls");

    switch(reponse)
    {
    case 1:
        nom();
        break;
    case 2:
        printf("score");
        break;
    default:
        return 0;

    }


}

void nom()
{
    char choix,nom[15];

    printf("Quel est votre nom ?\n");
    scanf("%s",&nom);

    printf("Bonjour %s !",nom);


    printf("Etes vous pret ? O/N \n ");
    choix=getch();

    if(choix == 'O' || choix== 'o')
    {

        printf("debut partie");
    }
    else
    {
        menu();
    }
}


int initialisation_jeu_carte()
{
    char *TabValeur[] = {"As","7", "8", "9", "10", "valet", "dame", "roi"};
    char *TabCouleur[] = {"trefle", "carreau", "coeur", "pique"};


    typedef struct _CARTE_
    {
        int valeur;
        int couleur;
    } CARTE;

    CARTE Jeu[32];
    int gMax;


    void InitJeu()
    {
        int val, coul, i;

        i = 0;

        for (coul=0; coul<=3; coul++)
        {
            for (val=0; val<8; val++)
            {
                Jeu[i].valeur = val;
                Jeu[i].couleur = coul;
                i++;
            }
        }




        CARTE *Distribue(CARTE *pCarte)
        {
            int indice;

            if (gMax)
                indice = rand()%(gMax);
            else
                indice = 0;

            *pCarte = Jeu[indice];


            Jeu[indice] = Jeu[gMax];

            gMax--;
            return pCarte;
        }

int distribution()
        {
            int i;
            CARTE Carte;

            srand(time(0));
            gMax = 31;
            InitJeu();

            char couleur[32];
            char valeur[32];

            for(int i=0; i<32; i++)
            {
                Distribue(&Carte);
                valeur[i]=TabValeur[Carte.valeur];
                couleur[i]=TabCouleur[Carte.couleur];
            }

            printf("%s  de %s",valeur[i],couleur[i]);
          }


