#ifndef STARTUPACTIONADDMESSAGE_H
#define STARTUPACTIONADDMESSAGE_H

#include "src/Protocol/Types/Data/game/startup/StartupActionAddObject.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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