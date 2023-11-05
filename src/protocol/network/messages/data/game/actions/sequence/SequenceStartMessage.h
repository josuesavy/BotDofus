#ifndef SEQUENCESTARTMESSAGE_H
#define SEQUENCESTARTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class SequenceStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SequenceStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SequenceStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SequenceStartMessage(FuncTree tree);
  SequenceStartMessage();

  int sequenceType;
  double authorId;

private:
  void _sequenceTypeFunc(Reader *input);
  void _authorIdFunc(Reader *input);
};

#endif // SEQUENCESTARTMESSAGE_H