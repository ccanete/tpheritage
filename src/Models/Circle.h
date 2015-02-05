/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H )
#define CIRCLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Figure.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Circle>
//
//
//------------------------------------------------------------------------ 

class Circle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Move(const signed long &dx, const signed long &dy);
    // Manual : Methode that move the circle by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    // @param : Value that will be incremented over y-axis

    virtual bool IsInSelection(const Point &a, const Point &b);
    // Manual : Methode that verify if the circle belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    string ToString();
    // Manual : Methode that return the string used to create it.

    string Display();
    // Mode d'emploi : Method that return the string to describe
    //                 the figure.
    
//-------------------------------------------- Constructeurs - destructeur
    Circle ( string n, signed long x, signed long y, int r );
    // Manual : Circle's constructor.
    // @param : Circle's name
    // @param : First circle's center.
    // @param : Second circle's point

    virtual ~Circle ( );
    // Manual : Circle's destructor.


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    Point center;
    signed long radius;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Circle>

#endif // CIRCLE_H