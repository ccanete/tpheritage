/*************************************************************************
                           LoadCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <LoadCommand> (fichier LoadCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LoadCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
LoadCommand::LoadCommand (map <string, Figure *> * mapFigure, map <string, Selection *> * mapSelection, ifstream &file)
// Algorithme :
//
{
    signed long coordX1, coordX2, coordY1, coordY2;
    long radius;
    char * command, * text;
    string read;
    myMapSelection = mapSelection;

    while (getline(file, read))
    {			
    	text = (char *) read.c_str();
    	command = strtok(text ," ");

    	if ( *text == '#')
		{
			getline(file, read);
			text = (char *) read.c_str();
    		command = strtok(text ," ");
			continue;
		}
		myCommands.push_back(new AddCommand(mapFigure, mapSelection, *command, strtok(NULL, "\r")) );
    }
	#ifdef MAP
		cout << "Appel au constructeur de <LoadCommand>" << endl;
	#endif
} //----- Fin de LoadCommand

bool LoadCommand::Do ()
{
	vector<Command *>::iterator it;
	for (it = myCommands.begin(); it != myCommands.end(); it++)
	{
		if (!(*it)->Do())
		{
			break;
		}
	}
	if (it != myCommands.end())
	{
		for (; it != myCommands.begin(); it--)
		{
			(*it)->Undo();
		}
		return false;
	}

	#ifdef MAP
	    cout << "Create object" << endl;
	#endif

	return true;

} //----- Fin de Do

bool LoadCommand::Undo ()
{
	for (vector<Command *>::iterator it = myCommands.begin(); it != myCommands.end(); it++)
	{
		(*it)->Undo();
	}
	#ifdef MAP
	    cout << "Unmove object" << endl;
	#endif

	//figure_->Move(-dx_, -dy_);
	return true;

} //----- Fin de Undo

LoadCommand::~LoadCommand ( )
// Algorithme :
//
{
	for (vector<Command *>::iterator it = myCommands.begin(); it != myCommands.end(); it++) 
	{
		delete *it;
	}
#ifdef MAP
    cout << "Appel au destructeur de <LoadCommand>" << endl;
#endif
} //----- Fin de ~LoadCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
