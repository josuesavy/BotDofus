#ifndef TITLESELECTEDMESSAGE_H
#define TITLESELECTEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TitleSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TitleSelectedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TitleSelectedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TitleSelectedMessage(FuncTree tree);
  TitleSelectedMessage();

  uint titleId;

private:
  void _titleIdFunc(Reader *input);
};

#endif // TITLESELECTEDMESSAGE_H