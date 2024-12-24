#ifndef ORNAMENTGAINEDMESSAGE_H
#define ORNAMENTGAINEDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class OrnamentGainedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_OrnamentGainedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_OrnamentGainedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_OrnamentGainedMessage(FuncTree tree);
  OrnamentGainedMessage();

  uint ornamentId;

private:
  void _ornamentIdFunc(Reader *input);
};

#endif // ORNAMENTGAINEDMESSAGE_H