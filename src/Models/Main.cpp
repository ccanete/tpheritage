#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Figure.h"
#include "Polyline.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"

//#define MAP
#define ZERO 0
#define ONE 1
#define TWO 2


using namespace std;

int main (  )
// Program main fonction that read the user's 
// entries and execute these commands.
{
	// Variables initialization 
	string line;
	char * textChain;
	char * command, * firstEntry, * secondEntry, * thirdEntry, * fourthEntry, * fifthEntry;
	long coordX1, coordX2, coordY1, coordY2, radius;
	char ** names, ** entries;
	vector<Point> myVector;

	// Start cycle
	while (true)
	{
		// Reading user's entry
		getline(cin,line);
		// Transformation 
		textChain = ( char * ) line.c_str();
		command = strtok(textChain, " ");
		#ifdef MAP
			cout << "command : " << command << "\r\n";
		#endif

		/*---------- COMMAND CIRCLE ----------*/
		if (!strcmp(command,"C"))
		{
			firstEntry = strtok(NULL, " ");
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
				Circle test = Circle(firstEntry, coordX1, coordY1, radius);
				////test.ToString();
				cout << test;
			}
		}

		/*----------COMMAND RECTANGLE ----------*/
		else if (!strcmp(command,"R"))
		{
			firstEntry = strtok(NULL, " ");
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
		}

		/*----------COMMAND LINE----------*/
		else if (!strcmp(command,"L"))
		{
			firstEntry = strtok(NULL, " ");
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
		}

		/*----------COMMAND POLY-LINE----------*/
		else if (!strcmp(command,"PL") )
		{
			int i = ZERO;
			firstEntry = strtok(NULL, " ");
			if (firstEntry == NULL)
			{
				cout << "ERR\r\n";
				cout << "# Invalide name.\r\n";
				continue;
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
				continue;
			}

			Polyline test = Polyline(firstEntry, myVector);
			//test.ToString();
			cout << test;
			myVector.clear();
		}

		/*----------COMMAND SELECTION----------*/
		else if (!strcmp(command, "S"))
		{
			firstEntry = strtok(NULL, " ");
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

				cout << "OK\r\n";
				cout << "# Selection " << firstEntry << " of coordinates (" << coordX1 << ", " << coordY1
						 << ") and (" << coordX2 << ", " << coordY2 << ") has been created.\r\n";

				// Selection creation method
				//(firstEntry, coordX1, coordY1, coordX2, coordY2);
			}
		}

		/*----------COMMAND DELETE----------*/
		else if (!strcmp(command,"DELETE"))
		{
			int i = ZERO;
			while (ONE)
			{
				firstEntry = strtok(NULL, " "); 
				if (firstEntry == NULL)
				{
					break;
				}
				names[i] = firstEntry;
				i++;
			}

			cout << "OK\r\n";
			cout << "# The object " << firstEntry << " has been deleted.\r\n";


			// TO BE CONTINUED
		}

		/*----------COMMAND MOVE----------*/
		else if (!strcmp(command,"MOVE"))
		{
			firstEntry = strtok(NULL, " ");
			secondEntry = strtok(NULL, " "); 
			thirdEntry = strtok(NULL, " ");

			if ( firstEntry == NULL)
			{
				cout << "ERR\r\n";
				cout << "# Invalide name.\r\n";
			}
			else if (secondEntry == NULL || thirdEntry == NULL)
			{
				cout << "ERR\r\n";
				cout << "# Invalide values.\r\n";
			}
			else
			{
				coordX1 = strtol(secondEntry,NULL,10);
				coordY1 = strtol(thirdEntry,NULL,10);

				cout << "OK\r\n";
				cout << "# The object " << firstEntry << " has been moved by " << coordX1 << " over the x-axis and " << coordY1
						 << " over the y-axis.\r\n";
				
				// Move method
				//(firstEntry, coordX1, coordY2);
			}
		}

		/*----------COMMAND LIST----------*/
		else if (!strcmp(command,"LIST"))
		{
			cout << "OK\r\n";
			cout << "# This is the list of all object currently existing.\r\n";
			
			// Move method

		}

		/*----------COMMAND UNDO----------*/
		else if (!strcmp(command,"UNDO"))
		{
			cout << "OK\r\n";
			cout << "# The last action has been canceled.\r\n";
			
			// Undo method
		}
		
		/*----------COMMAND REDO----------*/
		else if (!strcmp(command,"REDO"))
		{
			cout << "OK\r\n";
			cout << "# The last action has been restored.\r\n";
			
			// Redo method
		}
		
		/*----------COMMAND LOAD----------*/
		else if (!strcmp(command,"LOAD"))
		{
			firstEntry = strtok(NULL, " ");
			secondEntry = strtok(NULL, " ");
			if ( firstEntry == NULL || secondEntry != NULL)
			{
				cout << "ERR\r\n";
				cout << "# Invalide file name.\r\n";
			}
			else
			{
				cout << "OK\r\n";
				cout << "# The file " << firstEntry << " has been loaded.\r\n";
			}
			// Load method
			//(firstEntry);
		}
		
		/*----------COMMAND SAVE----------*/
		else if (!strcmp(command,"SAVE"))
		{
			firstEntry = strtok(NULL, " ");
			secondEntry = strtok(NULL, " ");
			if ( firstEntry == NULL || secondEntry != NULL)
			{
				cout << "ERR\r\n";
				cout << "# Invalide file name.\r\n";
			}
			else
			{
				cout << "OK\r\n";
				cout << "# The file " << firstEntry << " has been saved.\r\n";
			}
			// Save method
			//(firstEntry;
		}
		
		/*----------COMMAND CLEAR----------*/
		else if (!strcmp(command,"CLEAR"))
		{
			cout << "OK\r\n";
			cout << "# All objects have been deleted.\r\n";
			
			// Clear method
			//();
		}
		/*----------COMMAND EXIT----------*/
		else if (!strcmp(command,"EXIT"))
		{
			cout << "\r\n# The program is being closed.";
			// Exit method
			//();
			return 0;
		}
	}
}
