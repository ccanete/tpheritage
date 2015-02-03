/*************************************************************************
                           Circle  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Circle> (fichier Circle.h) ------
#if ! defined ( CIRCLE_H )
#define CIRCLE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Figure.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Circle>
//
//
//------------------------------------------------------------------------ 

class Circle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Move(const signed long &dx, const signed long &dy);
    // Mode d'emploi : Methode that move a point by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    //�@param : Value that will be incremented over y-axis

    virtual bool IsInSelection(const Point &a, const Point &b);
    // Mode d'emploi : Methode that verify if the circle belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    string ToString();
    // Mode d'emploi : Methode that return the string used to create it.


//------------------------------------------------- Surcharge d'op�rateurs
    friend ostream& operator << ( ostream &flux, const Circle &c);
    // Mode d'emploi : Overcharged of operator <<, to post a circle.



//-------------------------------------------- Constructeurs - destructeur
    Circle ( string n, signed long x, signed long y, int r );
    // Mode d'emploi : Circle's constructor.
    // @param : Circle's name
    // @param : First circle's center.
    // @param : Second circle's point

    virtual ~Circle ( );
    // Mode d'emploi : Circle's destructor.


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
    Point center;
    signed long radius;
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Circle>

#endif // CIRCLE_H
