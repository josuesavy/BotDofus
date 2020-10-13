#ifndef INTERACTIVEUSEWITHPARAMREQUESTMESSAGE_H
#define INTERACTIVEUSEWITHPARAMREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/interactive/InteractiveUseRequestMessage.h"

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