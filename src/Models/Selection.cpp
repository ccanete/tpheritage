/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Réalisation de la classe <Selection> (fichier Selection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Selection::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.    	
	{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
	}
//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator << ( ostream &flux, const Selection &r )
// Algorithme :
//
{
    flux << "# Selection ";
    flux << r.name;
    flux << " formed by (";
    flux << r.pointA.GetX();
    flux << ", ";
    flux << r.pointA.GetY();
    flux << "), lower left vertice, and (";
    flux << r.pointB.GetX();
    flux << ", ";
    flux << r.pointB.GetY();
    flux << "), upper high vertice has been created.\r\n";
    return flux;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Selection::Selection ( string n, Point a, Point b, map<string,Figure *> &myMap ) : name(n), pointA(a), pointB(b)
// Algorithme : Save selection's name, list of figure belongs to selection
//              (map) and creation of two Points.
{
    map<string,Figure *>::iterator it;
    cout << *this;
    for (it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second->IsInSelection(a, b))
        {
            listFigure.push_back(it->second);
            listFigure.sort();
        }       
    }
    for (std::list<Figure *>::iterator it=listFigure.begin() ; it != listFigure.end(); ++it)
    cout << "# " << (*it)->ToString();

#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection


Selection::~Selection ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
