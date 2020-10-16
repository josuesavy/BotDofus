#ifndef IDOLPARTYLOSTMESSAGE_H
#define IDOLPARTYLOSTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IdolPartyLostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdolPartyLostMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdolPartyLostMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdolPartyLostMessage(FuncTree tree);
  IdolPartyLostMessage();

  uint idolId;

private:
  void _idolIdFunc(Reader *input);
};

#endif // IDOLPARTYLOSTMESSAGE_H