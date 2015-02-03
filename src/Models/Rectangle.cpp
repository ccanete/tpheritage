/*************************************************************************
                           Rectangle  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- R�alisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Rectangle::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Rectangle::Move(signed long dx, signed long dy)
// 	Algorithme :
//				
	{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
	}
//----- Fin de M�thode

bool Rectangle::IsInSelection(Point a, Point b) 
// 	Algorithme :
//	
	{
		if (pointA.IsInSelection(a, b) && pointB.IsInSelection(a, b))
			return true;
		else
	    	return false;
	}
//----- Fin de M�thode

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
//----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
