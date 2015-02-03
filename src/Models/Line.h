/*************************************************************************
                           Line  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Line> (fichier Line.h) ------
#if ! defined ( LINE_H )
#define LINE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Figure.h"
#include "Point.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Line>
//
//
//------------------------------------------------------------------------ 

class Line : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void Move(signed long dx, signed long dy);
    // Mode d'emploi : Methode that move a point by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    //�@param : Value that will be incremented over y-axis
    
    bool IsInSelection(Point a, Point b);
    // Mode d'emploi : Methode that verify if the line belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    string ToString();
    // Mode d'emploi : Methode that return the string used to create it.
    
//------------------------------------------------- Surcharge d'op�rateurs
    friend ostream& operator << ( ostream &flux, const Line &l);
    // Mode d'emploi : Overcharged of operator <<, to post a line.


//-------------------------------------------- Constructeurs - destructeur
    Line ( string name, Point a, Point b );
    // Mode d'emploi : Line's constructor.
    // @param : Line's name
    // @param : First line's point
    // @param : Second line's point

    virtual ~Line ( );
    // Mode d'emploi : Line's destructor.

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    Point pointA;
    Point pointB;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Line>

#endif // LINE_H
