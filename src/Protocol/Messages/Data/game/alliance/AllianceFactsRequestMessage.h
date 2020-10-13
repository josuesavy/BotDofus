#ifndef ALLIANCEFACTSREQUESTMESSAGE_H
#define ALLIANCEFACTSREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AllianceFactsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceFactsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceFactsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceFactsRequestMessage(FuncTree tree);
  AllianceFactsRequestMessage();

  uint allianceId;

private:
  void _allianceIdFunc(Reader *input);
};

#endif // ALLIANCEFACTSREQUESTMESSAGE_H