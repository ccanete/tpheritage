/*************************************************************************
                           LoadCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <LoadCommand> (fichier LoadCommand.h) ------
#if ! defined ( LOADCOMMAND_H )
#define LOADCOMMAND_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "AddCommand.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <LoadCommand>
//
//
//------------------------------------------------------------------------ 

class LoadCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    LoadCommand (map <string, Figure *> * mapFigure, map <string, Selection *> * mapSelection, ifstream &file);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool Do();

    virtual bool Undo();

    virtual ~LoadCommand ( );
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
    map <string, Selection *> * myMapSelection;
    vector<Command *> myCommands;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};


#endif // LOADCOMMAND_H
