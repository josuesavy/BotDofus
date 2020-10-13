#ifndef STARTUPACTIONFINISHEDMESSAGE_H
#define STARTUPACTIONFINISHEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class StartupActionFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StartupActionFinishedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StartupActionFinishedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StartupActionFinishedMessage(FuncTree tree);
  StartupActionFinishedMessage();

  bool success;
  uint actionId;
  bool automaticAction;

private:
  void deserializeByteBoxes(Reader *input);
  void _actionIdFunc(Reader *input);
};

#endif // STARTUPACTIONFINISHEDMESSAGE_H