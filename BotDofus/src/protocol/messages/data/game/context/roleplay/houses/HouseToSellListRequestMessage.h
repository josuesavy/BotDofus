#ifndef HOUSETOSELLLISTREQUESTMESSAGE_H
#define HOUSETOSELLLISTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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