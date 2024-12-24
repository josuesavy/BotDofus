#ifndef BASICSTATMESSAGE_H
#define BASICSTATMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BasicStatMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicStatMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicStatMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicStatMessage(FuncTree tree);
  BasicStatMessage();

  double timeSpent;
  uint statId;

private:
  void _timeSpentFunc(Reader *input);
  void _statIdFunc(Reader *input);
};

#endif // BASICSTATMESSAGE_H