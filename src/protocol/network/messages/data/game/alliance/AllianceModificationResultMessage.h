#ifndef ALLIANCEMODIFICATIONRESULTMESSAGE_H
#define ALLIANCEMODIFICATIONRESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceModificationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceModificationResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceModificationResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceModificationResultMessage(FuncTree tree);
  AllianceModificationResultMessage();

  uint result;

private:
  void _resultFunc(Reader *input);
};

#endif // ALLIANCEMODIFICATIONRESULTMESSAGE_H