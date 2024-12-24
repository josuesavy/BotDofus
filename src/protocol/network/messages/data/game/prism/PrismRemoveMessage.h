#ifndef PRISMREMOVEMESSAGE_H
#define PRISMREMOVEMESSAGE_H

#include "src/protocol/network/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class PrismRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismRemoveMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismRemoveMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismRemoveMessage(FuncTree tree);
  PrismRemoveMessage();

  QSharedPointer<PrismGeolocalizedInformation> prism;

private:
  void _prismtreeFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // PRISMREMOVEMESSAGE_H