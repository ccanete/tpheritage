/*************************************************************************
                           Point -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Point Move(const signed long &dx, const signed long &dy);
    // Mode d'emploi : Methode that move a point by dx over x-axis and by 
    //                 dy over y-axis.
    // @param : Value that will be incremented over x-axis
    // @param : Value that will be incremented over y-axis
    
    bool IsInSelection(const Point &a, const Point &b);
    // Mode d'emploi : Methode that verify if the point belong to a
    //                 selection.
    // @param : First point, lower left vertice
    // @param : Second point, upper right vertice 

    signed long GetX() const;
    // Mode d'emploi : Method that return x.

    signed long GetY() const;
    // Mode d'emploi : Method that return y.


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi : Point's copies constructor.
    // @param : Point

    Point( const signed long &a, const signed long &b );
    // Mode d'emploi : Point's constructor.
    // @param : X
    // @param : Y
    virtual ~Point( );
    // Mode d'emploi : Point's destructor.


//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    signed long x;
    signed long y;
//---------------------------------------------------------- Classes amies
friend class Polyline;
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
