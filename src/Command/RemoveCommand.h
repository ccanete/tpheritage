/*************************************************************************
                           RemoveCommand  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <RemoveCommand> (fichier ${file_name}) ------
#if ! defined ( RemoveCommand_H )
#define RemoveCommand_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <RemoveCommand>
//
//
//------------------------------------------------------------------------ 

class RemoveCommand : public Command
{
//----------------------------------------------------------------- PUBLIC

public:

    RemoveCommand (Figure* figure, long dx, long dy);
    /**
     * @constructor
     * @param figure The objet that will Remove
     * @param dx Delta x
     * @param dy Delta y
     */

    virtual bool DO();

    virtual bool Undo();

    virtual ~RemoveCommand ( );


private:
//------------------------------------------------------- Méthodes privées
    Figure* figure_;
    long dx_, dy_;

};

//----------------------------------------- Types dépendants de <RemoveCommand>

#endif // RemoveCommand_H
