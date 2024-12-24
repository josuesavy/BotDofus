#ifndef ADMINCOMMANDMESSAGE_H
#define ADMINCOMMANDMESSAGE_H

#include "src/protocol/network/types/data/game/Uuid.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AdminCommandMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AdminCommandMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AdminCommandMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AdminCommandMessage(FuncTree tree);
  AdminCommandMessage();

  Uuid messageUuid;
  QString content;

private:
  void _messageUuidtreeFunc(Reader *input);
  void _contentFunc(Reader *input);

  FuncTree _messageUuidtree;
};

#endif // ADMINCOMMANDMESSAGE_H