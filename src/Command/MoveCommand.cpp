/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MoveCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

MoveCommand::MoveCommand (Figure* figure, long dx, long dy) : figure_(figure), dx_(dx), dy_(dy)
{
	#ifdef MAP
    	cout << "Appel au constructeur de <MoveCommand>" << endl;
	#endif
} //----- Fin de MoveCommand

bool MoveCommand::Do ()
{
	#ifdef MAP
	    cout << "Move object" << endl;
	#endif

	//figure_->Move(dx_, dy_);
	return true;

} //----- Fin de MoveCommand

bool MoveCommand::Undo ()
{
	#ifdef MAP
	    cout << "Unmove object" << endl;
	#endif

	//figure_->Move(-dx_, -dy_);
	return true;

} //----- Fin de MoveCommand

MoveCommand::~MoveCommand ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MoveCommand>" << endl;
#endif
} //----- Fin de ~MoveCommand
