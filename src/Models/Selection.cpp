/*************************************************************************
                           Selection  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- R�alisation de la classe <Selection> (fichier Selection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Selection::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Selection::Move(const signed long &dx, const signed long &dy)
// 	Algorithme :
//				
	{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
	}
//----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
ostream& operator << ( ostream &flux, const Selection &r )
// Algorithme :
//
{
    cout << "OK\r\n";
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
Selection::Selection ( string n, Point a, Point b ) : name(n), pointA(a), pointB(b)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection


Selection::~Selection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
