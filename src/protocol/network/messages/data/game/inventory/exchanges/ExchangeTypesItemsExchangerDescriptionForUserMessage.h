#ifndef EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H
#define EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/BidExchangerObjectInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  uint objectGID;
  uint objectType;
  QList<QSharedPointer<BidExchangerObjectInfo>> itemTypeDescriptions;

private:
  void _objectGIDFunc(Reader *input);
  void _objectTypeFunc(Reader *input);
  void _itemTypeDescriptionstreeFunc(Reader *input);
  void _itemTypeDescriptionsFunc(Reader *input);

  FuncTree _itemTypeDescriptionstree;
};

#endif // EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H