// Imagine++ project
// Project:  Mastermind
// Author:   keriven
// Date:     2007/10/16

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


const int nbCases = 5,
          nbCouleurs = 4,
          essaisMax=10;

void genereCombinaison (int combin [ nbCases ] )
{
    for ( int i =0; i <nbCases; ++i )
        combin[i]=rand()%nbCouleurs; // appels au generateur
}

bool VerifInput(int combi[nbCases])
{
    for(int i = 0; i<nbCases; i++)
        if (combi[i] >= nbCouleurs)
        {
            cout << "Entree incorrecte" <<endl;
            return false;
        }
    return true;
}

void Compare(int combIn[nbCases], int combIni[nbCases], int &exact, int &malPlace)
{
    bool indiceExact[nbCases], indiceVerifies[nbCases];
    for(int i=0; i<nbCases; i++)
    {
        indiceVerifies[i] = false;
        indiceExact[i]=false;
    }


    for(int i =0; i<nbCases; i++)
    {
        if (combIn[i]==combIni[i])
        {
            exact++;
            indiceExact[i] = true;
            indiceVerifies[i] = true;
        }
    }
    for(int i=0; i<nbCases; i++)
    {
        if (indiceExact[i]==false)
        {
            for(int j=0; j<nbCases;j++)
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

// Saisie d'une combinaison au clavier
// (5 chiffres tapes a la suite entre 0 et 3)
// Attention: ajouter le controle du nombre codes entres
//            et de leur valeur
void getCombinaison(int combi[nbCases], int essai)
{
    cout << "Essai #"<<essai << " :";
    string s;
    cin >> s;
    for (int i=0;i<nbCases;i++)
        combi[i]=s[i]-'0';
}


void afficheComb(int tab[nbCases],int exact, int malPlace)
{
    for(int i =0; i< nbCases; i++)
        cout << tab[i];
    cout << " : " << exact << "," << malPlace << endl;
}

int main()
{
    cout << "MASTERMIND" << endl << endl;
    cout << "Le MASTERMIND se joue avec " << nbCases<< " cases de " << nbCouleurs << " couleurs et en " << essaisMax << " essais."<< endl <<endl ;
    srand((unsigned int) time(0)); //initialisation

    int exact, malPlace;
    int combSet[nbCases], combIn[nbCases];
    genereCombinaison(combSet);

    for(int essai=0; essai<essaisMax; essai ++)
    {
        do
        {
            getCombinaison(combIn, essai);
        }while (VerifInput(combIn)==false);

        exact= 0;
        malPlace = 0;
        Compare(combIn,combSet,exact, malPlace);
        afficheComb(combIn,exact,malPlace);
        if(exact==nbCases)
        {
            cout << "Vous avez gagne !"<< endl;
            return 0;
        }
    }
    cout << "Vous avez perdu !" << endl;


	return 0;
}
