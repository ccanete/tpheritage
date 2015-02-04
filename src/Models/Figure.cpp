/*************************************************************************
                           Figure  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Figure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Figure::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

string Figure::GetName()
// Algorithme :
//
{
    return "";
}
//----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
bool Figure::operator < ( const Figure &f )
// Algorithme :
//
{
	return name > f.name;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( const Figure & unFigure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Figure>" << endl;
#endif
} //----- Fin de Figure (constructeur de copie)


Figure::Figure ( string name )
// Algorithme :
//
{
this->name = name;
#ifdef MAP
    cout << "Appel au constructeur de <Figure>" << endl;
#endif
} //----- Fin de Figure


Figure::~Figure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
