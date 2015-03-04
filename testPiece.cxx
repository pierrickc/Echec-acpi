/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(Piece p1, Piece p2)
{
  return ( (p1.x()==p2.x()) && (p1.y()==p2.y()) );
}


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  Piece p2(4,4,false);
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );

  // On l'affiche
  p1.affiche();
  p2.affiche();

  if (compare(p1,p2))
    cout << "Pieces meme positions" << endl;
  else
    cout << "Pieces position differentes" << endl;

  p1=p2;

  //Piece tbl[4];

  //Joueur jb(true);
  JoueurBlanc jb;
  //Joueur jn(false);
  JoueurNoir jn;
  jb.affiche();
  jn.affiche();

  Echiquier e;
  jb.placerPieces(e);
  jn.placerPieces(e);
  int i = 0;

  while( i <50){

e.affiche();

jb.unTourBlanc(e);

e.affiche();

jb.unTourNoir(e);

  }














 /* Roi rb(true);
  Roi rn(false);
  Reine qb(true);

  Reine qn(false);


Pion pionB(true, 2);
Pion pionBa(true, 2);
Pion pionBb(true, 2);
Pion pionBc(true, 2);

Pion pionNa(false, 7);
Pion pionNb(false, 7);
Pion pionNc(false,7);
Pion pionNd(false, 7);



   e.affiche();
*/
  /*  int xDepart;
    int yDepart;
    cout <<"choisir les coordonnées de la piece en x"<<endl;
    cin >> xDepart;
    cout <<"choisir les coordonnées de la piece en y"<<endl;
    cin >> yDepart;


    Piece.myCode

    int xArrive;
    int yArrive;
    cout <<"De combien de cases en x voulez vous deplacer la piece"<<endl;
    cin >> xArrive;
    cout <<"De combien de cases en x voulez vous deplacer la piece"<<endl;
    cin >> yArrive;


    //e->getPiece(xDepart,yDepart);
    e.enleverPiece(xDepart,yDepart);*/

/*Cavalier cavNoir(false, false);
Cavalier cavBlanc(true, true);
  Fou fouNoir(false, false);
  Fou fouBlanc(true, true);
  Tour tourBlanche(true, true);
  Tour tourNoir(false, false);


pionBa.mouvementValide(e,4,3 );
pionBa.mouvementValide(e,3,3 );
pionBc.mouvementValide(e,4,5 );

pionNa.mouvementValide(e,5,2 );
pionNb.mouvementValide(e,5,3 );
pionNb.mouvementValide(e,6,3 );
pionNc.mouvementValide(e,6,4 );
pionNd.mouvementValide(e,5,5 );

pionNd.mouvementValide(e,4,5 );
pionNd.mouvementValide(e,3,5 );
pionNc.mouvementValide(e,7,3 );
pionNc.mouvementValide(e,7,5 );



e.deplacer(&pionB, 2, 2);


e.affiche();
*/
/*cout <<" "<<endl;cout <<" "<<endl;
fouBlanc.mouvementValide(e,5,3);
cout <<" "<<endl;cout <<" "<<endl;
fouBlanc.mouvementValide(e,4,3);
cout <<" "<<endl;cout <<" "<<endl;
fouBlanc.mouvementValide(e,4,6);
*/
/*cavBlanc.mouvementValide(e,3,3);
cout <<" "<<endl;
cout <<" "<<endl;cout <<" "<<endl;
cavBlanc.mouvementValide(e,3,1);
cout <<" "<<endl;
cavBlanc.mouvementValide(e,3,2);
cout <<" "<<endl;
cavBlanc.mouvementValide(e,1,3);
cout <<" "<<endl;
cavBlanc.mouvementValide(e,4,1);
cout <<" "<<endl;
cavBlanc.mouvementValide(e,3,6);

cout <<" "<<endl;
cavBlanc.mouvementValide(e,1,4);*/
//fouNoir.mouvementValide(e, 7, 7);


/*e.deplacer(&cavNoir, 6, 6);
e.deplacer(&pionB, 2, 4);
e.affiche();
e.deplacer(&cavNoir, 6, 6);
e.deplacer(&pionB, 2, 4);
e.affiche();


e.deplacer(&pionB, 2, 5);
e.affiche();*/

/*  //rb.roque(); ok
  Piece *pt;
  pt=&rb;
  //pt->roque(); not ok
  Roi *ptr;
  //ptr=pt; not ok
  ptr=dynamic_cast<Roi*>(pt);
  if (pt!=NULL)
    ptr->roque();
  else cout << "cast not ok" << endl;

  e.enleverPiece(5,1);
  e.placer(&rb);
  e.enleverPiece(4,1);
  e.placer(&qb);
  e.enleverPiece(5,8);
  e.placer(&rn);
  e.enleverPiece(4,8);
  e.placer(&qn);*/


  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1






}
