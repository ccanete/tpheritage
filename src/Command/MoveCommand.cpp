/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <MoveCommand> (fichier MoveCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MoveCommand.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

MoveCommand::MoveCommand (Figure* figure, signed long x, signed long y) : dx(x), dy(y)
{
	myList.push_back(figure);
	#ifdef MAP
    	cout << "Appel au constructeur de <MoveCommand>" << endl;
	#endif
} //----- Fin de MoveCommand

MoveCommand::MoveCommand (Selection* selection, signed long x, signed long y) : dx(x), dy(y)
{
	myList = selection->ListFigure();
	#ifdef MAP
    	cout << "Appel au constructeur de <MoveCommand>" << endl;
	#endif
} //----- Fin de MoveCommand

bool MoveCommand::Do ()
{
	#ifdef MAP
	    cout << "Move object" << endl;
	#endif
	for (std::list<Figure *>::iterator it = myList.begin() ; it != myList.end(); it++)
	{
		(*it)->Move(dx, dy);
	}
	return true;

} //----- Fin de MoveCommand

bool MoveCommand::Undo ()
{
	#ifdef MAP
	    cout << "Unmove object" << endl;
	#endif

	for (std::list<Figure *>::iterator it = myList.begin() ; it != myList.end(); it++)
	{
		(*it)->Move(-dx, -dy);
	}	
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
