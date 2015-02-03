/*************************************************************************
                           DrawController  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <DrawController> (fichier DrawController.cpp) --

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdlib>


//------------------------------------------------------ Include personnel
#include "DrawController.h"

//-------------------------------------------- Constructeurs - destructeur

DrawController::DrawController ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DrawController>" << endl;
#endif
        //std::map <char *,Figure *> figuresList;

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


std::string DrawController::ExecuteCommand ( std::string commandInput )
//Algorithme :
//
{

	//Transform users command
	char * textChain = ( char * ) commandInput.c_str();
	char * command = strtok(textChain, " ");
	char * params = NULL;
	params = strtok(NULL,"\r");

	#ifdef MAP
		cout << "command : " << command << "\r\n" << "params : " << params << "\r\n";
	#endif

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
		return addFigure('L', params);
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
		return "EXIT\r\n# The program is being closed.";
	}

	else
	{
		return "ERR\r\n# Unknown command\n";
	}

} //----- Fin de Méthode


std::string DrawController::addFigure ( char cmd , char * params)
{
	char * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
	long coordX1, coordX2, coordY1, coordY2, radius;


	if(cmd == 'C')
	{

        firstEntry = strtok(params, " ");
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");

		if ( firstEntry == NULL)
		{
			cout << "ERR\r\n" << "# Invalide name.\r\n";
		}
		else if (secondEntry == NULL || thirdEntry == NULL)
		{
			cout << "ERR\r\n" << "# Invalide center.\r\n";
		}
		else if ( fourthEntry == NULL)
		{
			cout << "ERR\r\n" << "# Invalide radius.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry,NULL,10);
			coordY1 = strtol(thirdEntry,NULL,10);
			radius = strtol(fourthEntry,NULL,10);

			Figure * myFigure;
			figuresList.insert ( std::pair<char *,Figure *>(firstEntry, myFigure) );	


			cout << "#Circle " << firstEntry << " of center (" << coordX1 << ", " << coordY1 << ") and radius " << radius << " has been created.\r\n";

			return "OK\r\n";

			// Circle creation method
			//(firstEntry, coordX1, coordX2, radius);
		}
	}
	if(cmd == 'R')
	{
		firstEntry = strtok(params, " ");
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		if ( firstEntry == NULL)
		{
			cout << "ERR\r\n" << "# Invalide name.\r\n";
		}
		else if (secondEntry == NULL || thirdEntry == NULL)
		{
			cout << "ERR\r\n" << "# Invalide first point.\r\n";
		}
		else if ( fourthEntry == NULL || fifthEntry == NULL)
		{
			cout << "ERR\r\n" << "# Invalide second point.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry,NULL,10);
			coordY1 = strtol(thirdEntry,NULL,10);
			coordX2 = strtol(fourthEntry,NULL,10);
			coordY2 = strtol(fifthEntry,NULL,10);

			cout << "OK\r\n" <<
					"# Rectangle " << 
					firstEntry << 
					" of coordinates (" << 
					coordX1 << 
					", " << 
					coordY1 <<
					") and (" << 
					coordX2 << 
					", " << 
					coordY2 << 
					") has been created.\r\n";
			return "OK\r\n";

			// Rectangle creation method
			//(firstEntry, coordX1, coordY1, coordX2, coordY2);
		}		
	}
	if(cmd == 'L')
	{
		firstEntry = strtok(params, " ");
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		if ( firstEntry == NULL)
		{
			cout << "ERR\r\n" << 
					"# Invalide name.\r\n";
		}
		else if (secondEntry == NULL || thirdEntry == NULL)
		{
			cout << "ERR\r\n" <<
					"# Invalide first point.\r\n";
		}
		else if ( fourthEntry == NULL || fifthEntry == NULL)
		{
			cout << "ERR\r\n" <<
					"# Invalide second point.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry,NULL,10);
			coordY1 = strtol(thirdEntry,NULL,10);
			coordX2 = strtol(fourthEntry,NULL,10);
			coordY2 = strtol(fifthEntry,NULL,10);

			cout << "OK\r\n" 
					"# Line " << firstEntry << " passing by (" << coordX1 << ", " << coordY1 <<
					") and (" << coordX2 << ", " << coordY2 << ") has been created.\r\n";
			return "OK\r\n";
			// Line creation method
			//(firstEntry, coordX1, coordY1, coordX2, coordY2);
		}
		
	}
	if(cmd == 'P')
	{
		long coordinates [10]; // Max numbers of points for a polyline ?

		int i = ZERO;
		firstEntry = strtok(params, " ");
		if (firstEntry == NULL)
		{
			cout << "ERR\r\n" << 
					"# Invalide name.\r\n";
			//continue;
		}

		while (ONE)
		{
			secondEntry = strtok(NULL, " "); 
			if (secondEntry == NULL)
			{
				break;
			}
			coordinates[i] = strtol(secondEntry,NULL,10);
			i++;
		}

		if ( i%2 )
		{
			cout << "ERR\r\n" <<
					"# Invalide " << (i + ONE)/TWO << "th point.\r\n";
			//continue;
		}
		
		cout << "OK\r\n" <<
				"# Poly-line " << firstEntry << " passing by ";

		for (int j = ZERO; j < i - TWO; j += TWO)
		{
			cout << "(" << coordinates[j] << ", " << coordinates[j+ONE] << "), ";
		}
		cout << "(" << coordinates[i - TWO] << ", " << coordinates[i - ONE] << ")";
		cout <<  " has been created.\r\n";
		return "OK\r\n";

		// TO BE CONTINUED
		
	}
	return NULL;
}
