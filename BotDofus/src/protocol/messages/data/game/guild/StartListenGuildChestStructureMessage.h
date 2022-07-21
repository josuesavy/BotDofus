#ifndef STARTLISTENGUILDCHESTSTRUCTUREMESSAGE_H
#define STARTLISTENGUILDCHESTSTRUCTUREMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartListenGuildChestStructureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartListenGuildChestStructureMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartListenGuildChestStructureMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartListenGuildChestStructureMessage(FuncTree tree);
  StartListenGuildChestStructureMessage();
};

#endif // STARTLISTENGUILDCHESTSTRUCTUREMESSAGE_H