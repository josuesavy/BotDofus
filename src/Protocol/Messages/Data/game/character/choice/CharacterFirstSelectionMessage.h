#ifndef CHARACTERFIRSTSELECTIONMESSAGE_H
#define CHARACTERFIRSTSELECTIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/character/choice/CharacterSelectionMessage.h"

class CharacterFirstSelectionMessage : public CharacterSelectionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterFirstSelectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterFirstSelectionMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterFirstSelectionMessage(FuncTree tree);
  CharacterFirstSelectionMessage();

  bool doTutorial;

private:
  void _doTutorialFunc(Reader *input);
};

#endif // CHARACTERFIRSTSELECTIONMESSAGE_H