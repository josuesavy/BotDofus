#ifndef ALLIANCEISTHEREANYAPPLICATIONMESSAGE_H
#define ALLIANCEISTHEREANYAPPLICATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceIsThereAnyApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceIsThereAnyApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceIsThereAnyApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceIsThereAnyApplicationMessage(FuncTree tree);
  AllianceIsThereAnyApplicationMessage();
};

#endif // ALLIANCEISTHEREANYAPPLICATIONMESSAGE_H