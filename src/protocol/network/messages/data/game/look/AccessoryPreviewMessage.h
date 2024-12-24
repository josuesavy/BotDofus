#ifndef ACCESSORYPREVIEWMESSAGE_H
#define ACCESSORYPREVIEWMESSAGE_H

#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AccessoryPreviewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AccessoryPreviewMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AccessoryPreviewMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AccessoryPreviewMessage(FuncTree tree);
  AccessoryPreviewMessage();

  QSharedPointer<EntityLook> look;

private:
  void _looktreeFunc(Reader *input);

  FuncTree _looktree;
};

#endif // ACCESSORYPREVIEWMESSAGE_H