#ifndef RELOGINTOKENREQUESTMESSAGE_H
#define RELOGINTOKENREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ReloginTokenRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ReloginTokenRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ReloginTokenRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ReloginTokenRequestMessage(FuncTree tree);
  ReloginTokenRequestMessage();
};

#endif // RELOGINTOKENREQUESTMESSAGE_H