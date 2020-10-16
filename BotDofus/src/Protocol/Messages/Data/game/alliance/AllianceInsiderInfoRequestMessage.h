#ifndef ALLIANCEINSIDERINFOREQUESTMESSAGE_H
#define ALLIANCEINSIDERINFOREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceInsiderInfoRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInsiderInfoRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInsiderInfoRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInsiderInfoRequestMessage(FuncTree tree);
  AllianceInsiderInfoRequestMessage();
};

#endif // ALLIANCEINSIDERINFOREQUESTMESSAGE_H