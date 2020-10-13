#ifndef ORNAMENTGAINEDMESSAGE_H
#define ORNAMENTGAINEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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