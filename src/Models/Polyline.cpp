/*************************************************************************
                           Polyline  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Polyline> (fichier Polyline.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Polyline.h"

//------------------------------------------------------------- Constantes
#define ONE 1
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Polyline::Move(const signed long &dx, const signed long &dy)
// Algorithme : Call to point's Move method.
{
    for (std::vector<Point>::iterator it = myVector.begin() ; it != myVector.end(); it++)
    {
        it->x += dx;
        it->y += dy;
    }
}
//----- Fin de M�thode

bool Polyline::IsInSelection(const Point &a, const Point &b) 
{
// Algorithme : Call to point's IsInSelection method.
    std::vector<Point>::iterator it = myVector.begin();
    for (; it != myVector.end(); it++)
    {
        if (!it->IsInSelection(a, b))
        {
            return false;
        }
    }
    return true;
}
//----- Fin de M�thode


string Polyline::ToString()
// Algorithme : Use of a stringstream to create a string equals to
//              input user's one.
{
    stringstream sstm;
    sstm << "PL " << name << " ";
    for (std::vector<Point>::iterator it = myVector.begin() ; it != myVector.end(); it++)
    {
        sstm << it->x << " " << it->y << " ";
    }
    sstm << "\r\n";
    string result = sstm.str();
    return result;
}
//----- Fin de M�thode

string Polyline::Display()
// Algorithme : Use of a stringstream to create a string to describe a polyline.
{   
    stringstream flux;
    flux << "# Polyline ";
    flux << name;
    flux << " passing by ";
    std::vector<Point>::iterator it = myVector.begin();
    for (;it != (myVector.end() - ONE); it++)
    {
        flux << "(";
        flux << it->GetX();
        flux << ", ";
        flux << it->GetY();
        flux << "), ";
    }
    flux << "(";
    flux << it->GetX();
    flux << ", ";
    flux << it->GetY();
    flux << ") ";
    flux << "has been created.\r\n";
    return (string)flux.str();
}
//----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
Polyline::Polyline ( string name, vector<Point> &v ) : Figure(name), myVector(v)
// Algorithme : Call to Figure's constructor and creation of n Points. 
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif
} //----- Fin de Polyline


Polyline::~Polyline ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es