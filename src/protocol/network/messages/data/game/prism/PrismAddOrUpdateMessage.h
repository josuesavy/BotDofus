#ifndef PRISMADDORUPDATEMESSAGE_H
#define PRISMADDORUPDATEMESSAGE_H

#include "src/protocol/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismAddOrUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismAddOrUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismAddOrUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismAddOrUpdateMessage(FuncTree tree);
  PrismAddOrUpdateMessage();

  QSharedPointer<PrismGeolocalizedInformation> prism;

private:
  void _prismtreeFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // PRISMADDORUPDATEMESSAGE_H