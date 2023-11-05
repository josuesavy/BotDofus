#ifndef ALLIANCECREATIONRESULTMESSAGE_H
#define ALLIANCECREATIONRESULTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceCreationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceCreationResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceCreationResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceCreationResultMessage(FuncTree tree);
  AllianceCreationResultMessage();

  uint result;

private:
  void _resultFunc(Reader *input);
};

#endif // ALLIANCECREATIONRESULTMESSAGE_H