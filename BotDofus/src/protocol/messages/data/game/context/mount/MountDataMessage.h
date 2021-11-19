#ifndef MOUNTDATAMESSAGE_H
#define MOUNTDATAMESSAGE_H

#include "src/protocol/types/data/game/mount/MountClientData.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountDataMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountDataMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountDataMessage(FuncTree tree);
  MountDataMessage();

  QSharedPointer<MountClientData> mountData;

private:
  void _mountDatatreeFunc(Reader *input);

  FuncTree _mountDatatree;
};

#endif // MOUNTDATAMESSAGE_H