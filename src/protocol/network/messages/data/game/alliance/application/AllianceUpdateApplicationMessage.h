#ifndef ALLIANCEUPDATEAPPLICATIONMESSAGE_H
#define ALLIANCEUPDATEAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceUpdateApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceUpdateApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceUpdateApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceUpdateApplicationMessage(FuncTree tree);
  AllianceUpdateApplicationMessage();

  QString applyText;
  uint allianceId;

private:
  void _applyTextFunc(Reader *input);
  void _allianceIdFunc(Reader *input);
};

#endif // ALLIANCEUPDATEAPPLICATIONMESSAGE_H