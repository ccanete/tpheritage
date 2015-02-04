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
// type Polyline::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Polyline::Move(const signed long &dx, const signed long &dy)
// Algorithme :
//
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
// Algorithme :
//
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
// Algorithme :
//
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

//------------------------------------------------- Surcharge d'op�rateurs
ostream& operator << ( ostream &flux, Polyline &p )
// Algorithme :
//
{
    cout << "OK\r\n";
    flux << "# Polyline ";
    flux << p.name;
    flux << " passing by ";
    std::vector<Point>::iterator it = p.myVector.begin();
    for (;it != (p.myVector.end() - ONE); it++)
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
    return flux;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Polyline::Polyline ( string name, vector<Point> &v ) : Figure(name), myVector(v)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif
} //----- Fin de Polyline


Polyline::~Polyline ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
