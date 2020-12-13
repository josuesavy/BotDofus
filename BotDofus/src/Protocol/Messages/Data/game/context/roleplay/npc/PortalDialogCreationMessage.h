#ifndef PORTALDIALOGCREATIONMESSAGE_H
#define PORTALDIALOGCREATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/npc/NpcDialogCreationMessage.h"

class PortalDialogCreationMessage : public NpcDialogCreationMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PortalDialogCreationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PortalDialogCreationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PortalDialogCreationMessage(FuncTree tree);
  PortalDialogCreationMessage();

  uint type;

private:
  void _typeFunc(Reader *input);
};

#endif // PORTALDIALOGCREATIONMESSAGE_H