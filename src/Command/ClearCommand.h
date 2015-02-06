/*************************************************************************
                           ClearCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <ClearCommand> (fichier ${file_name}) ------
#if ! defined ( CLEARCOMMAND_H )
#define CLEARCOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "../Models/Figure.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <ClearCommand>
//
//
//------------------------------------------------------------------------ 

class ClearCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    ClearCommand (map <string, Figure *> * mapFigure);
    /**
     * @constructor
     * @param figure The objet that will Remove
     * @param dx Delta x
     * @param dy Delta y
     */

    virtual bool Do();

    virtual bool Undo();

    virtual ~ClearCommand ( );


private:
//------------------------------------------------------- Méthodes privées
    vector<Figure*> myVector;
    map <string, Figure *> * myMapFigure;
};

//----------------------------------------- Types dépendants de <ClearCommand>

#endif // CLEARCOMMAND_H
