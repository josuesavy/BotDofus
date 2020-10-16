#ifndef PRISMSLISTMESSAGE_H
#define PRISMSLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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