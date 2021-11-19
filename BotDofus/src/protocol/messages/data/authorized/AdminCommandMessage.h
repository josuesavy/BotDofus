#ifndef ADMINCOMMANDMESSAGE_H
#define ADMINCOMMANDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  QString content;

private:
  void _contentFunc(Reader *input);
};

#endif // ADMINCOMMANDMESSAGE_H