#ifndef EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE_H
#define EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeBidHouseGenericItemAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseGenericItemAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseGenericItemAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseGenericItemAddedMessage(FuncTree tree);
  ExchangeBidHouseGenericItemAddedMessage();

  uint objGenericId;

private:
  void _objGenericIdFunc(Reader *input);
};

#endif // EXCHANGEBIDHOUSEGENERICITEMADDEDMESSAGE_H