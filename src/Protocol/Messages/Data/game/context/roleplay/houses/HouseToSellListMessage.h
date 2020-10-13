#ifndef HOUSETOSELLLISTMESSAGE_H
#define HOUSETOSELLLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/house/HouseInformationsForSell.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HouseToSellListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseToSellListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseToSellListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseToSellListMessage(FuncTree tree);
  HouseToSellListMessage();

  uint pageIndex;
  uint totalPage;
  QList<HouseInformationsForSell> houseList;

private:
  void _pageIndexFunc(Reader *input);
  void _totalPageFunc(Reader *input);
  void _houseListtreeFunc(Reader *input);
  void _houseListFunc(Reader *input);

  FuncTree _houseListtree;
};

#endif // HOUSETOSELLLISTMESSAGE_H