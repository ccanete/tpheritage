/*************************************************************************
                           LoadCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <LoadCommand> (fichier LoadCommand.h) ------
#if ! defined ( LoadCommand_H )
#define LoadCommand_H

#include <fstream>
#include <vector>

#include "Command.h"
#include "AddCommand.h"

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
// Rôle de la classe <LoadCommand>
//
//
//------------------------------------------------------------------------ 

class LoadCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    LoadCommand (map <string, Figure *> * mapFigure, ifstream &file);
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
    map <string, Figure *> * myMapFigure;
    vector<Command *> myCommands;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};


#endif // LoadCommand_H
