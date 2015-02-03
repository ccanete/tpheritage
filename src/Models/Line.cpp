/*************************************************************************
                           Line  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Réalisation de la classe <Line> (fichier Line.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Line.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Line::Move(signed long dx, signed long dy)
// 	Algorithme : Use of Move point's methode.
	{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
	}
//----- Fin de Méthode

bool Line::IsInSelection(Point a, Point b) 
// 	Algorithme : Use of IsInSelection point's methode.
	{
		if (pointA.IsInSelection(a, b) && pointB.IsInSelection(a, b))
			return true;
		else
	    	return false;
	}
//----- Fin de Méthode

string Line::ToString()
// Algorithme : Use of a stringstream to create a string equals to
//              input user's one.
{   
    stringstream sstm;
    sstm << "L " << name << " " 
    	 <<	pointA.GetX() << " " << pointA.GetY() 
    	 << " " << pointB.GetX() << " " 
    	 << pointB.GetY() << "\r\n";
    string result = sstm.str();
    cout << result;
    return result;
}
//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator << ( ostream &flux, const Line &l )
{
    cout << "OK\r\n";
    flux << "# Line ";
    flux << l.name;
    flux << " passing by (";
    flux << l.pointA.GetX();
    flux << ", ";
    flux << l.pointA.GetY();
    flux << ") and (";
    flux << l.pointB.GetX();
    flux << ", ";
    flux << l.pointB.GetY();
    flux << ") has been created.\r\n";
    return flux;
} //----- Fin de operator <<


//-------------------------------------------- Constructeurs - destructeur
Line::Line ( string name, Point a, Point b ) : Figure(name), pointA(a), pointB(b)
{
#ifdef MAP
    cout << "Appel au constructeur de <Line>" << endl;
#endif
} //----- Fin de Line


Line::~Line ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Line>" << endl;
#endif
} //----- Fin de ~Line


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
