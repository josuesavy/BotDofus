#ifndef ALLIANCEMODIFICATIONSTARTEDMESSAGE_H
#define ALLIANCEMODIFICATIONSTARTEDMESSAGE_H

#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceModificationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceModificationStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceModificationStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceModificationStartedMessage(FuncTree tree);
  AllianceModificationStartedMessage();

  bool canChangeName;
  bool canChangeTag;
  bool canChangeEmblem;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // ALLIANCEMODIFICATIONSTARTEDMESSAGE_H