#ifndef ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceModificationNameAndTagValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceModificationNameAndTagValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceModificationNameAndTagValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceModificationNameAndTagValidMessage(FuncTree tree);
  AllianceModificationNameAndTagValidMessage();

  QString allianceName;
  QString allianceTag;

private:
  void _allianceNameFunc(Reader *input);
  void _allianceTagFunc(Reader *input);
};

#endif // ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE_H