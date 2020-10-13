#ifndef PRISMFIGHTJOINLEAVEREQUESTMESSAGE_H
#define PRISMFIGHTJOINLEAVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismFightJoinLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightJoinLeaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightJoinLeaveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightJoinLeaveRequestMessage(FuncTree tree);
  PrismFightJoinLeaveRequestMessage();

  uint subAreaId;
  bool join;

private:
  void _subAreaIdFunc(Reader *input);
  void _joinFunc(Reader *input);
};

#endif // PRISMFIGHTJOINLEAVEREQUESTMESSAGE_H