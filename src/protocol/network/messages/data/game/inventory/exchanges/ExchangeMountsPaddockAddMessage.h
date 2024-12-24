#ifndef EXCHANGEMOUNTSPADDOCKADDMESSAGE_H
#define EXCHANGEMOUNTSPADDOCKADDMESSAGE_H

#include "src/protocol/network/types/data/game/mount/MountClientData.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeMountsPaddockAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountsPaddockAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountsPaddockAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountsPaddockAddMessage(FuncTree tree);
  ExchangeMountsPaddockAddMessage();

  QList<QSharedPointer<MountClientData>> mountDescription;

private:
  void _mountDescriptiontreeFunc(Reader *input);
  void _mountDescriptionFunc(Reader *input);

  FuncTree _mountDescriptiontree;
};

#endif // EXCHANGEMOUNTSPADDOCKADDMESSAGE_H