/*************************************************************************
                           Point -  description
                             -------------------
    d�but                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
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
//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    signed long x;
    signed long y;
//---------------------------------------------------------- Classes amies
friend class Polyline;
//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Point>

#endif // POINT_H
