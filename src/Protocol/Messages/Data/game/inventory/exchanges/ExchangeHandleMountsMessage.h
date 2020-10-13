#ifndef EXCHANGEHANDLEMOUNTSMESSAGE_H
#define EXCHANGEHANDLEMOUNTSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeHandleMountsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeHandleMountsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeHandleMountsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeHandleMountsMessage(FuncTree tree);
  ExchangeHandleMountsMessage();

  int actionType;
  QList<uint> ridesId;

private:
  void _actionTypeFunc(Reader *input);
  void _ridesIdtreeFunc(Reader *input);
  void _ridesIdFunc(Reader *input);

  FuncTree _ridesIdtree;
};

#endif // EXCHANGEHANDLEMOUNTSMESSAGE_H