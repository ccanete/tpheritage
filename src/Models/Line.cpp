/*************************************************************************
                           Line  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- R�alisation de la classe <Line> (fichier Line.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Line.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Line::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.
{
	pointA.Move(dx, dy);
	pointB.Move(dx, dy);
}
//----- Fin de M�thode

bool Line::IsInSelection(const Point &a, const Point &b) 
// Algorithme : Call to point's IsInSelection method.
{
	if (pointA.IsInSelection(a, b) && pointB.IsInSelection(a, b))
		return true;
	else
    	return false;
}
//----- Fin de M�thode

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
//----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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
// Algorithme : Call to Figure's constructor and creation of two Points.
{
    cout << *this;
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
