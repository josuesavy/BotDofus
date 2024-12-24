#ifndef NPCDIALOGCREATIONMESSAGE_H
#define NPCDIALOGCREATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class NpcDialogCreationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NpcDialogCreationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NpcDialogCreationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NpcDialogCreationMessage(FuncTree tree);
  NpcDialogCreationMessage();

  double mapId;
  int npcId;

private:
  void _mapIdFunc(Reader *input);
  void _npcIdFunc(Reader *input);
};

#endif // NPCDIALOGCREATIONMESSAGE_H