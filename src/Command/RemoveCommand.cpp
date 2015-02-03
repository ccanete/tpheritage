/*************************************************************************
                           RemoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <RemoveCommand> (fichier RemoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "RemoveCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

RemoveCommand::RemoveCommand (Figure* figure, long dx, long dy) : figure_(figure), dx_(dx), dy_(dy)
{
	#ifdef MAP
    	cout << "Appel au constructeur de <RemoveCommand>" << endl;
	#endif
} //----- Fin de RemoveCommand

bool RemoveCommand::Do ()
{
	#ifdef MAP
	    cout << "Remove object" << endl;
	#endif

	//figure_->Remove(dx_,dy_);
	return true;

} //----- Fin de RemoveCommand

bool RemoveCommand::Undo ()
{
	#ifdef MAP
	    cout << "UnRemove object" << endl;
	#endif

	//figure_->Remove(-dx_,-dy_);
	return true;

} //----- Fin de RemoveCommand

RemoveCommand::~RemoveCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RemoveCommand>" << endl;
#endif
} //----- Fin de ~RemoveCommand
