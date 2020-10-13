#ifndef HOUSEKICKINDOORMERCHANTREQUESTMESSAGE_H
#define HOUSEKICKINDOORMERCHANTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HouseKickIndoorMerchantRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseKickIndoorMerchantRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseKickIndoorMerchantRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseKickIndoorMerchantRequestMessage(FuncTree tree);
  HouseKickIndoorMerchantRequestMessage();

  uint cellId;

private:
  void _cellIdFunc(Reader *input);
};

#endif // HOUSEKICKINDOORMERCHANTREQUESTMESSAGE_H