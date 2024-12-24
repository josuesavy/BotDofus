#ifndef PADDOCKTOSELLLISTREQUESTMESSAGE_H
#define PADDOCKTOSELLLISTREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaddockToSellListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockToSellListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockToSellListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockToSellListRequestMessage(FuncTree tree);
  PaddockToSellListRequestMessage();

  uint pageIndex;

private:
  void _pageIndexFunc(Reader *input);
};

#endif // PADDOCKTOSELLLISTREQUESTMESSAGE_H