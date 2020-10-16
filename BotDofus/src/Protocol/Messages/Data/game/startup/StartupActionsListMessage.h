#ifndef STARTUPACTIONSLISTMESSAGE_H
#define STARTUPACTIONSLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/startup/StartupActionAddObject.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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