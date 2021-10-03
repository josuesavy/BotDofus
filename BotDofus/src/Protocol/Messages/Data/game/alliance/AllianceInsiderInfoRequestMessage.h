#ifndef ALLIANCEINSIDERINFOREQUESTMESSAGE_H
#define ALLIANCEINSIDERINFOREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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