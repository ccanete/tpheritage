/*************************************************************************
                           RemoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <RemoveCommand> (fichier ${file_name}) ------
#if ! defined ( REMOVECOMMAND_H )
#define REMOVECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "../Models/Figure.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <RemoveCommand>
//
//
//------------------------------------------------------------------------ 

class RemoveCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    RemoveCommand (map <string, Figure *> * mapFigure, map <string, Selection *> * mapSelection, char * params);
    /**
     * @constructor
     * @param figure The objet that will Remove
     * @param dx Delta x
     * @param dy Delta y
     */

    virtual bool Do();

    virtual bool Undo();

    virtual ~RemoveCommand ( );


private:
//------------------------------------------------------- Méthodes privées
    map <string, Figure *> myMapBackup;
    map <string, Figure *> * myMapFigure;
    map <string, Selection *> * myMapSelection;
};

//----------------------------------------- Types dépendants de <RemoveCommand>

#endif // REMOVECOMMAND_H
