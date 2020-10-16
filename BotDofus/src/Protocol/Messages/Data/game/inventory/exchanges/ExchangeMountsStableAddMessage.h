#ifndef EXCHANGEMOUNTSSTABLEADDMESSAGE_H
#define EXCHANGEMOUNTSSTABLEADDMESSAGE_H

#include "src/Protocol/Types/Data/game/mount/MountClientData.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ExchangeMountsStableAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeMountsStableAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeMountsStableAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeMountsStableAddMessage(FuncTree tree);
  ExchangeMountsStableAddMessage();

  QList<QSharedPointer<MountClientData>> mountDescription;

private:
  void _mountDescriptiontreeFunc(Reader *input);
  void _mountDescriptionFunc(Reader *input);

  FuncTree _mountDescriptiontree;
};

#endif // EXCHANGEMOUNTSSTABLEADDMESSAGE_H