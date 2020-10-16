#ifndef ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE_H
#define ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AnomalySubareaInformationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AnomalySubareaInformationRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AnomalySubareaInformationRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AnomalySubareaInformationRequestMessage(FuncTree tree);
  AnomalySubareaInformationRequestMessage();
};

#endif // ANOMALYSUBAREAINFORMATIONREQUESTMESSAGE_H