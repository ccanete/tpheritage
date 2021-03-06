/*************************************************************************
                           Selection  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection.h) ------
#if ! defined ( SELECTION_H )
#define SELECTION_H

//--------------------------------------------------- Interfaces utilis�es
#include <list>
#include <map>
#include <vector>

using namespace std;

#include "Figure.h"
#include "Point.h"
//------------------------------------------------------------- Constantes 
#define ONE 1
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
    // Mode d'emploi : Methode that move the selection by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    // @param : Value that will be incremented over y-axis

    string Display();
    // Mode d'emploi : Method that return the string to describe
    //                 the figure.

    string ToString();
    // Mode d'emploi : Method that return the string to describe
    //                 the figure.
    
    string ListElements();
    // Mode d'emploi : Method that return the string to list
    //                 selection's elements.

    list<Figure *> ListFigure();
    // Mode d'emploi : Method that return a list containing
    //                 selection's elements.
//-------------------------------------------- Constructeurs - destructeur
    Selection ( string name, Point a, Point b, map<string,Figure *> &myMap );
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
    list<Figure *> listFigure;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Selection>

#endif // SELECTION_H