#ifndef PRISMSLISTMESSAGE_H
#define PRISMSLISTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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

  QList<QSharedPointer<PrismGeolocalizedInformation>> prisms;

private:
  void _prismstreeFunc(Reader *input);
  void _prismsFunc(Reader *input);

  FuncTree _prismstree;
};

#endif // PRISMSLISTMESSAGE_H