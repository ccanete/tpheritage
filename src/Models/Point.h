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
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Point Move(signed long dx, signed long dy);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool IsInSelection(const Point &a, const Point &b);
    // Mode d'emploi :
    //
    // Contrat :
    //

    signed long GetX() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    signed long GetY() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    Point& operator = ( const Point& unPoint);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Point( const Point& unPoint);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point( const signed long &a, const signed long &b );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point( );
    // Mode d'emploi :
    //
    // Contrat :
    //

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
