/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 21/01/2015
    copyright            : (C) 2015 par Accardo & Canete
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H )
#define FIGURE_H

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Figure>
//
//
//------------------------------------------------------------------------ 

class Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetName();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool IsInSelection(Point a, Point b);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Figure & operator = ( const Figure & unFigure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Figure ( const Figure & unFigure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Figure ( string name );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Figure ( );
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
string name;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Figure>

#endif // FIGURE_H
