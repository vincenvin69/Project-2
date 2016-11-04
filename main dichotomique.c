#include <stdio.h>
#include <stdlib.h>


int rechercheDicho(int [], int, int);  //prototype de la fonction de recherche dichotomique

int main()
{
  /* on d�clare un tableau d'entiers que l'on initialise avec 8 entiers rang�s par ordre croissant */
  int tab[10] = {12, 14, 20, 25, 26, 28, 35, 99};
  int nbVal = 8;  //nombre de valeurs stock�es dans le tableau "tab[]"
  
  /* on demande la valeur que l'utilisateur veut rechercher dans le tableau */
  int val;  //variable stockant la valeur � rechercher dans le tableau
  cout << "Quelle valeur voulez-vous rechercher ?" << endl;
  cin >> val;
  
  /* on appelle la fonction de recherche dichotomique et on affiche le r�sultat  */
  int indiceRetourne = rechercheDicho(tab, nbVal, val);

  if(indiceRetourne != -1) cout << "Votre valeur est a l'indice : " << indiceRetourne << endl;
  else cout << "Votre valeur n'est pas dans le tableau." << endl;


  return 0;
}

/* fonction de recherche dichotomique qui renvoie un indice o� se trouve la valeur "val" s'il est dans le tableau "tab[]" et -1 si cette valeur n'y est pas */
int rechercheDicho(int tab[], int nbVal, int val){

  /* d�claration des variables locales � la fonction */
  bool trouve;  //vaut faux tant que la valeur "val" n'aura pas �t� trouv�e
  int id;  //indice de d�but
  int ifin;  //indice de fin
  int im;  //indice de "milieu"
  
  /* initialisation de ces variables avant la boucle de recherche */
  trouve = false;  //la valeur n'a pas encore �t� trouv�e
  id = 0;  //intervalle de recherche compris entre 0...
  ifin = nbVal;  //...et nbVal
  
  /* boucle de recherche */
  while(!trouve && ((ifin - id) > 1)){

    im = (id + ifin)/2;  //on d�termine l'indice de milieu
    
    trouve = (tab[im] == val);  //on regarde si la valeur recherch�e est � cet indice
    
    if(tab[im] > val) ifin = im;  //si la valeur qui est � la case "im" est sup�rieure � la valeur recherch�e, l'indice de fin "ifin" << devient >> l'indice de milieu, ainsi l'intervalle de recherche est restreint lors du prochain tour de boucle
    else id = im;  //sinon l'indice de d�but << devient >> l'indice de milieu et l'intervalle est de la m�me fa�on restreint
  }
  
  /* test conditionnant la valeur que la fonction va renvoyer */
  if(tab[id] == val) return(id);  //si on a trouv� la bonne valeur, on retourne l'indice
  else return(-1);  //sinon on retourne -1
  
}

