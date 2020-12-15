#ifndef QUESTLISTREQUESTMESSAGE_H
#define QUESTLISTREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class QuestListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_QuestListRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_QuestListRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_QuestListRequestMessage(FuncTree tree);
  QuestListRequestMessage();
};

#endif // QUESTLISTREQUESTMESSAGE_H