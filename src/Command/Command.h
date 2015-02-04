/*************************************************************************
                           Command  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Command> (fichier ${file_name}) ------
#if ! defined ( Command_H )
#define Command_H

#include <iostream>
    
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
// Rôle de la classe <Command>
//
//
//------------------------------------------------------------------------ 

class Command
{
//----------------------------------------------------------------- PUBLIC

public:
    Command(/*models::Group* inGroup*/);
    /**
     * @constructor
     * @param inGroup The group where the command operates
     */
    
    virtual bool Do() = 0;
    /**
     * Executes or redo the command
     */

    virtual bool Undo() = 0;
    /**
     * Undo the command
     */

    virtual ~Command();
    /**
     * @destructor
     */

//------------------------------------------------------------------ PRIVE 


private:
//------------------------------------------------------- Attributs privés


};

//----------------------------------------- Types dépendants de <Command>

#endif // Command_H
