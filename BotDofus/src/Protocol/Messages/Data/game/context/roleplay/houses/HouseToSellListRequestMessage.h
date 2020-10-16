#ifndef HOUSETOSELLLISTREQUESTMESSAGE_H
#define HOUSETOSELLLISTREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HouseToSellListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseToSellListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseToSellListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseToSellListRequestMessage(FuncTree tree);
  HouseToSellListRequestMessage();

  uint pageIndex;

private:
  void _pageIndexFunc(Reader *input);
};

#endif // HOUSETOSELLLISTREQUESTMESSAGE_H