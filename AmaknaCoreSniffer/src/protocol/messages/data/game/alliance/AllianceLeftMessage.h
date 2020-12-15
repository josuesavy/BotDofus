#ifndef ALLIANCELEFTMESSAGE_H
#define ALLIANCELEFTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceLeftMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceLeftMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceLeftMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceLeftMessage(FuncTree tree);
  AllianceLeftMessage();
};

#endif // ALLIANCELEFTMESSAGE_H