/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Figure.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string Figure::GetName()
// Algorithme : Return figure's name.
//
{
    return name;
}
//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
bool Figure::operator < ( const Figure &f )
// Algorithme : 
//
{
	return name > f.name;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( string name )
// Algorithme : Save of figure's name.
// @param : Name.
{
this->name = name;
#ifdef MAP
    cout << "Appel au constructeur de <Figure>" << endl;
#endif
} //----- Fin de Figure


Figure::~Figure ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
} //----- Fin de ~Figure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
