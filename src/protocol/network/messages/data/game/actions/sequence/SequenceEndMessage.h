#ifndef SEQUENCEENDMESSAGE_H
#define SEQUENCEENDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SequenceEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SequenceEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SequenceEndMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SequenceEndMessage(FuncTree tree);
  SequenceEndMessage();

  uint actionId;
  double authorId;
  int sequenceType;

private:
  void _actionIdFunc(Reader *input);
  void _authorIdFunc(Reader *input);
  void _sequenceTypeFunc(Reader *input);
};

#endif // SEQUENCEENDMESSAGE_H