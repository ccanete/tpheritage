/*************************************************************************
                           Selection  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection.h) ------
#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Figure.h"
#include "Point.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Selection>
//
//
//------------------------------------------------------------------------ 

class Selection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void Move(const signed long &dx, const signed long &dy);
    // Mode d'emploi : Methode that move a point by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    //�@param : Value that will be incremented over y-axis

    bool IsInSelection(const Point &a, const Point &b);
    // Mode d'emploi : Methode that verify if the rectangle belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    string ToString();
    // Mode d'emploi : Methode that return the string used to create it.

//------------------------------------------------- Surcharge d'op�rateurs
    friend ostream& operator << ( ostream &flux, const Selection &r);
    // Mode d'emploi : Overcharged of operator <<, to post a rectangle.

//-------------------------------------------- Constructeurs - destructeur
    Selection ( string name, Point a, Point b );
    // Mode d'emploi : Selection's constructor.
    // @param : Selection's name
    // @param : First rectangle's point, lower left vertice
    // @param : Second rectangle's point, upper right vertice

    virtual ~Selection ( );
    // Mode d'emploi : Selection's destructor.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    string name;
    Point pointA;
    Point pointB;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Selection>

#endif // RECTANGLE_H
