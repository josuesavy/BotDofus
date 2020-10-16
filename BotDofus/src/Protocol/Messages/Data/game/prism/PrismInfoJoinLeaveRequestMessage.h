#ifndef PRISMINFOJOINLEAVEREQUESTMESSAGE_H
#define PRISMINFOJOINLEAVEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismInfoJoinLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismInfoJoinLeaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismInfoJoinLeaveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismInfoJoinLeaveRequestMessage(FuncTree tree);
  PrismInfoJoinLeaveRequestMessage();

  bool join;

private:
  void _joinFunc(Reader *input);
};

#endif // PRISMINFOJOINLEAVEREQUESTMESSAGE_H