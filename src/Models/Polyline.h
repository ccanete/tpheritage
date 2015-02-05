/*************************************************************************
                           Polyline  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Polyline> (fichier Polyline.h) ------
#if ! defined ( Polyline_H )
#define Polyline_H

//--------------------------------------------------- Interfaces utilis�es
#include <vector>
#include "Figure.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Polyline>
//
//
//------------------------------------------------------------------------ 

class Polyline : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void Move(const signed long &dx, const signed long &dy);
    // Mode d'emploi : Methode that move every point by dx over x-axis and 
    //                 by dy over y-axis.
    // @param : Value that will be incremented over x-axis
    //�@param : Value that will be incremented over y-axis

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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
vector<Point> myVector;
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Polyline>

#endif // Polyline_H
