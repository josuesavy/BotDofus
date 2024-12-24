#ifndef SEQUENCENUMBERREQUESTMESSAGE_H
#define SEQUENCENUMBERREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SequenceNumberRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SequenceNumberRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SequenceNumberRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SequenceNumberRequestMessage(FuncTree tree);
  SequenceNumberRequestMessage();
};

#endif // SEQUENCENUMBERREQUESTMESSAGE_H