#ifndef HOUSEGUILDRIGHTSVIEWMESSAGE_H
#define HOUSEGUILDRIGHTSVIEWMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HouseGuildRightsViewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseGuildRightsViewMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseGuildRightsViewMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseGuildRightsViewMessage(FuncTree tree);
  HouseGuildRightsViewMessage();

  uint houseId;
  uint instanceId;

private:
  void _houseIdFunc(Reader *input);
  void _instanceIdFunc(Reader *input);
};

#endif // HOUSEGUILDRIGHTSVIEWMESSAGE_H