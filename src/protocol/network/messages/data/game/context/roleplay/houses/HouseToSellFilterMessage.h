#ifndef HOUSETOSELLFILTERMESSAGE_H
#define HOUSETOSELLFILTERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HouseToSellFilterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseToSellFilterMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseToSellFilterMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseToSellFilterMessage(FuncTree tree);
  HouseToSellFilterMessage();

  int areaId;
  uint atLeastNbRoom;
  uint atLeastNbChest;
  uint skillRequested;
  double maxPrice;
  uint orderBy;

private:
  void _areaIdFunc(Reader *input);
  void _atLeastNbRoomFunc(Reader *input);
  void _atLeastNbChestFunc(Reader *input);
  void _skillRequestedFunc(Reader *input);
  void _maxPriceFunc(Reader *input);
  void _orderByFunc(Reader *input);
};

#endif // HOUSETOSELLFILTERMESSAGE_H