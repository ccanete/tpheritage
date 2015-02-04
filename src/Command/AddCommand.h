/*************************************************************************
                           AddCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <AddCommand> (fichier AddCommand.h) ------
#if ! defined ( AddCommand_H )
#define AddCommand_H

#include "Command.h"

#include "../Models/Figure.h"
#include "../Models/Polyline.h"
#include "../Models/Point.h"
#include "../Models/Circle.h"
#include "../Models/Rectangle.h"
#include "../Models/Line.h"
#include "../Models/Selection.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <AddCommand>
//
//
//------------------------------------------------------------------------ 

class AddCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    AddCommand (char objType, char * params);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool Do();

    virtual bool Undo();

    virtual ~AddCommand ( );
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

    char myObjType;
    char * myParams;
    string name;
    Figure * newFigure;

//----------------------------------------- Objets atributs

    char * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
    signed long coordX1, coordX2, coordY1, coordY2;
    long radius;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};


#endif // AddCommand_H
