#ifndef HAAPICANCELBIDREQUESTMESSAGE_H
#define HAAPICANCELBIDREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class HaapiCancelBidRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HaapiCancelBidRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HaapiCancelBidRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HaapiCancelBidRequestMessage(FuncTree tree);
  HaapiCancelBidRequestMessage();

  double id;
  uint type;

private:
  void _idFunc(Reader *input);
  void _typeFunc(Reader *input);
};

#endif // HAAPICANCELBIDREQUESTMESSAGE_H