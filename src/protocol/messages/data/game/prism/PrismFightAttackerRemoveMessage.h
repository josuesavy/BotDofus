#ifndef PRISMFIGHTATTACKERREMOVEMESSAGE_H
#define PRISMFIGHTATTACKERREMOVEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismFightAttackerRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightAttackerRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightAttackerRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightAttackerRemoveMessage(FuncTree tree);
  PrismFightAttackerRemoveMessage();

  uint subAreaId;
  uint fightId;
  double fighterToRemoveId;

private:
  void _subAreaIdFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _fighterToRemoveIdFunc(Reader *input);
};

#endif // PRISMFIGHTATTACKERREMOVEMESSAGE_H