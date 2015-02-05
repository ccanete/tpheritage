#include <iostream>

#include "Command/DrawController.h"

using namespace std;

int main()

/**
 * Enters the program in a REPL mode
 * Delegates everything to the controller, except for the exit
 */
 
{
	DrawController::DrawController drawController = DrawController::DrawController();
	cout << "# Hi !" << endl;
	cout << "# Welcome to Draw Controller" << endl;
	string commandInput;
	while (getline(cin, commandInput))
	{
        int out = drawController.ExecuteCommand(commandInput);
        if (out == 0)
        {
            cout << "OK\r\n";
        }
        else if (out == 1)
        {
        	cout << "EXIT\r\n# The program is being closed.\r\n";
            break;
        }
        else if (out == 2)
        {
        	cout << "ERR\r\n# Unknown command\r\n";
        }
	}
    return 0;
}