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
        std::string out = drawController.ExecuteCommand(commandInput);
        cout << out << endl;
        if(out == "EXIT\r\n# The program is being closed.")
        {
            break;
        }
	}
    return 0;
}