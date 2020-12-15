#ifndef EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H
#define EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H

#include "src/protocol/types/data/game/data/items/BidExchangerObjectInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeTypesItemsExchangerDescriptionForUserMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeTypesItemsExchangerDescriptionForUserMessage(FuncTree tree);
  ExchangeTypesItemsExchangerDescriptionForUserMessage();

  uint objectType;
  QList<QSharedPointer<BidExchangerObjectInfo>> itemTypeDescriptions;

private:
  void _objectTypeFunc(Reader *input);
  void _itemTypeDescriptionstreeFunc(Reader *input);
  void _itemTypeDescriptionsFunc(Reader *input);

  FuncTree _itemTypeDescriptionstree;
};

#endif // EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H