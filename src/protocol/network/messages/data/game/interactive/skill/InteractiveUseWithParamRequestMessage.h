#ifndef INTERACTIVEUSEWITHPARAMREQUESTMESSAGE_H
#define INTERACTIVEUSEWITHPARAMREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/interactive/InteractiveUseRequestMessage.h"

class InteractiveUseWithParamRequestMessage : public InteractiveUseRequestMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveUseWithParamRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveUseWithParamRequestMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveUseWithParamRequestMessage(FuncTree tree);
  InteractiveUseWithParamRequestMessage();

  int id;

private:
  void _idFunc(Reader *input);
};

#endif // INTERACTIVEUSEWITHPARAMREQUESTMESSAGE_H