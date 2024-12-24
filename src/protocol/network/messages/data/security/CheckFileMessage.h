#ifndef CHECKFILEMESSAGE_H
#define CHECKFILEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CheckFileMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CheckFileMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CheckFileMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CheckFileMessage(FuncTree tree);
  CheckFileMessage();

  QString filenameHash;
  uint type;
  QString value;

private:
  void _filenameHashFunc(Reader *input);
  void _typeFunc(Reader *input);
  void _valueFunc(Reader *input);
};

#endif // CHECKFILEMESSAGE_H