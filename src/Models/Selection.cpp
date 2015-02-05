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
void Selection::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.        
    {
    pointA.Move(dx, dy);
    pointB.Move(dx, dy);
    }
//----- Fin de M�thode

string Selection::Display()
// Algorithme : Use of a stringstream to create a string to describe a selection.
{   
    return "# Selection " + name + " formed by (" + std::to_string(pointA.GetX()) + ", " + 
           std::to_string(pointA.GetY()) + "), lower left vertice, and (" + std::to_string(pointB.GetX()) + ", " + 
           std::to_string(pointB.GetY()) + "), upper high vertice has been created.\r\n";
}
//----- Fin de M�thode

string Selection::ToString()
// Algorithme : Use of a stringstream to create a string to describe a selection.
{   
    string description = "# " + name + " is formed by these elements:\r\n";
    for (std::list<Figure *>::iterator it=listFigure.begin() ; it != listFigure.end(); ++it)
    description += "# " + (*it)->ToString();
    return description;
}
//----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
Selection::Selection ( string n, Point a, Point b, map<string,Figure *> &myMap ) : name(n), pointA(a), pointB(b)
// Algorithme : Save selection's name, list of figure belongs to selection
//              (map) and creation of two Points.
{
    map<string,Figure *>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second->IsInSelection(a, b))
        {
            listFigure.push_back(it->second);
            listFigure.sort();
        }       
    }

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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es