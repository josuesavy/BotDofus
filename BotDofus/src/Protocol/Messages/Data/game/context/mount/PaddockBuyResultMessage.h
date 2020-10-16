#ifndef PADDOCKBUYRESULTMESSAGE_H
#define PADDOCKBUYRESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PaddockBuyResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockBuyResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockBuyResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockBuyResultMessage(FuncTree tree);
  PaddockBuyResultMessage();

  double paddockId;
  bool bought;
  double realPrice;

private:
  void _paddockIdFunc(Reader *input);
  void _boughtFunc(Reader *input);
  void _realPriceFunc(Reader *input);
};

#endif // PADDOCKBUYRESULTMESSAGE_H