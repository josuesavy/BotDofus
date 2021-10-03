#ifndef EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeBidHouseInListRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseInListRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseInListRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseInListRemovedMessage(FuncTree tree);
  ExchangeBidHouseInListRemovedMessage();

  int itemUID;
  uint objectGID;
  uint objectType;

private:
  void _itemUIDFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
  void _objectTypeFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEINLISTREMOVEDMESSAGE_H