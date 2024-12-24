#ifndef PADDOCKTOSELLLISTMESSAGE_H
#define PADDOCKTOSELLLISTMESSAGE_H

#include "src/protocol/network/types/data/game/paddock/PaddockInformationsForSell.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PaddockToSellListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockToSellListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockToSellListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockToSellListMessage(FuncTree tree);
  PaddockToSellListMessage();

  uint pageIndex;
  uint totalPage;
  QList<PaddockInformationsForSell> paddockList;

private:
  void _pageIndexFunc(Reader *input);
  void _totalPageFunc(Reader *input);
  void _paddockListtreeFunc(Reader *input);
  void _paddockListFunc(Reader *input);

  FuncTree _paddockListtree;
};

#endif // PADDOCKTOSELLLISTMESSAGE_H