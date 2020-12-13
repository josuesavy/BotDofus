#ifndef EXCHANGEMOUNTSSTABLEADDMESSAGE_H
#define EXCHANGEMOUNTSSTABLEADDMESSAGE_H

#include "src/protocol/types/data/game/mount/MountClientData.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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