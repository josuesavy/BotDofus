#ifndef ACCESSORYPREVIEWMESSAGE_H
#define ACCESSORYPREVIEWMESSAGE_H

#include "src/Protocol/Types/Data/game/look/EntityLook.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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