#ifndef ALLIANCEAPPLICATIONPRESENCEMESSAGE_H
#define ALLIANCEAPPLICATIONPRESENCEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceApplicationPresenceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceApplicationPresenceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceApplicationPresenceMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceApplicationPresenceMessage(FuncTree tree);
  AllianceApplicationPresenceMessage();

  bool isApplication;

private:
  void _isApplicationFunc(Reader *input);
};

#endif // ALLIANCEAPPLICATIONPRESENCEMESSAGE_H