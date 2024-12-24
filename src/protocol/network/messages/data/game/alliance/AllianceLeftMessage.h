#ifndef ALLIANCELEFTMESSAGE_H
#define ALLIANCELEFTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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