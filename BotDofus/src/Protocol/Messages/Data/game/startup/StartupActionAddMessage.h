#ifndef STARTUPACTIONADDMESSAGE_H
#define STARTUPACTIONADDMESSAGE_H

#include "src/protocol/types/data/game/startup/StartupActionAddObject.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class StartupActionAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionAddMessage(FuncTree tree);
  StartupActionAddMessage();

  QSharedPointer<StartupActionAddObject> newAction;

private:
  void _newActiontreeFunc(Reader *input);

  FuncTree _newActiontree;
};

#endif // STARTUPACTIONADDMESSAGE_H