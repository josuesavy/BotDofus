#ifndef PRISMATTACKEDMESSAGE_H
#define PRISMATTACKEDMESSAGE_H

#include "src/protocol/network/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PrismAttackedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismAttackedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismAttackedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismAttackedMessage(FuncTree tree);
  PrismAttackedMessage();

  QSharedPointer<PrismGeolocalizedInformation> prism;

private:
  void _prismtreeFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // PRISMATTACKEDMESSAGE_H