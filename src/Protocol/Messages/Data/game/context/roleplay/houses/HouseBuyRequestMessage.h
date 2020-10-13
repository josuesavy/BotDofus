#ifndef HOUSEBUYREQUESTMESSAGE_H
#define HOUSEBUYREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HouseBuyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseBuyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseBuyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseBuyRequestMessage(FuncTree tree);
  HouseBuyRequestMessage();

  double proposedPrice;

private:
  void _proposedPriceFunc(Reader *input);
};

#endif // HOUSEBUYREQUESTMESSAGE_H