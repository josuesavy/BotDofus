#ifndef ALLIANCEFACTSERRORMESSAGE_H
#define ALLIANCEFACTSERRORMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceFactsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFactsErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFactsErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFactsErrorMessage(FuncTree tree);
  AllianceFactsErrorMessage();

  uint allianceId;

private:
  void _allianceIdFunc(Reader *input);
};

#endif // ALLIANCEFACTSERRORMESSAGE_H