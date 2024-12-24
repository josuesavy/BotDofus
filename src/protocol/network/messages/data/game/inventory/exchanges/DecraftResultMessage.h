#ifndef DECRAFTRESULTMESSAGE_H
#define DECRAFTRESULTMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/job/DecraftedItemStackInfo.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DecraftResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DecraftResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DecraftResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DecraftResultMessage(FuncTree tree);
  DecraftResultMessage();

  QList<DecraftedItemStackInfo> results;

private:
  void _resultstreeFunc(Reader *input);
  void _resultsFunc(Reader *input);

  FuncTree _resultstree;
};

#endif // DECRAFTRESULTMESSAGE_H