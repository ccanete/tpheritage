/*************************************************************************
                           AddCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <AddCommand> (fichier AddCommand.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AddCommand.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
AddCommand::AddCommand (map <string, Figure *> * mapFigure, map <string, Selection *> * mapSelection, char objType, char * params)
// Algorithme :
//
{
	#ifdef MAP
	    cout << "Appel au constructeur de <AddCommand>" << endl;
	#endif
    char * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
    signed long coordX1, coordX2, coordY1, coordY2;
    long radius;
	myObjType = objType;
	myParams = params;
	myMapFigure = mapFigure;
	myMapSelection = mapSelection;


	if (myObjType == 'C')
	{

        name = strtok(params, " ");

		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");

		coordX1 = strtol(secondEntry,NULL,10);
		coordY1 = strtol(thirdEntry,NULL,10);
		radius = strtol(fourthEntry,NULL,10);

		// Circle creation method

		Circle * myCircle = new Circle(name, coordX1, coordY1, radius);
		newFigure = myCircle;
	}
	if (myObjType == 'R')
	{
		name = strtok(params, " ");

		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		coordX1 = strtol(secondEntry,NULL,10);
		coordY1 = strtol(thirdEntry,NULL,10);
		coordX2 = strtol(fourthEntry,NULL,10);
		coordY2 = strtol(fifthEntry,NULL,10);

		// Rectangle creation method
		Rectangle * myRectangle = new Rectangle(name, Point(coordX1, coordY1), Point(coordX2, coordY2));
		newFigure = myRectangle;
	}
	
	if (myObjType == 'L')
	{
		name  = strtok(params, " ");

		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		coordX1 = strtol(secondEntry,NULL,10);
		coordY1 = strtol(thirdEntry,NULL,10);
		coordX2 = strtol(fourthEntry,NULL,10);
		coordY2 = strtol(fifthEntry,NULL,10);
		
		// Line creation method
		Line * myLine = new Line(name, Point(coordX1, coordY1), Point(coordX2, coordY2));
		newFigure = myLine;
	}
	
	if (myObjType == 'P')
	{
		vector<Point> myVector;
		name = strtok(params, " ");

		while (true)
		{
			secondEntry = strtok(NULL, " ");
			thirdEntry = strtok(NULL, " "); 
			if (thirdEntry == NULL)
			{
				break;
			}
			myVector.push_back(Point(strtol(secondEntry,NULL,10), strtol(thirdEntry,NULL,10)));
		}

		Polyline * myPolyline = new Polyline(name, myVector);
		newFigure = myPolyline;
	}

} //----- Fin de AddCommand

bool AddCommand::Do ()
{
	#ifdef MAP
	    cout << "Create object" << endl;
	#endif
    if ( myMapSelection->find(name) != myMapSelection->end())
    {
    	return false;
    }
	myMapFigure->insert(std::pair<string,Figure *>(name,newFigure));

	return true;

} //----- Fin de Do

bool AddCommand::Undo ()
{
	#ifdef MAP
	    cout << "Unmove object" << endl;
	#endif
	myMapFigure->erase(name);

	return true;

} //----- Fin de Undo

AddCommand::~AddCommand ( )
// Algorithme :
//
{
	delete newFigure;
#ifdef MAP
    cout << "Appel au destructeur de <AddCommand>" << endl;
#endif
} //----- Fin de ~AddCommand


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
