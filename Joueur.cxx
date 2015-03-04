#include <iostream>
#include "Joueur.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

Joueur::Joueur()
{
  //cout << "Constructeur Joueur" << endl;
}

Joueur::~Joueur()
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      delete *p;
      p++;
    }
  //cout << "Destructeur Joueur" << endl;
}

Joueur::Joueur(bool white)
{
  cout << "Constructeur Joueur specialise" << endl;
  /*
  int n = 0;
  int y = white ? 1 : 8;
  for ( int x = 1; x <= 8; ++x )
    m_pieces[ n++ ].init( x, y, white );
  y = white ? 2 : 7;
  for ( int x = 1; x <= 8; ++x )
    m_pieces[ n++ ].init( x, y, white );
  */
}

void
Joueur::placerPieces(Echiquier &e)
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      e.placer((Piece*)*p);
      p++;
    }
  /*
  for (int i=0;i<16;i++)
    e.placer(m_pieces+i);
  */
}

/*
bool
Joueur::isWhite()
{
  return m_pieces[0].isWhite();
}
*/
bool
verifCoord(int x, int y)
{
       if((x ||y) > 8 || (x ||y) < 1)
    {

        return false;
    }
    return true;
}
bool
verifPiece(Echiquier &e, int x, int y)
{
if(e.getPiece( x,y) != NULL){
  return true;
    }
    return false;

}

void
Joueur::unTourBlanc(Echiquier &e)
{
    cout <<"Tour joueur Blanc"<<endl;
    bool color = false;
    int xDepart;
    int yDepart;
    cout <<"x coordonnée horizontal"<<endl;
    cout <<"x coordonnée vertical"<<endl;

    int xArrive;
    int yArrive;
    cout <<"choisir les coordonnées de la piece que vous voulez déplacer en x"<<endl;
    cin >> xDepart;
    cout <<"choisir les coordonnées de la piece que vous voulez déplacer en  en y"<<endl;
    cin >> yDepart;
    verifCoord(xDepart,yDepart );
    if(e.getPiece(xDepart,yDepart)->isWhite() == true)
    {
    color = true;
    }
    while((verifPiece(e, xDepart,yDepart) || color )== false )
    {
        cout <<"coordonnées de la piece Invalide"<<endl;
        cout <<"choisir une coordonnée de la piece en x valide "<<endl;
        cin >> xDepart;
        cout <<"choisir une coordonnée de la piece en y valide "<<endl;
        cin >> yDepart;
        verifPiece(e, xDepart,yDepart);
    }

    cout <<"choisir la coordonnée du déplacement de la piece en x"<<endl;
    cin >> xArrive;
    cout <<"choisir la coordonnée du déplacement de la piece en y"<<endl;
    cin >> yArrive;

    verifCoord(xDepart,yDepart );
    while(verifCoord(xArrive,yArrive) == false)
    {
        cout <<"choisir une coordonnée du déplacement de la piece en x valide "<<endl;
        cin >> xArrive;
        cout <<"choisir une coordonnée du déplacement de la piece en y valide"<<endl;
        cin >> yArrive;
        verifCoord(xArrive,yArrive);
    }

        while(e.getPiece(xDepart, yDepart)->mouvementValide(e, xArrive, yArrive) == false)
        {
            cout <<"Deplacement non possible  Invalide"<<endl;
        cout <<"choisir une coordonnée pour un mouvement possible en x"<<endl;
        cin >> xArrive;
        cout <<"choisir une coordonnée pour un mouvement possible  en y"<<endl;
        cin >> yArrive;
        verifCoord(xArrive,yArrive);
        }
    if(e.getPiece(xDepart, yDepart)->mouvementValide(e, xArrive, yArrive)){
        if(e.getPiece(xArrive, yArrive) !=NULL)
        {
            e.getPiece(xDepart, yDepart)->mange(e, true, xArrive, yArrive);
            cout <<"Vous avez mangé une piece adverse"<<endl;

        }

    e.deplacer(e.getPiece(xDepart, yDepart),xArrive, yArrive);


    }
}


 void
Joueur::unTourNoir(Echiquier &e)
{
    cout <<"Tour joueur Noir"<<endl;
    bool color = false;
    int xDepart;
    int yDepart;

    int xArrive;
    int yArrive;
    cout <<"choisir les coordonnées de la piece en x"<<endl;
    cin >> xDepart;
    cout <<"choisir les coordonnées de la piece en y"<<endl;
    cin >> yDepart;
    verifCoord(xDepart,yDepart );
    if(e.getPiece(xDepart,yDepart)->isWhite() != true)
    {
    color = true;
    }
    while((verifPiece(e,xDepart,yDepart) || color )== false )
    {
        cout <<"coordonnées de la piece Invalide"<<endl;
        cout <<"choisir les coordonnées de la piece en x"<<endl;
        cin >> xDepart;
        cout <<"choisir les coordonnées de la piece en y"<<endl;
        cin >> yDepart;
        verifPiece(e, xDepart,yDepart);
    }

    cout <<"choisir les coordonnées du déplacement de la piece en x"<<endl;
    cin >> xArrive;
    cout <<"choisir les coordonnées du déplacement de la piece en y"<<endl;
    cin >> yArrive;

    verifCoord(xDepart,yDepart );
    while(verifCoord(xArrive,yArrive) == false)
    {
        cout <<"coordonnées  Invalide"<<endl;
        cout <<"choisir les coordonnées du déplacement de la piece en x"<<endl;
        cin >> xArrive;
        cout <<"choisir les coordonnées du déplacement de la piece en y"<<endl;
        cin >> yArrive;
        verifCoord(xArrive,yArrive);
    }

    if(e.getPiece(xDepart, yDepart)->mouvementValide(e, xArrive, yArrive)){
        if(e.getPiece(xArrive, yArrive) !=NULL)
        {
            e.getPiece(xDepart, yDepart)->mange(e, false, xArrive, yArrive);
            cout <<"Vous avez mangé une piece adverse"<<endl;
        }
    e.deplacer(e.getPiece(xDepart, yDepart),xArrive, yArrive);

    }



}



bool
JoueurBlanc::isWhite()
{
  return true;
}

bool
JoueurNoir::isWhite()
{
  return false;
}

void
Joueur::affiche()
{
  vector<Piece*>::iterator p = m_pieces.begin();
  while ( p != m_pieces.end() )
    {
      (*p)->affiche();
      p++;
    }
  /*
  for (int i=0;i<16;i++)
    m_pieces[i]->affiche();
  */
}

JoueurBlanc::JoueurBlanc() //: Joueur(true)
{
  Roi *pr = new Roi(true);
  Reine *pq = new Reine(true);
  Cavalier *pcl = new Cavalier(true,true);
  Cavalier *pcr = new Cavalier(true,false);
  Fou *pfl = new Fou(true,true);
  Fou *pfr = new Fou(true,false);
  Tour *ptl = new Tour(true,true);
  Tour *ptr = new Tour(true,false);

  m_pieces.push_back(pr);
  m_pieces.push_back(pq);
  m_pieces.push_back(pcl);
  m_pieces.push_back(pcr);
  m_pieces.push_back(pfl);
  m_pieces.push_back(pfr);
  m_pieces.push_back(ptl);
  m_pieces.push_back(ptr);

  for (int i=1; i<=8; i++)
    {
      Pion *p = new Pion (true,i);
      m_pieces.push_back(p);
    }
  cout << "Constructeur Joueur Blanc" << endl;
}

JoueurNoir::JoueurNoir() //: Joueur(false)
{
  Roi *pr = new Roi(false);
  Reine *pq = new Reine(false);
  Cavalier *pcl = new Cavalier(false,true);
  Cavalier *pcr = new Cavalier(false,false);
  Fou *pfl = new Fou(false,true);
  Fou *pfr = new Fou(false,false);
  Tour *ptl = new Tour(false,true);
  Tour *ptr = new Tour(false,false);

  m_pieces.push_back(pr);
  m_pieces.push_back(pq);
  m_pieces.push_back(pcl);
  m_pieces.push_back(pcr);
  m_pieces.push_back(pfl);
  m_pieces.push_back(pfr);
  m_pieces.push_back(ptl);
  m_pieces.push_back(ptr);

  for (int i=1; i<=8; i++)
    {
      Pion  *p = new Pion (false,i);
      m_pieces.push_back(p);
    }
  cout << "Constructeur Joueur Noir" << endl;
}
