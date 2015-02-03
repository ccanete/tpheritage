/*************************************************************************
                           MoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <MoveCommand> (fichier ${file_name}) ------
#if ! defined ( MoveCommand_H )
#define MoveCommand_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <MoveCommand>
//
//
//------------------------------------------------------------------------ 

class MoveCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    MoveCommand (Figure* figure, long dx, long dy);
    /**
     * @constructor
     * @param figure The objet that will move
     * @param dx Delta x
     * @param dy Delta y
     */

    virtual bool DO();

    virtual bool Undo();

    virtual ~MoveCommand ( );


private:
//------------------------------------------------------- Méthodes privées
    Figure* figure_;
    long dx_, dy_;

};

//----------------------------------------- Types dépendants de <MoveCommand>

#endif // MoveCommand_H
