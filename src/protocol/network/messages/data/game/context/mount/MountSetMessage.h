#ifndef MOUNTSETMESSAGE_H
#define MOUNTSETMESSAGE_H

#include "src/protocol/network/types/data/game/mount/MountClientData.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MountSetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountSetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountSetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountSetMessage(FuncTree tree);
  MountSetMessage();

  QSharedPointer<MountClientData> mountData;

private:
  void _mountDatatreeFunc(Reader *input);

  FuncTree _mountDatatree;
};

#endif // MOUNTSETMESSAGE_H