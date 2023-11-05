#ifndef ALLIANCESUBMITAPPLICATIONMESSAGE_H
#define ALLIANCESUBMITAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceSubmitApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceSubmitApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceSubmitApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceSubmitApplicationMessage(FuncTree tree);
  AllianceSubmitApplicationMessage();

  QString applyText;
  uint allianceId;

private:
  void _applyTextFunc(Reader *input);
  void _allianceIdFunc(Reader *input);
};

#endif // ALLIANCESUBMITAPPLICATIONMESSAGE_H