/*************************************************************************
                           RemoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <RemoveCommand> (fichier RemoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "RemoveCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

RemoveCommand::RemoveCommand (map <string, Figure *> * mapFigure, map <string, Selection *> * mapSelection,
							  char * params)
{
	myMapFigure = mapFigure;
	myMapSelection = mapSelection;
	char * figures = strtok(params, " ");
	while (figures != NULL)
	{
		myMapBackup.insert(std::pair<string, Figure *>(mapFigure->find(figures)->first,
						   mapFigure->find(figures)->second));
		figures = strtok(NULL, " ");
	}
	#ifdef MAP
    	cout << "Appel au constructeur de <RemoveCommand>" << endl;
	#endif
} //----- Fin de RemoveCommand

bool RemoveCommand::Do ()
{
	for (std::map<string, Figure *>::iterator it = myMapBackup.begin(); it != myMapBackup.end(); it++)
	{
		myMapFigure->erase(it->first);
	}
	#ifdef MAP
	    cout << "Remove object" << endl;
	#endif

	return true;

} //----- Fin de RemoveCommand

bool RemoveCommand::Undo ()
{
	std::map<string, Figure *>::iterator it;
	for (it = myMapBackup.begin(); it != myMapBackup.end(); it++)
	{
		if ( myMapSelection->find(it->second->GetName()) != myMapSelection->end() )
		{
			break;
		}
		myMapFigure->insert(std::pair<string, Figure *>(it->first, it->second));
	}
	if (it != myMapBackup.end())
	{
		for (; it != myMapBackup.begin(); it--)
		{
			myMapFigure->erase(it->first);
		}
		return false;
	}
	#ifdef MAP
	    cout << "UnRemove object" << endl;
	#endif

	return true;

} //----- Fin de RemoveCommand

RemoveCommand::~RemoveCommand ( )
// Algorithme :
//
{
	for (std::map<string, Figure *>::iterator it = myMapBackup.begin(); it != myMapBackup.end(); it++)
	{
		delete it->second;
	}
#ifdef MAP
    cout << "Appel au destructeur de <RemoveCommand>" << endl;
#endif
} //----- Fin de ~RemoveCommand
