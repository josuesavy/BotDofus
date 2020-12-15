#ifndef BASICWHOISREQUESTMESSAGE_H
#define BASICWHOISREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BasicWhoIsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicWhoIsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicWhoIsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicWhoIsRequestMessage(FuncTree tree);
  BasicWhoIsRequestMessage();

  bool verbose;
  QString search;

private:
  void _verboseFunc(Reader *input);
  void _searchFunc(Reader *input);
};

#endif // BASICWHOISREQUESTMESSAGE_H