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
        string out = drawController.ExecuteCommand(commandInput);
        if (out == "# The program is being closed.\r\n")
        {
            cout << out;
            break;
        }
        else
        {
            cout << out;
        }
	}
    return 0;
}