// Imagine++ project
// Project:  Mastermind Graphique
// Author:   keriven
// Date:     2007/10/16

#include<iostream>
using namespace std;

#include<Imagine/Graphics.h>
using namespace Imagine;

// Parametres du jeu
const int nbcases = 5;		// nombre de pions a deviner
const int nbcoul = 6;		// nombre de types de pions
const int nbessais = 10;	// nombre d'essais pour trouver la combinaison

const int ncmax = 7;		// nombre maximal de couleurs disponibles

/////////////////////////////////////////////////////////////////////////
// Fonctions d'affichage

Color couleurs[ncmax+1]={RED,GREEN,BLUE,YELLOW,MAGENTA,CYAN,BLACK,WHITE};
char touche_couleurs[ncmax+1]={'r','v','b','j','m','c','n',' '};
const int c_size = 24;
const int ecart = 10;

// Affichage d'un curseur indiquant le prochain pion a saisir
void afficheSaisie(int n, int ligne, Color c)
{
	drawCircle(n*c_size+c_size/2,ligne*c_size+c_size/2,c_size/2,c);
}

// Affichage d'un combinaison
void afficheCombinaison(int combi[nbcases], int ligne)
{
	for (int i=0; i<nbcases; ++i)
		fillCircle(i*c_size+c_size/2,ligne*c_size+c_size/2,
                   c_size/2,couleurs[combi[i]]);
}

// Affichage des indices
void afficheIndices(int bienplaces, int malplaces, int ligne)
{
	for (int i=0; i<bienplaces; ++i)
		fillCircle(nbcases*c_size+ecart+i*c_size/2+c_size/4,
                   ligne*c_size+c_size/2,c_size/4,BLACK);
	for (int i=0; i<malplaces; ++i)
		drawCircle(nbcases*c_size+ecart+(bienplaces+i)*c_size/2+c_size/4,
                   ligne*c_size+c_size/2,c_size/4,BLACK);
}

// Affichage d'un trait horizontal de separation
void afficheSeparation(int ligne)
{
	drawLine(0,(2*ligne+1)*c_size/2,500,(2*ligne+1)*c_size/2,BLACK);
}

// Affichage d'un mini mode d'emploi recapitulant quelle touche
// correspond a quelle couleur
void afficheTouches(int ligne)
{
	char c[2] = {0,0};
	for (int i=0; i<nbcoul; ++i){
		fillCircle(i*c_size+c_size/2,ligne*c_size+c_size/2,
                   c_size/2,couleurs[i]);
		c[0] = touche_couleurs[i];
        drawString(i*c_size,(ligne+1)*c_size+c_size/2,c,BLACK);
	}
}

//////////////////////////////////////////////////////////////////////////
// Fonction de gestion du clavier
int Clavier()
{
	// Renvoie une couleur entre 0 et nbcoul-1,
	// -1 pour signifier un retour en arriere d'une case
	// -2 pour une mauvaise touche
	int k = getKey();
	if (k==KEY_BACK) // Backspace
		return -1;
	for (int i=0;i<nbcoul;i++)
		if (k==touche_couleurs[i] || k==touche_couleurs[i]-'a'+'A')
			return i;
	return -2; // Mauvaise touche
}

//////////////////////////////////////////////////////////////////////////
// Fonctions Mastermind

// Genration aleatoire d'une combinaison
void genereCombinaison (int combin [ nbcases ] )
{
    for ( int i =0; i <nbcases; ++i )
        combin[i]=rand()%nbcoul;
}
//
//

void getCombinaison(int combi[nbcases], int ligne)
{
    int k=0;
	for (int j=0; j<nbcases; ++j)
		combi[j]=ncmax;
    while (k<nbcases){
        afficheSaisie(k,ligne,Color(160,160,160));
		int c;
        do {
			c = Clavier();
        }
        while (c==-2);
        if (c==-1)
        {
            afficheSaisie(k,ligne,WHITE);
            if (k>0)
                k--;
            combi[k]=ncmax;
            afficheCombinaison(combi,ligne);
        }
        else
        {
            combi[k]=c;
            afficheSaisie(k,ligne,WHITE);
            afficheCombinaison(combi,ligne);
            k++;
        }
    }
}


// Comparaison de deux combinaisons
void Compare(int combIn[nbcases], int combIni[nbcases], int &exact, int &malPlace)
{
    bool indiceExact[nbcases], indiceVerifies[nbcases];
    for(int i=0; i<nbcases; i++)
    {
        indiceVerifies[i] = false;
        indiceExact[i]=false;
    }


    for(int i =0; i<nbcases; i++)
    {
        if (combIn[i]==combIni[i])
        {
            exact++;
            indiceExact[i] = true;
            indiceVerifies[i] = true;
        }
    }
    for(int i=0; i<nbcases; i++)
    {
        if (indiceExact[i]==false)
        {
            for(int j=0; j<nbcases;j++)
            {
                if(indiceVerifies[j]==false)
                {
                    if(combIn[i]==combIni[j])
                    {
                        indiceVerifies[j]= true;
                        malPlace ++;
                        break;
                    }
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// Fonction principale

int main()
{
    // On genere une combinaison
    int combSet[nbcoul];
    srand((unsigned int) time(0));
    genereCombinaison(combSet);


	// Initialisation de l'affichage
	int width = nbcases*c_size + ecart + nbcases*c_size/2;
	int height = (nbessais+6)*c_size;
	openWindow(width,height,"Master Mind");
    afficheSeparation(nbessais+1);
	afficheSeparation(nbessais+3);
	afficheTouches(nbessais+4);

	// Affichage de la solution pour debuggage
	// afficheCombinaison(,nbessais+1);
    // afficheCombinaison(combSet, nbessais+1);

	// Jeu
	bool trouve=false;
    int essai=0;
    int tentative[nbcases];
    int exact,
        malPlace;


    while((essai<=nbessais) && (trouve==false))
    {
        exact=0;
        malPlace=0;

        getCombinaison(tentative,essai);
        Compare(tentative,combSet,exact,malPlace);
        afficheIndices(exact,malPlace,essai);

        if(exact == nbcases)
        {
            trouve = true;
        }

        essai++;
    }

	if (trouve)
        drawString(0,(nbessais+3)*c_size," GAGNE",RED);
	else
        drawString(0,(nbessais+3)*c_size," PERDU",RED);
	endGraphics();
	return 0;
}
