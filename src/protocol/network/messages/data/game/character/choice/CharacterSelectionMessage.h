#ifndef CHARACTERSELECTIONMESSAGE_H
#define CHARACTERSELECTIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharacterSelectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSelectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSelectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSelectionMessage(FuncTree tree);
  CharacterSelectionMessage();

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // CHARACTERSELECTIONMESSAGE_H