/*************************************************************************
                           Figure  -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H )
#define FIGURE_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>

#include "Point.h"
using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Figure>
//
//
//------------------------------------------------------------------------ 

class Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    virtual void Move(const signed long &dx, const signed long &dy) = 0;
    // Mode d'emploi : Method that move a point by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    //�@param : Value that will be incremented over y-axis

    string GetName();
    // Mode d'emploi : Method that return the figure's name.

    virtual string ToString() = 0;
    // Mode d'emploi : Method that return the string used to recreate 
    //                 the figure.

    virtual bool IsInSelection(const Point &a, const Point &b) = 0;
    // Manual : Methode that verify if the circle belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

//------------------------------------------------- Surcharge d'op�rateurs
    bool operator < ( const Figure &f );
    // Mode d'emploi : Overcharged of operator <<, to post a polyline.

//-------------------------------------------- Constructeurs - destructeur
    Figure ( string name );
    // Mode d'emploi : Figure's constructor.
    // @param : Figure's name

    virtual ~Figure ( );
    // Mode d'emploi : Figure's destructor.


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
string name;
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Figure>

#endif // FIGURE_H
