#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>

using namespace Imagine;
using namespace std;

typedef Image<byte> Img;

int max(int tab[256]){
    int compte=tab[0];
    for (int i=0; i<256; i++){
        if (tab[i]>compte)
            compte=tab[i];
    }
    return compte;
}

int max(int a, int tab[256]){
    int compteur = max(tab);
    if (a<compteur)
        return compteur;
    return a;

}

int main()
{
	// Img est un type representant une image et img est le nom de la variable
	Img img;
    int nvGris[256];
    for (int i=0; i<256; i++)
        nvGris[i]=0;

	if (!load(img,srcPath("lena.png"))) // Stop si l'image n'est pas chargee
		return 0;

    for(int i=0; i<img.width();i++){
        for(int j=0; j<img.height();j++){
            nvGris[int(img(i,j))]++; //comptage des pixels
        }
    }

    openWindow(img.width() + 400, img.height());
    display(img);

    // Niveau de gris (entre 0 et 255) du pixel en haut a gauche
    // On recupere les valeurs des pixels en faisant comme si img etait une
    // function definie ainsi: byte img(int x, int y);
    double ratio = double(max(nvGris))/img.height();

    for(int i=0; i<256;i++){
        fillRect(img.width()+i+50,img.height()-1,1,-nvGris[i]/ratio, RGB<double> (i,i,i));
    }

	endGraphics(); // En realite, on n'arrive jamais ici...
	return 0;
}
