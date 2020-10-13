#ifndef BASICWHOAMIREQUESTMESSAGE_H
#define BASICWHOAMIREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicWhoAmIRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicWhoAmIRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicWhoAmIRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicWhoAmIRequestMessage(FuncTree tree);
  BasicWhoAmIRequestMessage();

  bool verbose;

private:
  void _verboseFunc(Reader *input);
};

#endif // BASICWHOAMIREQUESTMESSAGE_H