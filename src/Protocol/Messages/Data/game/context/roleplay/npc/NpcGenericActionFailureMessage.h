#ifndef NPCGENERICACTIONFAILUREMESSAGE_H
#define NPCGENERICACTIONFAILUREMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class NpcGenericActionFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_NpcGenericActionFailureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_NpcGenericActionFailureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_NpcGenericActionFailureMessage(FuncTree tree);
  NpcGenericActionFailureMessage();
};

#endif // NPCGENERICACTIONFAILUREMESSAGE_H