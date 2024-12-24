#ifndef SEQUENCENUMBERMESSAGE_H
#define SEQUENCENUMBERMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SequenceNumberMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SequenceNumberMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SequenceNumberMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SequenceNumberMessage(FuncTree tree);
  SequenceNumberMessage();

  uint number;

private:
  void _numberFunc(Reader *input);
};

#endif // SEQUENCENUMBERMESSAGE_H