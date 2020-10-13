#ifndef EXCHANGEMOUNTSPADDOCKADDMESSAGE_H
#define EXCHANGEMOUNTSPADDOCKADDMESSAGE_H

#include "src/Protocol/Types/Data/game/mount/MountClientData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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