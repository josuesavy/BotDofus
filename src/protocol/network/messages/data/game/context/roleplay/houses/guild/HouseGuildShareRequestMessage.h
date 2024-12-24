#ifndef HOUSEGUILDSHAREREQUESTMESSAGE_H
#define HOUSEGUILDSHAREREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HouseGuildShareRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseGuildShareRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseGuildShareRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseGuildShareRequestMessage(FuncTree tree);
  HouseGuildShareRequestMessage();

  uint houseId;
  uint instanceId;
  bool enable;
  uint rights;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
  void _enableFunc(Reader *input);
  void _rightsFunc(Reader *input);
};

#endif // HOUSEGUILDSHAREREQUESTMESSAGE_H