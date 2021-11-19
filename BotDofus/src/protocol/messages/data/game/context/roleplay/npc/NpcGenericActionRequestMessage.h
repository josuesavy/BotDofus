#ifndef NPCGENERICACTIONREQUESTMESSAGE_H
#define NPCGENERICACTIONREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class NpcGenericActionRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NpcGenericActionRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NpcGenericActionRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NpcGenericActionRequestMessage(FuncTree tree);
  NpcGenericActionRequestMessage();

  int npcId;
  uint npcActionId;
  double npcMapId;

private:
  void _npcIdFunc(Reader *input);
  void _npcActionIdFunc(Reader *input);
  void _npcMapIdFunc(Reader *input);
};

#endif // NPCGENERICACTIONREQUESTMESSAGE_H