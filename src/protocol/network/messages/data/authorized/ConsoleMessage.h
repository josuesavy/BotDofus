#ifndef CONSOLEMESSAGE_H
#define CONSOLEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ConsoleMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ConsoleMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ConsoleMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ConsoleMessage(FuncTree tree);
  ConsoleMessage();

  uint type;
  QString content;

private:
  void _typeFunc(Reader *input);
  void _contentFunc(Reader *input);
};

#endif // CONSOLEMESSAGE_H