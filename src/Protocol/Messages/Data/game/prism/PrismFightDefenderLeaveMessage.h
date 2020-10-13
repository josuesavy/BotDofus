#ifndef PRISMFIGHTDEFENDERLEAVEMESSAGE_H
#define PRISMFIGHTDEFENDERLEAVEMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismFightDefenderLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightDefenderLeaveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightDefenderLeaveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightDefenderLeaveMessage(FuncTree tree);
  PrismFightDefenderLeaveMessage();

  uint subAreaId;
  uint fightId;
  double fighterToRemoveId;

private:
  void _subAreaIdFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _fighterToRemoveIdFunc(Reader *input);
};

#endif // PRISMFIGHTDEFENDERLEAVEMESSAGE_H