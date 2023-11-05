#ifndef WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE_H
#define WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class WrapperObjectDissociateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_WrapperObjectDissociateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_WrapperObjectDissociateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_WrapperObjectDissociateRequestMessage(FuncTree tree);
  WrapperObjectDissociateRequestMessage();

  uint hostUID;
  uint hostPos;

private:
  void _hostUIDFunc(Reader *input);
  void _hostPosFunc(Reader *input);
};

#endif // WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE_H