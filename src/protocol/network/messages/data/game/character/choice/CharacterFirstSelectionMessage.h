#ifndef CHARACTERFIRSTSELECTIONMESSAGE_H
#define CHARACTERFIRSTSELECTIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/character/choice/CharacterSelectionMessage.h"

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