#ifndef HOUSESELLFROMINSIDEREQUESTMESSAGE_H
#define HOUSESELLFROMINSIDEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/context/roleplay/houses/HouseSellRequestMessage.h"

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