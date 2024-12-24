#ifndef EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE_H
#define EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeBidHouseGenericItemRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseGenericItemRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseGenericItemRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseGenericItemRemovedMessage(FuncTree tree);
  ExchangeBidHouseGenericItemRemovedMessage();

  uint objGenericId;

private:
  void _objGenericIdFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEGENERICITEMREMOVEDMESSAGE_H