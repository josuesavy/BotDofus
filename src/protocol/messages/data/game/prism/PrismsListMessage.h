#ifndef PRISMSLISTMESSAGE_H
#define PRISMSLISTMESSAGE_H

#include "src/protocol/types/data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismsListMessage(FuncTree tree);
  PrismsListMessage();

  QList<QSharedPointer<PrismSubareaEmptyInfo>> prisms;

private:
  void _prismstreeFunc(Reader *input);
  void _prismsFunc(Reader *input);

  FuncTree _prismstree;
};

#endif // PRISMSLISTMESSAGE_H