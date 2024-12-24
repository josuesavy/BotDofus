#ifndef EXCHANGESTARTEDWITHPODSMESSAGE_H
#define EXCHANGESTARTEDWITHPODSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/inventory/exchanges/ExchangeStartedMessage.h"

class ExchangeStartedWithPodsMessage : public ExchangeStartedMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeStartedWithPodsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeStartedWithPodsMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeStartedWithPodsMessage(FuncTree tree);
  ExchangeStartedWithPodsMessage();

  double firstCharacterId;
  uint firstCharacterCurrentWeight;
  uint firstCharacterMaxWeight;
  double secondCharacterId;
  uint secondCharacterCurrentWeight;
  uint secondCharacterMaxWeight;

private:
  void _firstCharacterIdFunc(Reader *input);
  void _firstCharacterCurrentWeightFunc(Reader *input);
  void _firstCharacterMaxWeightFunc(Reader *input);
  void _secondCharacterIdFunc(Reader *input);
  void _secondCharacterCurrentWeightFunc(Reader *input);
  void _secondCharacterMaxWeightFunc(Reader *input);
};

#endif // EXCHANGESTARTEDWITHPODSMESSAGE_H