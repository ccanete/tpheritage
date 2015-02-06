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


string DrawController::ExecuteCommand ( string commandInput )
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
		return move(params);
	}

	/*----------COMMAND LIST----------*/
	else if (!strcmp(command,"LIST"))
	{
		return list();
	}

	/*----------COMMAND UNDO----------*/
	else if (!strcmp(command,"UNDO"))
	{
		return undo();
	}
	
	/*----------COMMAND REDO----------*/
	else if (!strcmp(command,"REDO"))
	{
		return redo();
	}
	
	/*----------COMMAND LOAD----------*/
	else if (!strcmp(command,"LOAD"))
	{
		return loadFigures(params);
	}
	
	/*----------COMMAND SAVE----------*/
	else if (!strcmp(command,"SAVE"))
	{
		return saveFigures(params);
	}
	
	/*----------COMMAND CLEAR----------*/
	else if (!strcmp(command,"CLEAR"))
	{
		return clear();
	}
	/*----------COMMAND EXIT----------*/
	else if (!strcmp(command,"EXIT"))
	{
		return "# The program is being closed.\r\n";
	}

	else
	{
		return "ERR\r\n# Unknown command\r\n";
	}
} //----- Fin de Méthode


string DrawController::addFigure( char cmd , char * params)
{
	char * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
	signed long coordX1, coordX2, coordY1, coordY2;
	long radius;
	char cleanParams [100];
	if (params != NULL)
	strcpy(cleanParams,params);

	firstEntry = strtok(params, " ");
	if ( firstEntry == NULL)
	{
		return "ERR\r\n# Invalide name.\r\n";
	}
	else if ( (mapFigure.find(firstEntry) != mapFigure.end()) || (mapSelection.find(firstEntry) != mapSelection.end()) )
	{
		return "ERR\r\n# Figure " + (string)firstEntry + " is already existing\r\n";
	}

	if (cmd == 'C')
	{
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");

		if (secondEntry == NULL || thirdEntry == NULL)
		{
			return "ERR\r\n# Invalide center.\r\n";
		}
		else if ( fourthEntry == NULL)
		{
			return "ERR\r\n# Invalide radius.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry, NULL, 10);
			coordY1 = strtol(thirdEntry, NULL, 10);
			radius = strtol(fourthEntry, NULL, 10);

			// Figure creation method
			
			AddCommand * addCmd = new AddCommand(&mapFigure, &mapSelection, 'C', cleanParams);
			addCmd->Do();

			if (commandsListUndo.size() >= 20)
			{
				delete [] commandsListUndo.back();
				commandsListUndo.pop_back();
			}
			commandsListUndo.push_front(addCmd);
			while (!commandsListRedo.empty())
			{
				delete commandsListRedo.top();
				commandsListRedo.pop();
			}
			return "OK\r\n" + mapFigure.find(firstEntry)->second->Display();
		}
	}
	if (cmd == 'R')
	{
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		if (secondEntry == NULL || thirdEntry == NULL)
		{
			return "ERR\r\n# Invalide first point.\r\n";
		}
		else if ( fourthEntry == NULL || fifthEntry == NULL)
		{
			return "ERR\r\n# Invalide second point.\r\n";
		}
		else
		{
			coordX1 = strtol(secondEntry, NULL, 10);
			coordY1 = strtol(thirdEntry, NULL, 10);
			coordX2 = strtol(fourthEntry, NULL, 10);
			coordY2 = strtol(fifthEntry, NULL, 10);

			// Figure creation method
			
			AddCommand * addCmd = new AddCommand(&mapFigure, &mapSelection, 'R', cleanParams);
			addCmd->Do();
			if (commandsListUndo.size() >= 20)
			{
				delete [] commandsListUndo.back();
				commandsListUndo.pop_back();
			}
			commandsListUndo.push_front(addCmd);
			while (!commandsListRedo.empty())
			{
				delete commandsListRedo.top();
				commandsListRedo.pop();
			}
			return "OK\r\n" + mapFigure.find(firstEntry)->second->Display();
		}
	}
	if (cmd == 'L')
	{
		secondEntry = strtok(NULL, " "); 
		thirdEntry = strtok(NULL, " ");
		fourthEntry = strtok(NULL, " ");
		fifthEntry = strtok(NULL, " ");

		if (secondEntry == NULL || thirdEntry == NULL)
		{
			return "ERR\r\n# Invalide first point.\r\n";
		}
		else if ( fourthEntry == NULL || fifthEntry == NULL)
		{
			return "ERR\r\n# Invalide second point.\r\n";
		}
		else
		{

			// Figure creation method
			coordX1 = strtol(secondEntry, NULL, 10);
			coordY1 = strtol(thirdEntry, NULL, 10);
			coordX2 = strtol(fourthEntry, NULL, 10);
			coordY2 = strtol(fifthEntry, NULL, 10);
			AddCommand * addCmd = new AddCommand(&mapFigure, &mapSelection, 'L', cleanParams);
			addCmd->Do();
			if (commandsListUndo.size() >= 20)
			{
				delete [] commandsListUndo.back();
				commandsListUndo.pop_back();
			}
			commandsListUndo.push_front(addCmd);
			while (!commandsListRedo.empty())
			{
				delete commandsListRedo.top();
				commandsListRedo.pop();
			}
			return "OK\r\n" + mapFigure.find(firstEntry)->second->Display();
		}
	}
	if (cmd == 'P')
	{
		int i = ZERO;
		vector<Point> myVector;

		while (ONE)
		{
			secondEntry = strtok(NULL, " ");
			thirdEntry = strtok(NULL, " "); 
			if (thirdEntry == NULL)
			{
				break;
			}
			myVector.push_back(Point(strtol(secondEntry, NULL, 10), strtol(thirdEntry, NULL, 10)));
			i++;
		}

		if ( secondEntry != NULL )
		{
			return "ERR\r\n# Invalide " + std::to_string(i + ONE) + "th point.\r\n";
		}

		// Figure creation method
		
		AddCommand * addCmd = new AddCommand(&mapFigure, &mapSelection, 'P', cleanParams);
		addCmd->Do();
		if (commandsListUndo.size() >= 20)
		{
			delete [] commandsListUndo.back();
			commandsListUndo.pop_back();
		}
		commandsListUndo.push_front(addCmd);
		while (!commandsListRedo.empty())
		{
			delete commandsListRedo.top();
			commandsListRedo.pop();
		}
		return "OK\r\n" + mapFigure.find(firstEntry)->second->Display();
	}
	else
	{
		return "";
	}
}

string DrawController::createSelection( char * params )
{
	char * firstEntry = strtok(params, " ");
	char * secondEntry = strtok(NULL, " "); 
	char * thirdEntry = strtok(NULL, " ");
	char * fourthEntry = strtok(NULL, " ");
	char * fifthEntry = strtok(NULL, " ");

	if ( firstEntry == NULL)
	{
		return "ERR\r\n# Invalide name.\r\n";
	}
	else if ( (mapFigure.find(firstEntry) != mapFigure.end()) || (mapSelection.find(firstEntry) != mapSelection.end()) )
	{
		return "ERR\r\n# Figure " + (string)firstEntry + " is already existing\r\n";
	}
	else if (secondEntry == NULL || thirdEntry == NULL)
	{
		return "ERR\r\n# Invalide first point.\r\n";
	}
	else if ( fourthEntry == NULL || fifthEntry == NULL)
	{
		return "ERR\r\n# Invalide second point.\r\n";
	}
	else
	{
		signed long coordX1 = strtol(secondEntry, NULL, 10);
		signed long coordY1 = strtol(thirdEntry, NULL, 10);
		signed long coordX2 = strtol(fourthEntry, NULL, 10);
		signed long coordY2 = strtol(fifthEntry, NULL, 10);

		// Selection creation method
		Selection * select = new Selection(firstEntry, Point(coordX1, coordY1), Point(coordX2, coordY2), mapFigure);
		mapSelection.insert(std::pair<string,Selection *>((string)firstEntry, select));
		return "OK\r\n" + mapSelection.find((string)firstEntry)->second->Display() + select->ToString();
	}
}

string DrawController::deleteFigures( char * params )
{
	// SEARCHING DOUBLES 
	vector<string> myVector;
	string figures;
	char * firstEntry = strtok(params, " ");
	if (firstEntry == NULL)
	{
    	return "ERR\r\n# No element\r\n";
	}
	else
	{
		myVector.push_back(firstEntry);
	}
	int i = 0;
	while ( (firstEntry = strtok(NULL, " ")) != NULL )
	{
		myVector.push_back(firstEntry);
		i++;
	}
	sort( myVector.begin(), myVector.end() );
 	vector<string>::iterator it;

	if ( i > 0)
	{
		i = 0;
		for (it=myVector.begin(); it != myVector.end() - ONE; it++)
	    {
	    	i++;
	    	if (*it == *(it+ONE))
	    	{
	    		return "ERR\r\n# " + *it + " is repeated\r\n";
	    	} 
	    }
	}
    // DELETE ELEMENTS 

	std::map<string, Selection *>::iterator itSelect;
    for (it=myVector.begin(); it != myVector.end(); it++)
	{
		if ((itSelect = mapSelection.find(*it)) != mapSelection.end())
		{
			figures += itSelect->second->ListElements();
			mapSelection.erase(*it);
		}
		else if (mapFigure.find(*it) != mapFigure.end())
		{
			figures += *it + " ";
		}
		else
		{	
			return "ERR\r\n# " + *it + " doesn't exist\r\n";
		}
	}
    RemoveCommand * rmvCmd = new RemoveCommand(&mapFigure, &mapSelection, (char *)figures.c_str());
	rmvCmd->Do();
	if (commandsListUndo.size() >= 20)
	{
		delete [] commandsListUndo.back();
		commandsListUndo.pop_back();
	}
	commandsListUndo.push_front(rmvCmd);
	while (!commandsListRedo.empty())
	{
		delete commandsListRedo.top();
		commandsListRedo.pop();
	}
    return "OK\r\n";
}

string DrawController::move( char * params )
{
	char * firstEntry = strtok(params, " ");
	char * secondEntry = strtok(NULL, " "); 
	char * thirdEntry = strtok(NULL, " ");
	signed long coordX = strtol(secondEntry, NULL, 10);
	signed long coordY = strtol(thirdEntry, NULL, 10);
	if ( mapFigure.find(firstEntry) != mapFigure.end() )
	{
		Figure * figure = mapFigure.find(firstEntry)->second;
		MoveCommand * mvCmd = new MoveCommand(figure, coordX, coordY);
		mvCmd->Do();
		if (commandsListUndo.size() >= 20)
		{
			delete [] commandsListUndo.back();
			commandsListUndo.pop_back();
		}
		commandsListUndo.push_front(mvCmd);
		while (!commandsListRedo.empty())
		{
			delete commandsListRedo.top();
			commandsListRedo.pop();
		}
	}
	else if ( mapSelection.find(firstEntry) != mapSelection.end() )
	{
		Selection * selection = mapSelection.find(firstEntry)->second;
		MoveCommand * mvCmd = new MoveCommand(selection, coordX, coordY);
		mvCmd->Do();
		if (commandsListUndo.size() >= 20)
		{
			delete [] commandsListUndo.back();
			commandsListUndo.pop_back();
		}
		commandsListUndo.push_front(mvCmd);
		while (!commandsListRedo.empty())
		{
			delete commandsListRedo.top();
			commandsListRedo.pop();
		}
	}	
	else//if ( mapFigure.find(firstEntry) == mapFigure.end() && mapSelection.find(firstEntry) == mapSelection.end() )
	{
    	return "ERR\r\n# " + (string)firstEntry + " doesn't exist\r\n";
	}
	return "OK\r\n# The object " + (string)firstEntry + " has been moved by " 
    		 + std::to_string(coordX) + " over the x-axis and " + std::to_string(coordY)
			 + " over the y-axis.\r\n";;
}

string DrawController::list()
{
	for (map<string,Figure *>::iterator it = mapFigure.begin(); it != mapFigure.end(); it++)
	{
		cout << it->second->ToString();	
	}
	return "";
}

string DrawController::undo()
{
	if (commandsListUndo.empty())
	{
		return "OK\r\n# No UNDO avaible.\r\n";
	}
	if (!commandsListUndo.front()->Undo())
	{
		commandsListUndo.front()->Do();
		return "ERR\r\n# Another figure with the same name isalready existing.\r\n";
	}
	commandsListRedo.push(commandsListUndo.front());
	commandsListUndo.pop_front();
	return "OK\r\n";
}

string DrawController::redo()
{
	if (commandsListRedo.empty())
	{
		return "OK\r\n# No REDO avaible.\r\n";
	}
	if (!commandsListRedo.top()->Do())
	{
		commandsListRedo.top()->Undo();
		return "ERR\r\n# Another figure with the same name isalready existing.\r\n";
	}
	commandsListUndo.push_front(commandsListRedo.top());
	commandsListRedo.pop();
    return "OK\r\n";
}

string DrawController::loadFigures( char * params )
{
	char * firstEntry = strtok(params, " ");
	char * secondEntry = strtok(NULL, " ");
	char * text;
	char * name;
	string read;
	if ( firstEntry == NULL || secondEntry != NULL)
	{
		return "ERR\r\n# Invalide file name.\r\n";
	}
	ifstream file(firstEntry, ios::in);  // File readable
    if (file)
    {
		getline(file, read);
		text = (char *) read.c_str();
		strtok(text, " ");
		name = strtok(NULL, " ");
		map<string,Figure *>::iterator it = mapFigure.begin();
		while (ONE)
		{
			if ( *(strtok(text, " ")) == '#')
			{
				getline(file, read);
				text = (char *) read.c_str();
				strtok(text, " ");
				name = strtok(NULL, " ");
				continue;
			}
			if (it == mapFigure.end())
				break;
			if (it->second->GetName() == name)
			{
				return "ERR\r\n# Figure " + (string)name + " already existing.\r\n";
			}
			else if (it->second->GetName() < name)
			{
				it++;
			}
			else
			{
				if (!getline(file, read))
					break;
				text = (char *) read.c_str();
				strtok(text, " ");
				name = strtok(NULL, " ");
			}
		}
    }
    else
	{
		return "ERR\r\n# File cannot be opened !\r\n";
	}
	file.seekg(ios_base::beg);
	LoadCommand * ldCmd = new LoadCommand(&mapFigure, &mapSelection, file);
	if (!ldCmd->Do())
	{
		file.close();
		return "ERR\r\n# Another figure with the same name isalready existing.\r\n";
	}
	if (commandsListUndo.size() >= 20)
	{
		delete [] commandsListUndo.back();
		commandsListUndo.pop_back();
	}
	commandsListUndo.push_front(ldCmd);
	while (!commandsListRedo.empty())
	{
		delete commandsListRedo.top();
		commandsListRedo.pop();
	}
	file.close();
    return "OK\r\n";
}

string DrawController::saveFigures( char * params )
{
	char * firstEntry = strtok(params, " ");
	char * secondEntry = strtok(NULL, " ");
	if ( firstEntry == NULL || secondEntry != NULL)
	{
		return "ERR\r\n# Invalide file name.\r\n";
	}
	else
	{
		// Save method
		ofstream file(firstEntry, ios::out | ios::trunc);  // file writtable

        if(file)
        {
 			for (map<string,Figure *>::iterator it = mapFigure.begin(); it != mapFigure.end(); it++)
    		{
    			file << it->second->ToString();
    		}
                file.close();
        }
        else
        {
			return "ERR\r\n# File cannot be opened !\r\n";
        }
		return "OK\r\n# The file " + (string)firstEntry + " has been saved.\r\n";
	}
}

string DrawController::clear()
{
	for (map<string,Selection *>::iterator it = mapSelection.begin(); it != mapSelection.end(); it++)
	{
		delete it->second;
	}
	mapSelection.clear();
	ClearCommand * clCmd = new ClearCommand(&mapFigure);
	clCmd->Do();
	if (commandsListUndo.size() >= 20)
	{
		delete [] commandsListUndo.back();
		commandsListUndo.pop_back();
	}
	commandsListUndo.push_front(clCmd);
	while (!commandsListRedo.empty())
	{
		delete commandsListRedo.top();
		commandsListRedo.pop();
	}
    return "OK\r\n";
}