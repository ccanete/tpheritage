/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Figure.h"
#include "Point.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
//
//
//------------------------------------------------------------------------ 

class Rectangle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Move(const signed long &dx, const signed long &dy);
    // Mode d'emploi : Methode that move the rectangle by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    // @param : Value that will be incremented over y-axis

    bool IsInSelection(const Point &a, const Point &b);
    // Mode d'emploi : Methode that verify if the rectangle belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    string ToString();
    // Mode d'emploi : Methode that return the string used to create it.

    string Display();
    // Mode d'emploi : Method that return the string to describe
    //                 the figure.

//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( string name, Point a, Point b );
    // Mode d'emploi : Rectangle's constructor.
    // @param : Rectangle's name
    // @param : First rectangle's point, lower left vertice
    // @param : Second rectangle's point, upper right vertice

    virtual ~Rectangle ( );
    // Mode d'emploi : Rectangle's destructor.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Point pointA;
    Point pointB;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE_H