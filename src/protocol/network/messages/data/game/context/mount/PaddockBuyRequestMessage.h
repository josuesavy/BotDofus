#ifndef PADDOCKBUYREQUESTMESSAGE_H
#define PADDOCKBUYREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaddockBuyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockBuyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockBuyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockBuyRequestMessage(FuncTree tree);
  PaddockBuyRequestMessage();

  double proposedPrice;

private:
  void _proposedPriceFunc(Reader *input);
};

#endif // PADDOCKBUYREQUESTMESSAGE_H