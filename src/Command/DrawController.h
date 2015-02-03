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

#include "../Models/Figure.h"
#include "Command.h"

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

    std::string ExecuteCommand (std::string commandInput);
    // Mode d'emploi :
    //
    // Contrat :
    //




//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Méthodes privées

        std::string addFigure (char cmd , char * params);


/*
    std::string add             ( std::string cmd, std::string params );
    std::string deleteFigure    ( char * params );
    std::string move            ( char * params );
    std::string load            ( char * params );
    std::string save            ( char * params );
    std::string list            ();
    std::string undo            ();
    std::string redo            ();
    std::string clear           ();
    */

private:
//------------------------------------------------------- Attributs privés
    //std::vector<Command> commands;
    std::map <char *,Figure *> figuresList;
    std::queue<Command> commandsList;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <DrawController>

#endif // DrawController_H
