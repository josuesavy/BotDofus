#ifndef STARTUPACTIONSLISTMESSAGE_H
#define STARTUPACTIONSLISTMESSAGE_H

#include "src/protocol/types/data/game/startup/StartupActionAddObject.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartupActionsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionsListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionsListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionsListMessage(FuncTree tree);
  StartupActionsListMessage();

  QList<QSharedPointer<StartupActionAddObject>> actions;

private:
  void _actionstreeFunc(Reader *input);
  void _actionsFunc(Reader *input);

  FuncTree _actionstree;
};

#endif // STARTUPACTIONSLISTMESSAGE_H