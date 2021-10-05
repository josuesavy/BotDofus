#ifndef BREACHTELEPORTRESPONSEMESSAGE_H
#define BREACHTELEPORTRESPONSEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class BreachTeleportResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachTeleportResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachTeleportResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachTeleportResponseMessage(FuncTree tree);
  BreachTeleportResponseMessage();

  bool teleported;

private:
  void _teleportedFunc(Reader *input);
};

#endif // BREACHTELEPORTRESPONSEMESSAGE_H