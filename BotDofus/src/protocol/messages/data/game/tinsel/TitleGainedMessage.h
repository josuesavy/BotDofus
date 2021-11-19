#ifndef TITLEGAINEDMESSAGE_H
#define TITLEGAINEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TitleGainedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitleGainedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitleGainedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitleGainedMessage(FuncTree tree);
  TitleGainedMessage();

  uint titleId;

private:
  void _titleIdFunc(Reader *input);
};

#endif // TITLEGAINEDMESSAGE_H