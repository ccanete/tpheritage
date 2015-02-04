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
#include <fstream>


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

int DrawController::AddFigureToList (string name, Figure * figureAdded)
{
	mapFigure.insert ( std::pair<string,Figure *>(name,figureAdded) );
	return 0;

}


int DrawController::RemoveFigureFromList (string name)
{
	return 0;
}


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
		return createSelection(params);
	}

	/*----------COMMAND DELETE----------*/
	else if (!strcmp(command,"DELETE"))
	{
		return deleteFigures(params);
	}

	/*----------COMMAND MOVE----------*/
	else if (!strcmp(command,"MOVE"))
	{
		//return move(params);
	}

	/*----------COMMAND LIST----------*/
	else if (!strcmp(command,"LIST"))
	{
		return list();
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
		return saveFigures(params);
	}
	
	/*----------COMMAND CLEAR----------*/
	else if (!strcmp(command,"CLEAR"))
	{
		//return clear();
	}
	/*----------COMMAND EXIT----------*/
	else if (!strcmp(command,"EXIT"))
	{
		return ONE;
	}

	else
	{
		return TWO;
	}

} //----- Fin de Méthode


int DrawController::addFigure( char cmd , char * params)
{
	char * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
	signed long coordX1, coordX2, coordY1, coordY2;
	long radius;
	char * cleanParams = new char[strlen(params)];
	strcpy(cleanParams,params);


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

			// Circle creation method
			
			AddCommand newCircle ('C', cleanParams);
			newCircle.Do();
		}
		return ZERO;
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
		}
		return ZERO;
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
		}
		return ZERO;
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
			return ONE;
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
			return ONE;
		}

		Polyline test = Polyline(firstEntry, myVector);
		//test.ToString();
		myVector.clear();
		return ZERO;
	}
}

int DrawController::createSelection( char * params )
{
	char * firstEntry = strtok(params, " ");
	char * secondEntry = strtok(NULL, " "); 
	char * thirdEntry = strtok(NULL, " ");
	char * fourthEntry = strtok(NULL, " ");
	char * fifthEntry = strtok(NULL, " ");

	if ( firstEntry == NULL)
	{
		cout << "ERR\r\n";
		cout << "# Invalide name.\r\n";
		return -ONE;
	}
	else if (secondEntry == NULL || thirdEntry == NULL)
	{
		cout << "ERR\r\n";
		cout << "# Invalide first point.\r\n";
		return -ONE;
	}
	else if ( fourthEntry == NULL || fifthEntry == NULL)
	{
		cout << "ERR\r\n";
		cout << "# Invalide second point.\r\n";
		return -ONE;
	}
	else
	{
		signed long coordX1 = strtol(secondEntry,NULL,10);
		signed long coordY1 = strtol(thirdEntry,NULL,10);
		signed long coordX2 = strtol(fourthEntry,NULL,10);
		signed long coordY2 = strtol(fifthEntry,NULL,10);

		// Selection creation method
		//Selection test = Selection(firstEntry, Point(coordX1, coordY1), Point(coordX2, coordY2), mapFigure);
		////test.ToString();
	return ZERO;
	}
}

int DrawController::deleteFigures( char * params )
{
	// SEARCHING DOUBLES 
	vector<string> v;
	char * firstEntry = strtok(params, " ");
	if (firstEntry == NULL)
	{
		cout << "ERR\r\n";
    	cout << "# No element\r\n";
    	return -ONE;
	}
	else
	{
		v.push_back(firstEntry);
	}
	int i = 0;
	while ( (firstEntry = strtok(NULL, " ")) != NULL )
	{
		cout << "Vecteur pos" << i << "\r\n";
		v.push_back(firstEntry);
		i++;
	}
	sort( v.begin(), v.end() );
 	vector<string>::iterator it;

	if ( i > 0)
	{
		i = 0;
		for (it=v.begin(); it != v.end() - ONE; it++)
	    {
	    	cout << "Recherche doublons\r\n";
	    	i++;
	    	if (*it == *(it+ONE))
	    	{
	    		cout << "ERR\r\n";
	    		cout << "# " << *it << " is repeated\r\n";
	    		return -ONE;
	    	} 
	    }
	}
	i = 0;
	for (it=v.begin(); it != v.end(); it++)
    {
    	i++;
	    cout << "Recherche dans les maps\r\n";
    	if ( mapSelection.find(*it) == mapSelection.end() && mapFigure.find(*it) == mapFigure.end() )
    	{
    		cout << "ERR\r\n";
    		cout << "# " << *it << " doesn't exist\r\n";
    		return -ONE;
    	}
    }

    // DELETE ELEMENTS 
    map<string, Selection *>::iterator itSel;
    map<string, Figure *>::iterator itFig;
    /*for (it=v.begin(); it != v.end() - ONE; it++)
    {
    	
    	if ( (itSel = mapSelection.find(*it)) != mapSelection.end() )
    	{
    		itSel->second->GetFigureVector();
    	}
    	else if ( (itFig = mapFigure.find(*it)) != mapFigure.end() )
    	{
    		itFig->second
    	}
    }*/
    return 0;
}

int DrawController::list()
{
	for (map<string,Figure *>::iterator it = mapFigure.begin(); it != mapFigure.end(); it++)
	{
		cout << it->second->ToString();	
	}
	return 0;
}

int DrawController::saveFigures( char * params )
{
	char * firstEntry = strtok(params, " ");
	char * secondEntry = strtok(NULL, " ");
	if ( firstEntry == NULL || secondEntry != NULL)
	{
		cout << "ERR\r\n";
		cout << "# Invalide file name.\r\n";
		return -ONE;
	}
	else
	{
		// Save method
		ofstream fichier(firstEntry, ios::out | ios::trunc);  // file writtable

        if(fichier)
        {
 			for (map<string,Figure *>::iterator it = mapFigure.begin(); it != mapFigure.end(); it++)
    		{
    			fichier << it->second->ToString();
    		}
                fichier.close();
        }
        else
        {
			cerr << "# File cannot be opened !" << endl;
			return -ONE;
        }
		cout << "OK\r\n";
		cout << "# The file " << firstEntry << " has been saved.\r\n";
		return ZERO;
	}
}