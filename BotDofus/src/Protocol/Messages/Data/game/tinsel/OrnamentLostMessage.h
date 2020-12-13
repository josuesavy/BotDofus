#ifndef ORNAMENTLOSTMESSAGE_H
#define ORNAMENTLOSTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class OrnamentLostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OrnamentLostMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OrnamentLostMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OrnamentLostMessage(FuncTree tree);
  OrnamentLostMessage();

  uint ornamentId;

private:
  void _ornamentIdFunc(Reader *input);
};

#endif // ORNAMENTLOSTMESSAGE_H