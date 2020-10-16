#ifndef IDENTIFICATIONFAILEDMESSAGE_H
#define IDENTIFICATIONFAILEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class IdentificationFailedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IdentificationFailedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IdentificationFailedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IdentificationFailedMessage(FuncTree tree);
  IdentificationFailedMessage();

  uint reason;

private:
  void _reasonFunc(Reader *input);
};

#endif // IDENTIFICATIONFAILEDMESSAGE_H