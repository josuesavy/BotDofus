#ifndef TITLEGAINEDMESSAGE_H
#define TITLEGAINEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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