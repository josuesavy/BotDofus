#ifndef CONSOLECOMMANDSLISTMESSAGE_H
#define CONSOLECOMMANDSLISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ConsoleCommandsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ConsoleCommandsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ConsoleCommandsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ConsoleCommandsListMessage(FuncTree tree);
  ConsoleCommandsListMessage();

  QList<QString> aliases;
  QList<QString> args;
  QList<QString> descriptions;

private:
  void _aliasestreeFunc(Reader *input);
  void _aliasesFunc(Reader *input);
  void _argstreeFunc(Reader *input);
  void _argsFunc(Reader *input);
  void _descriptionstreeFunc(Reader *input);
  void _descriptionsFunc(Reader *input);

  FuncTree _aliasestree;
  FuncTree _argstree;
  FuncTree _descriptionstree;
};

#endif // CONSOLECOMMANDSLISTMESSAGE_H