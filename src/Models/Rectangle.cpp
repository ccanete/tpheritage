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
void Rectangle::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.    
    {
    pointA.Move(dx, dy);
    pointB.Move(dx, dy);
    }
//----- Fin de Méthode

bool Rectangle::IsInSelection(const Point &a, const Point &b) 
// Algorithme : Call to point's IsInSelection method.
    {
        if (pointA.IsInSelection(a, b) && pointB.IsInSelection(a, b))
            return true;
        else
            return false;
    }
//----- Fin de Méthode

string Rectangle::ToString()
// Algorithme : Use of a stringstream to create a string equals to
//              input user's one.
{   
    stringstream sstm;
    sstm << "R " << name << " " 
         << pointA.GetX() << " " << pointA.GetY() 
         << " " << pointB.GetX() << " " 
         << pointB.GetY() << "\r\n";
    string result = sstm.str();
    return result;
}
//----- Fin de Méthode

string Rectangle::Display()
// Algorithme : Use of a stringstream to create a string to describe a rectangle.
{   
    stringstream flux;
    flux << "# Rectangle ";
    flux << name;
    flux << " formed by (";
    flux << pointA.GetX();
    flux << ", ";
    flux << pointA.GetY();
    flux << "), lower left vertice, and (";
    flux << pointB.GetX();
    flux << ", ";
    flux << pointB.GetY();
    flux << "), upper high vertice has been created.\r\n";
    return (string)flux.str();
}
//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( string name, Point a, Point b ) : Figure(name), pointA(a), pointB(b)
// Algorithme : Call to Figure's constructor and creation of two Points.

{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées