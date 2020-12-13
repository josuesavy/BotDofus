#ifndef PRISMFIGHTADDEDMESSAGE_H
#define PRISMFIGHTADDEDMESSAGE_H

#include "src/protocol/types/data/game/prism/PrismFightersInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismFightAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightAddedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightAddedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightAddedMessage(FuncTree tree);
  PrismFightAddedMessage();

  QSharedPointer<PrismFightersInformation> fight;

private:
  void _fighttreeFunc(Reader *input);

  FuncTree _fighttree;
};

#endif // PRISMFIGHTADDEDMESSAGE_H