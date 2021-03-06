/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <MoveCommand> (fichier ${file_name}) ------
#if ! defined ( MOVECOMMAND_H )
#define MOVECOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "../Models/Figure.h"
#include "../Models/Selection.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <MoveCommand>
//
//
//------------------------------------------------------------------------ 

class MoveCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    MoveCommand (Figure* figure, long dx, long dy);

    MoveCommand (Selection* selection, long dx, long dy);

    virtual bool Do();

    virtual bool Undo();

    virtual ~MoveCommand ( );


private:
//------------------------------------------------------- Méthodes privées
    list<Figure *> myList;
    long dx, dy;

};

//----------------------------------------- Types dépendants de <MoveCommand>

#endif // MOVECOMMAND_H
