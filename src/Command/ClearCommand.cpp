/*************************************************************************
                           ClearCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <ClearCommand> (fichier ClearCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ClearCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ClearCommand::ClearCommand (map <string, Figure *> * mapFigure)
{
	myMapFigure = mapFigure;
	for (map<string,Figure *>::iterator it = mapFigure->begin(); it != mapFigure->end(); it++)
	{
		myVector.push_back(it->second);
	}
	#ifdef MAP
    	cout << "Appel au constructeur de <ClearCommand>" << endl;
	#endif
} //----- Fin de ClearCommand

bool ClearCommand::Do ()
{
	myMapFigure->clear();
	#ifdef MAP
	    cout << "Remove object" << endl;
	#endif

	//figure_->Remove(dx_,dy_);
	return true;

} //----- Fin de ClearCommand

bool ClearCommand::Undo ()
{
	for (std::vector<Figure *>::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		myMapFigure->insert(std::pair<string, Figure *>((*it)->GetName(), *it));
	}
	#ifdef MAP
	    cout << "UnRemove object" << endl;
	#endif

	//figure_->Remove(-dx_,-dy_);
	return true;

} //----- Fin de ClearCommand

ClearCommand::~ClearCommand ( )
// Algorithme :
//
{
	for (std::vector<Figure *>::iterator it = myVector.begin(); it != myVector.end(); it++)
	{
		delete *it;
	}
#ifdef MAP
    cout << "Appel au destructeur de <ClearCommand>" << endl;
#endif
} //----- Fin de ~ClearCommand
