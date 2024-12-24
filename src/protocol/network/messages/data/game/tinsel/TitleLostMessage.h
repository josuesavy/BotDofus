#ifndef TITLELOSTMESSAGE_H
#define TITLELOSTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TitleLostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitleLostMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitleLostMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitleLostMessage(FuncTree tree);
  TitleLostMessage();

  uint titleId;

private:
  void _titleIdFunc(Reader *input);
};

#endif // TITLELOSTMESSAGE_H