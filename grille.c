#include "tete.h"
//

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
}

void affichage(char mots[20],char motsSug[20], int nombreLettre,int numJoueur)
{
    int l=0;

    //affichage
    if(numJoueur!=0)
    {
        printf("Joueur %d\n",numJoueur);
    }

    for(int i=0;i<nombreLettre;i++)
    {
        printf(" ---");
        if(i==nombreLettre-1)
        {
            printf("\n");
            printf("|");
        }
    }
    for(int k=0;k<nombreLettre;k++)
        {
            l=1;
            if(mots[k]==motsSug[k]) //si la lettre k de motsSug est est dans mots et a la bonne place
            {
                setColor(10);
                printf(" %c ",motsSug[k]);
                l++;
            }
            else //si la lettre k de motsSug est dans mots mais pas a la bonne place
            {
                for(int j=0; j<nombreLettre; j++)
                {
                    if(motsSug[k]==mots[j])
                    {
                        setColor(14);
                        printf(" %c ",motsSug[k]);
                        l+=2;
                        break;
                    }
                }

            }

            if(l==1 && ((65<=motsSug[k] && motsSug[k]<=90) || (97<=motsSug[k] && motsSug[k]<=122))) // si la lettre k de motsSug n'existe pas dans mots
            {
                setColor(12);
                printf(" %c ",motsSug[k]);
            }
            else // si le contenu de motsSug a la position k n'est pas une lettre
            {
                if(l==1)
                {
                    printf(" - ");
                }
            }
            setColor(15);
            printf("|");
        }
        printf("\n");

    for(int k=0;k<nombreLettre;k++)
    {
        printf(" ---");
    }
    printf("\n");

}
