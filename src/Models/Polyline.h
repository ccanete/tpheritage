/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Polyline> (fichier Polyline.h) ------
#if ! defined ( Polyline_H )
#define Polyline_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Figure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polyline>
//
//
//------------------------------------------------------------------------ 

class Polyline : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Move(const signed long &dx, const signed long &dy);
    // Mode d'emploi : Methode that move every point by dx over x-axis and 
    //                 by dy over y-axis.
    // @param : Value that will be incremented over x-axis
    // @param : Value that will be incremented over y-axis

    bool IsInSelection(const Point &a, const Point &b);
    // Mode d'emploi : Methode that verify if the polyline belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    string ToString();
    // Mode d'emploi : Methode that return the string used to create it.

    string Display();
    // Mode d'emploi : Method that return the string to describe
    //                 the figure.

//-------------------------------------------- Constructeurs - destructeur
    Polyline ( string name, vector<Point> &v );
    // Mode d'emploi : Polyline's constructor.
    // @param : Polyline's name
    // @param : Vector containing polyline's points

    virtual ~Polyline ( );
    // Mode d'emploi : Polyline's destructor.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
vector<Point> myVector;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Polyline>

#endif // Polyline_H
