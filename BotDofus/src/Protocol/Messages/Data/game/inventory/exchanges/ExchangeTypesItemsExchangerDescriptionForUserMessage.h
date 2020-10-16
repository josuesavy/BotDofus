#ifndef EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H
#define EXCHANGETYPESITEMSEXCHANGERDESCRIPTIONFORUSERMESSAGE_H

#include "src/Protocol/Types/Data/game/data/items/BidExchangerObjectInfo.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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