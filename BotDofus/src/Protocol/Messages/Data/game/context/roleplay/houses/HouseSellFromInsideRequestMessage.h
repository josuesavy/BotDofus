#ifndef HOUSESELLFROMINSIDEREQUESTMESSAGE_H
#define HOUSESELLFROMINSIDEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/houses/HouseSellRequestMessage.h"

class HouseSellFromInsideRequestMessage : public HouseSellRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseSellFromInsideRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseSellFromInsideRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseSellFromInsideRequestMessage(FuncTree tree);
  HouseSellFromInsideRequestMessage();
};

#endif // HOUSESELLFROMINSIDEREQUESTMESSAGE_H