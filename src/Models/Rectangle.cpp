/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Rectangle::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Rectangle::Move(signed long dx, signed long dy)
// 	Algorithme :
//				
	{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
	}
//----- Fin de Méthode

bool Rectangle::IsInSelection(Point a, Point b) 
// 	Algorithme :
//	
	{
		if (pointA.IsInSelection(a, b) && pointB.IsInSelection(a, b))
			return true;
		else
	    	return false;
	}
//----- Fin de Méthode

string Rectangle::ToString()
// Algorithme :
//
{   
    stringstream sstm;
    sstm << "R " << name << " " 
    	 <<	pointA.GetX() << " " << pointA.GetY() 
    	 << " " << pointB.GetX() << " " 
    	 << pointB.GetY() << "\r\n";
    string result = sstm.str();
    cout << result;
    return result;
}
//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator << ( ostream &flux, const Rectangle &r )
// Algorithme :
//
{
    cout << "OK\r\n";
    flux << "# Rectangle ";
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
/*Rectangle::Rectangle ( const Rectangle & unRectangle )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)
*/

Rectangle::Rectangle ( string name, Point a, Point b ) : Figure(name), pointA(a), pointB(b)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
