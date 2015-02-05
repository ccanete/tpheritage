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
void Line::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.
{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
}
//----- Fin de Méthode

bool Line::IsInSelection(const Point &a, const Point &b) 
// Algorithme : Call to point's IsInSelection method.
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
    return result;
}
//----- Fin de Méthode

string Line::Display()
// Algorithme : Use of a stringstream to create a string to describe a line.
{   
    stringstream flux;
    flux << "# Line ";
    flux << name;
    flux << " passing by (";
    flux << pointA.GetX();
    flux << ", ";
    flux << pointA.GetY();
    flux << ") and (";
    flux << pointB.GetX();
    flux << ", ";
    flux << pointB.GetY();
    flux << ") has been created.\r\n";
    return flux.str();
}
//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Line::Line ( string name, Point a, Point b ) : Figure(name), pointA(a), pointB(b)
// Algorithme : Call to Figure's constructor and creation of two Points.
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
