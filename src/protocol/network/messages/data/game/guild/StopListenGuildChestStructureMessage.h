#ifndef STOPLISTENGUILDCHESTSTRUCTUREMESSAGE_H
#define STOPLISTENGUILDCHESTSTRUCTUREMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class StopListenGuildChestStructureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StopListenGuildChestStructureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StopListenGuildChestStructureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StopListenGuildChestStructureMessage(FuncTree tree);
  StopListenGuildChestStructureMessage();
};

#endif // STOPLISTENGUILDCHESTSTRUCTUREMESSAGE_H