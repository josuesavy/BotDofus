#ifndef COMPASSRESETMESSAGE_H
#define COMPASSRESETMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CompassResetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CompassResetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CompassResetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CompassResetMessage(FuncTree tree);
  CompassResetMessage();

  uint type;

private:
  void _typeFunc(Reader *input);
};

#endif // COMPASSRESETMESSAGE_H