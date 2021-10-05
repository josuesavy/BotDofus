#ifndef CHARACTERSELECTEDFORCEMESSAGE_H
#define CHARACTERSELECTEDFORCEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterSelectedForceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterSelectedForceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterSelectedForceMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterSelectedForceMessage(FuncTree tree);
  CharacterSelectedForceMessage();

  int id;

private:
  void _idFunc(Reader *input);
};

#endif // CHARACTERSELECTEDFORCEMESSAGE_H