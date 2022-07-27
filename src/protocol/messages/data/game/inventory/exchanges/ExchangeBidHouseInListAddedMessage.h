#ifndef EXCHANGEBIDHOUSEINLISTADDEDMESSAGE_H
#define EXCHANGEBIDHOUSEINLISTADDEDMESSAGE_H

#include "src/protocol/types/data/game/data/items/effects/ObjectEffect.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeBidHouseInListAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeBidHouseInListAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeBidHouseInListAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeBidHouseInListAddedMessage(FuncTree tree);
  ExchangeBidHouseInListAddedMessage();

  int itemUID;
  uint objectGID;
  uint objectType;
  QList<QSharedPointer<ObjectEffect>> effects;
  QList<double> prices;

private:
  void _itemUIDFunc(Reader *input);
  void _objectGIDFunc(Reader *input);
  void _objectTypeFunc(Reader *input);
  void _effectstreeFunc(Reader *input);
  void _effectsFunc(Reader *input);
  void _pricestreeFunc(Reader *input);
  void _pricesFunc(Reader *input);

  FuncTree _effectstree;
  FuncTree _pricestree;
};

#endif // EXCHANGEBIDHOUSEINLISTADDEDMESSAGE_H