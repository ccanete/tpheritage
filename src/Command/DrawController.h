/*************************************************************************
                           DrawController  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <DrawController> (fichier DrawController.h) ------
#if ! defined ( DrawController_H )
#define DrawController_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <queue>
#include <string>

#include "Command.h"
#include "MoveCommand.h"
#include "AddCommand.h"

#include "../Models/Figure.h"
#include "../Models/Polyline.h"
#include "../Models/Point.h"
#include "../Models/Circle.h"
#include "../Models/Rectangle.h"
#include "../Models/Line.h"
#include "../Models/Selection.h"

//------------------------------------------------------------- Constantes 

#define ZERO 0
#define ONE 1
#define TWO 2
#define MAXUNDO 20
#define MAP



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

    int ExecuteCommand (string commandInput);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int AddFigureToList (string name, Figure * figureAdded);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int RemoveFigureFromList (string name);
    // Mode d'emploi :
    //
    // Contrat :
    //




//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Méthodes privées
    int addFigure (char cmd , char * params);

    int createSelection ( char * params );

    int deleteFigures ( char * params );

    int list ();

    int saveFigures ( char * params );

private:
//------------------------------------------------------- Attributs privés
    map <string, Figure *> mapFigure;
    map <string, Selection *> mapSelection;
    //queue<Command> commandsList;
    //vector<Command> commands;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DrawController>

#endif // DrawController_H
