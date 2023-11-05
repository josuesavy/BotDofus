#ifndef ALLIANCEGETPLAYERAPPLICATIONMESSAGE_H
#define ALLIANCEGETPLAYERAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceGetPlayerApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceGetPlayerApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceGetPlayerApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceGetPlayerApplicationMessage(FuncTree tree);
  AllianceGetPlayerApplicationMessage();
};

#endif // ALLIANCEGETPLAYERAPPLICATIONMESSAGE_H