#ifndef PRISMATTACKRESULTMESSAGE_H
#define PRISMATTACKRESULTMESSAGE_H

#include "src/protocol/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismAttackResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismAttackResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismAttackResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismAttackResultMessage(FuncTree tree);
  PrismAttackResultMessage();

  QSharedPointer<PrismGeolocalizedInformation> prism;
  uint result;

private:
  void _prismtreeFunc(Reader *input);
  void _resultFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // PRISMATTACKRESULTMESSAGE_H