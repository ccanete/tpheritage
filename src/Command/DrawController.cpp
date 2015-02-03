/*************************************************************************
                           DrawController  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <DrawController> (fichier DrawController.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

#include <iostream>
#include <vector>
#include <cstdlib>


//------------------------------------------------------ Include personnel
#include "DrawController.h"

using namespace std;


//-------------------------------------------- Constructeurs - destructeur

DrawController::DrawController ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DrawController>" << endl;
#endif
<<<<<<< Updated upstream
=======
        //map <char *,Figure *> figuresList;
>>>>>>> Stashed changes

} //----- Fin de DrawController


DrawController::~DrawController ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DrawController>" << endl;
#endif
} //----- Fin de ~DrawController

//-------------------------------------------------- Methodes


int DrawController::ExecuteCommand ( string commandInput )
//Algorithme :
//
{
	// Variables initialization 
	char * textChain;
	char * command;
	char * params;

	// Transformation 
	textChain = ( char * ) commandInput.c_str();
	command = strtok(textChain, " ");
	params = strtok(NULL ,"\r");

	/*---------- COMMAND CIRCLE ----------*/
	if (!strcmp(command,"C"))
	{
		return addFigure ('C', params);
	}

	/*----------COMMAND RECTANGLE ----------*/
	else if (!strcmp(command,"R"))
	{
		return addFigure('R', params);
	}

	/*----------COMMAND LINE----------*/
	else if (!strcmp(command,"L"))
	{
		return addFigure('L', params);
	}

	/*----------COMMAND POLY-LINE----------*/
	else if (!strcmp(command,"PL") )
	{
		return addFigure('P', params);
	}

	/*----------COMMAND SELECTION----------*/
	else if (!strcmp(command, "S"))
	{
		//return createSelection(params);
	}

	/*----------COMMAND DELETE----------*/
	else if (!strcmp(command,"DELETE"))
	{
		//return delete(params);
	}

	/*----------COMMAND MOVE----------*/
	else if (!strcmp(command,"MOVE"))
	{
		//return move(params);
	}

	/*----------COMMAND LIST----------*/
	else if (!strcmp(command,"LIST"))
	{
		//return list();
	}

	/*----------COMMAND UNDO----------*/
	else if (!strcmp(command,"UNDO"))
	{
		//return undo();
	}
	
	/*----------COMMAND REDO----------*/
	else if (!strcmp(command,"REDO"))
	{
		//return redo();
	}
	
	/*----------COMMAND LOAD----------*/
	else if (!strcmp(command,"LOAD"))
	{
		//return load(params);
	}
	
	/*----------COMMAND SAVE----------*/
	else if (!strcmp(command,"SAVE"))
	{
		//return save(params);
	}
	
	/*----------COMMAND CLEAR----------*/
	else if (!strcmp(command,"CLEAR"))
	{
		//return clear();
	}
	/*----------COMMAND EXIT----------*/
	else if (!strcmp(command,"EXIT"))
	{
		return 1;
	}

	else
	{
		return 2;
	}

} //----- Fin de Méthode


int DrawController::addFigure ( char cmd , char * params)
{
	char * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
	long coordX1, coordX2, coordY1, coordY2, radius;


	if (cmd == 'C')
	{

        firstEntry = strtok(params, " ");
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");

		if ( firstEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide name.\r\n";
		}
		else if (secondEntry == NULL || thirdEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide center.\r\n";
		}
		else if ( fourthEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide radius.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry,NULL,10);
			coordY1 = strtol(thirdEntry,NULL,10);
			radius = strtol(fourthEntry,NULL,10);

<<<<<<< Updated upstream
			Figure * myFigure;
			figuresList.insert ( std::pair<char *,Figure *>(firstEntry, myFigure) );
			//AddCommand * myCommand;
			//commandsList.push();


			cout << "#Circle " << firstEntry << " of center (" << coordX1 << ", " << coordY1 << ") and radius " << radius << " has been created.\r\n";

			return "OK\r\n";

=======
>>>>>>> Stashed changes
			// Circle creation method
			Circle test = Circle(firstEntry, coordX1, coordY1, radius);
			////test.ToString();
			cout << test;
		}
		return 0;
	}
	if (cmd == 'R')
	{
		firstEntry = strtok(params, " ");
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		if ( firstEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide name.\r\n";
		}
		else if (secondEntry == NULL || thirdEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide first point.\r\n";
		}
		else if ( fourthEntry == NULL || fifthEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide second point.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry,NULL,10);
			coordY1 = strtol(thirdEntry,NULL,10);
			coordX2 = strtol(fourthEntry,NULL,10);
			coordY2 = strtol(fifthEntry,NULL,10);

			// Rectangle creation method
			Rectangle test = Rectangle(firstEntry, Point(coordX1, coordY1), Point(coordX2, coordY2));
			////test.ToString();
			cout << test;
		}
		return 0;
	}
	if (cmd == 'L')
	{
		firstEntry = strtok(params, " ");
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		if ( firstEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide name.\r\n";
		}
		else if (secondEntry == NULL || thirdEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide first point.\r\n";
		}
		else if ( fourthEntry == NULL || fifthEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide second point.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry,NULL,10);
			coordY1 = strtol(thirdEntry,NULL,10);
			coordX2 = strtol(fourthEntry,NULL,10);
			coordY2 = strtol(fifthEntry,NULL,10);
			
			// Line creation method
			Line test = Line(firstEntry, Point(coordX1, coordY1), Point(coordX2, coordY2));
			////test.ToString();
			cout << test;
		}
		return 0;
	}
	if (cmd == 'P')
	{
		int i = ZERO;
		vector<Point> myVector;
		firstEntry = strtok(params, " ");
		if (firstEntry == NULL)
		{
			cout << "ERR\r\n";
			cout << "# Invalide name.\r\n";
			return 1;
		}

		while (ONE)
		{
			secondEntry = strtok(NULL, " ");
			thirdEntry = strtok(NULL, " "); 
			if (thirdEntry == NULL)
			{
				break;
			}
			myVector.push_back(Point(strtol(secondEntry,NULL,10), strtol(thirdEntry,NULL,10)));
			i++;
		}

		if ( secondEntry != NULL )
		{
			cout << "ERR\r\n";
			cout << "# Invalide " << i + ONE << "th point.\r\n";
			return 1;
		}

		Polyline test = Polyline(firstEntry, myVector);
		//test.ToString();
		cout << test;
		myVector.clear();
		return 0;
	}
}
