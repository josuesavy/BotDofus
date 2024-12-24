#ifndef CHARACTERSELECTIONWITHREMODELMESSAGE_H
#define CHARACTERSELECTIONWITHREMODELMESSAGE_H

#include "src/protocol/network/types/data/game/character/choice/RemodelingInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/character/choice/CharacterSelectionMessage.h"

class CharacterSelectionWithRemodelMessage : public CharacterSelectionMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSelectionWithRemodelMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSelectionWithRemodelMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSelectionWithRemodelMessage(FuncTree tree);
  CharacterSelectionWithRemodelMessage();

  RemodelingInformation remodel;

private:
  void _remodeltreeFunc(Reader *input);

  FuncTree _remodeltree;
};

#endif // CHARACTERSELECTIONWITHREMODELMESSAGE_H