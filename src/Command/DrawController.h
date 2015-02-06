/*************************************************************************
                           DrawController  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <DrawController> (fichier DrawController.h) ------
#if ! defined ( DRAWCONTROLLER_H )
#define DRAWCONTROLLER_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <stack>
#include <list>
#include <string>

#include "Command.h"
#include "MoveCommand.h"
#include "AddCommand.h"
#include "RemoveCommand.h"
#include "ClearCommand.h"
#include "LoadCommand.h"

#include "../Models/Figure.h"
#include "../Models/Polyline.h"
#include "../Models/Point.h"
#include "../Models/Circle.h"
#include "../Models/Rectangle.h"
#include "../Models/Line.h"
#include "../Models/Selection.h"
#include "Command.h"


//------------------------------------------------------------- Constantes 

#define ZERO 0
#define ONE 1
#define TWO 2
#define HUNDRED 100
#define MAXUNDO 20
//#define MAP



//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <DrawController>
//
//
//------------------------------------------------------------------------ 

class DrawController
{
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------- Constructeurs - destructeur

    DrawController ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DrawController ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string ExecuteCommand (string commandInput);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string AddFigureToList (string name, Figure * figureAdded);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string RemoveFigureFromList (string name);
    // Mode d'emploi :
    //
    // Contrat :
    //




//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Méthodes privées
    string addFigure (char cmd , char * params);

    string createSelection ( char * params );

    string deleteFigures ( char * params );

    string move ( char * params );

    string list ();

    string undo ();

    string redo ();

    string loadFigures ( char * params );

    string saveFigures ( char * params );

    string clear();

private:
//------------------------------------------------------- Attributs privés
    map <string, Figure *> mapFigure;
    map <string, Selection *> mapSelection;
    std::list<Command *> commandsListUndo;
    std::stack<Command *> commandsListRedo;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DrawController>

#endif // DRAWCONTROLLER_H
