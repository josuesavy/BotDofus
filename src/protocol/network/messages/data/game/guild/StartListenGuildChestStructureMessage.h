#ifndef STARTLISTENGUILDCHESTSTRUCTUREMESSAGE_H
#define STARTLISTENGUILDCHESTSTRUCTUREMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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